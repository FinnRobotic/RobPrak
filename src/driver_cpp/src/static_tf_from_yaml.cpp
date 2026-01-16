#include <rclcpp/rclcpp.hpp>
#include <tf2_ros/static_transform_broadcaster.h>
#include <geometry_msgs/msg/transform_stamped.hpp>

#include <yaml-cpp/yaml.h>
#include <tf2/LinearMath/Quaternion.h>

#include <memory>
#include <vector>
#include <string>

class StaticTFfromYAML : public rclcpp::Node
{
public:
  StaticTFfromYAML() : Node("static_tf_from_yaml")
  {
    this->declare_parameter<std::string>("yaml_file", "");
    std::string yaml_file = this->get_parameter("yaml_file").as_string();

    if (yaml_file.empty()) {
      RCLCPP_FATAL(this->get_logger(), "No yaml_file parameter provided!");
      rclcpp::shutdown();
      return;
    }

    broadcaster_ =
      std::make_shared<tf2_ros::StaticTransformBroadcaster>(this);

    load_and_publish(yaml_file);
  }

private:
  void load_and_publish(const std::string & yaml_file)
  {
    YAML::Node config = YAML::LoadFile(yaml_file);
    std::vector<geometry_msgs::msg::TransformStamped> transforms;

    for (const auto & frame : config["frames"]) {
      geometry_msgs::msg::TransformStamped t;

      t.header.stamp = this->get_clock()->now();
      t.header.frame_id = frame["parent"].as<std::string>();
      t.child_frame_id = frame["child"].as<std::string>();

      // Translation
      t.transform.translation.x = frame["translation"][0].as<double>();
      t.transform.translation.y = frame["translation"][1].as<double>();
      t.transform.translation.z = frame["translation"][2].as<double>();

      // Rotation (RPY deg → rad → quaternion)
      double roll  = frame["rpy_deg"][0].as<double>() * M_PI / 180.0;
      double pitch = frame["rpy_deg"][1].as<double>() * M_PI / 180.0;
      double yaw   = frame["rpy_deg"][2].as<double>() * M_PI / 180.0;

      tf2::Quaternion q;
      q.setRPY(roll, pitch, yaw);
      q.normalize();

      t.transform.rotation.x = q.x();
      t.transform.rotation.y = q.y();
      t.transform.rotation.z = q.z();
      t.transform.rotation.w = q.w();

      transforms.push_back(t);

      RCLCPP_INFO(
        this->get_logger(),
        "Loaded static TF: %s -> %s",
        t.header.frame_id.c_str(),
        t.child_frame_id.c_str()
      );
    }

    broadcaster_->sendTransform(transforms);
    RCLCPP_INFO(this->get_logger(), "All static transforms published.");
  }

  std::shared_ptr<tf2_ros::StaticTransformBroadcaster> broadcaster_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<StaticTFfromYAML>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
