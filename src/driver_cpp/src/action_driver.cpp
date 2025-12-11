#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>

#include <prak_msgs/action/actuator_command.hpp>
#include <prak_msgs/msg/actuator_request.hpp>
#include <prak_msgs/msg/joint_state.hpp>


using ActuatorCommand = prak_msgs::action::ActuatorCommand;
using GoalHandleActuatorCommand = rclcpp_action::ServerGoalHandle<ActuatorCommand>;

class ActuatorActionServer : public rclcpp::Node
{
public:
  ActuatorActionServer()
    : Node("actuator_action_server")
  {
    using namespace std::placeholders;

    action_server_ = rclcpp_action::create_server<ActuatorCommand>(
        this,
        "actuator_command",
        std::bind(&ActuatorActionServer::handle_goal, this, _1, _2),
        std::bind(&ActuatorActionServer::handle_cancel, this, _1),
        std::bind(&ActuatorActionServer::handle_accepted, this, _1));

  }

private:
  rclcpp_action::Server<ActuatorCommand>::SharedPtr action_server_;

  rclcpp_action::GoalResponse handle_goal(
      const rclcpp_action::GoalUUID &,
      std::shared_ptr<const ActuatorCommand::Goal> goal)
  {
    RCLCPP_INFO(get_logger(),
                "Neues Action-Goal empfangen (use_angles=%s)",
                goal->request.use_angles ? "true" : "false");
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
  }

  rclcpp_action::CancelResponse handle_cancel(
      const std::shared_ptr<GoalHandleActuatorCommand> /*goal_handle*/)
  {
    RCLCPP_INFO(get_logger(), "Goal-Cancel angefragt.");
    return rclcpp_action::CancelResponse::ACCEPT;
  }

  void handle_accepted(const std::shared_ptr<GoalHandleActuatorCommand> goal_handle)
  {
    std::thread{std::bind(&ActuatorActionServer::execute, this, goal_handle)}.detach();
  }

  void execute(const std::shared_ptr<GoalHandleActuatorCommand> goal_handle)
  {
    const auto goal = goal_handle->get_goal();
    auto feedback = std::make_shared<ActuatorCommand::Feedback>();
    auto result   = std::make_shared<ActuatorCommand::Result>();

    bool ok = false;

    if (goal->request.use_angles)
    {
    }
    else
    {
    }

    feedback->progress = ok ? 1.0f : 0.0f;
    goal_handle->publish_feedback(feedback);

    if (!ok)
    {
      result->success = false;
      result->message = "MoveIt-Planung/Ausführung fehlgeschlagen.";
      goal_handle->abort(result);
      return;
    }

    result->success = true;
    result->message = "Ziel erfolgreich ausgeführt.";
    goal_handle->succeed(result);
  }
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<ActuatorActionServer>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
