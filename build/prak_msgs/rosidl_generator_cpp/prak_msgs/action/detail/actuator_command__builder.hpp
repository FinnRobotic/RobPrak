// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from prak_msgs:action/ActuatorCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "prak_msgs/action/actuator_command.hpp"


#ifndef PRAK_MSGS__ACTION__DETAIL__ACTUATOR_COMMAND__BUILDER_HPP_
#define PRAK_MSGS__ACTION__DETAIL__ACTUATOR_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "prak_msgs/action/detail/actuator_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace prak_msgs
{

namespace action
{

namespace builder
{

class Init_ActuatorCommand_Goal_request
{
public:
  Init_ActuatorCommand_Goal_request()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::prak_msgs::action::ActuatorCommand_Goal request(::prak_msgs::action::ActuatorCommand_Goal::_request_type arg)
  {
    msg_.request = std::move(arg);
    return std::move(msg_);
  }

private:
  ::prak_msgs::action::ActuatorCommand_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::prak_msgs::action::ActuatorCommand_Goal>()
{
  return prak_msgs::action::builder::Init_ActuatorCommand_Goal_request();
}

}  // namespace prak_msgs


namespace prak_msgs
{

namespace action
{

namespace builder
{

class Init_ActuatorCommand_Result_message
{
public:
  explicit Init_ActuatorCommand_Result_message(::prak_msgs::action::ActuatorCommand_Result & msg)
  : msg_(msg)
  {}
  ::prak_msgs::action::ActuatorCommand_Result message(::prak_msgs::action::ActuatorCommand_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::prak_msgs::action::ActuatorCommand_Result msg_;
};

class Init_ActuatorCommand_Result_success
{
public:
  Init_ActuatorCommand_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ActuatorCommand_Result_message success(::prak_msgs::action::ActuatorCommand_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ActuatorCommand_Result_message(msg_);
  }

private:
  ::prak_msgs::action::ActuatorCommand_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::prak_msgs::action::ActuatorCommand_Result>()
{
  return prak_msgs::action::builder::Init_ActuatorCommand_Result_success();
}

}  // namespace prak_msgs


namespace prak_msgs
{

namespace action
{

namespace builder
{

class Init_ActuatorCommand_Feedback_progress
{
public:
  Init_ActuatorCommand_Feedback_progress()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::prak_msgs::action::ActuatorCommand_Feedback progress(::prak_msgs::action::ActuatorCommand_Feedback::_progress_type arg)
  {
    msg_.progress = std::move(arg);
    return std::move(msg_);
  }

private:
  ::prak_msgs::action::ActuatorCommand_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::prak_msgs::action::ActuatorCommand_Feedback>()
{
  return prak_msgs::action::builder::Init_ActuatorCommand_Feedback_progress();
}

}  // namespace prak_msgs


namespace prak_msgs
{

namespace action
{

namespace builder
{

class Init_ActuatorCommand_SendGoal_Request_goal
{
public:
  explicit Init_ActuatorCommand_SendGoal_Request_goal(::prak_msgs::action::ActuatorCommand_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::prak_msgs::action::ActuatorCommand_SendGoal_Request goal(::prak_msgs::action::ActuatorCommand_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::prak_msgs::action::ActuatorCommand_SendGoal_Request msg_;
};

class Init_ActuatorCommand_SendGoal_Request_goal_id
{
public:
  Init_ActuatorCommand_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ActuatorCommand_SendGoal_Request_goal goal_id(::prak_msgs::action::ActuatorCommand_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ActuatorCommand_SendGoal_Request_goal(msg_);
  }

private:
  ::prak_msgs::action::ActuatorCommand_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::prak_msgs::action::ActuatorCommand_SendGoal_Request>()
{
  return prak_msgs::action::builder::Init_ActuatorCommand_SendGoal_Request_goal_id();
}

}  // namespace prak_msgs


namespace prak_msgs
{

namespace action
{

namespace builder
{

class Init_ActuatorCommand_SendGoal_Response_stamp
{
public:
  explicit Init_ActuatorCommand_SendGoal_Response_stamp(::prak_msgs::action::ActuatorCommand_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::prak_msgs::action::ActuatorCommand_SendGoal_Response stamp(::prak_msgs::action::ActuatorCommand_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::prak_msgs::action::ActuatorCommand_SendGoal_Response msg_;
};

class Init_ActuatorCommand_SendGoal_Response_accepted
{
public:
  Init_ActuatorCommand_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ActuatorCommand_SendGoal_Response_stamp accepted(::prak_msgs::action::ActuatorCommand_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_ActuatorCommand_SendGoal_Response_stamp(msg_);
  }

private:
  ::prak_msgs::action::ActuatorCommand_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::prak_msgs::action::ActuatorCommand_SendGoal_Response>()
{
  return prak_msgs::action::builder::Init_ActuatorCommand_SendGoal_Response_accepted();
}

}  // namespace prak_msgs


namespace prak_msgs
{

namespace action
{

namespace builder
{

class Init_ActuatorCommand_SendGoal_Event_response
{
public:
  explicit Init_ActuatorCommand_SendGoal_Event_response(::prak_msgs::action::ActuatorCommand_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::prak_msgs::action::ActuatorCommand_SendGoal_Event response(::prak_msgs::action::ActuatorCommand_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::prak_msgs::action::ActuatorCommand_SendGoal_Event msg_;
};

class Init_ActuatorCommand_SendGoal_Event_request
{
public:
  explicit Init_ActuatorCommand_SendGoal_Event_request(::prak_msgs::action::ActuatorCommand_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_ActuatorCommand_SendGoal_Event_response request(::prak_msgs::action::ActuatorCommand_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ActuatorCommand_SendGoal_Event_response(msg_);
  }

private:
  ::prak_msgs::action::ActuatorCommand_SendGoal_Event msg_;
};

class Init_ActuatorCommand_SendGoal_Event_info
{
public:
  Init_ActuatorCommand_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ActuatorCommand_SendGoal_Event_request info(::prak_msgs::action::ActuatorCommand_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ActuatorCommand_SendGoal_Event_request(msg_);
  }

private:
  ::prak_msgs::action::ActuatorCommand_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::prak_msgs::action::ActuatorCommand_SendGoal_Event>()
{
  return prak_msgs::action::builder::Init_ActuatorCommand_SendGoal_Event_info();
}

}  // namespace prak_msgs


namespace prak_msgs
{

namespace action
{

namespace builder
{

class Init_ActuatorCommand_GetResult_Request_goal_id
{
public:
  Init_ActuatorCommand_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::prak_msgs::action::ActuatorCommand_GetResult_Request goal_id(::prak_msgs::action::ActuatorCommand_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::prak_msgs::action::ActuatorCommand_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::prak_msgs::action::ActuatorCommand_GetResult_Request>()
{
  return prak_msgs::action::builder::Init_ActuatorCommand_GetResult_Request_goal_id();
}

}  // namespace prak_msgs


namespace prak_msgs
{

namespace action
{

namespace builder
{

class Init_ActuatorCommand_GetResult_Response_result
{
public:
  explicit Init_ActuatorCommand_GetResult_Response_result(::prak_msgs::action::ActuatorCommand_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::prak_msgs::action::ActuatorCommand_GetResult_Response result(::prak_msgs::action::ActuatorCommand_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::prak_msgs::action::ActuatorCommand_GetResult_Response msg_;
};

class Init_ActuatorCommand_GetResult_Response_status
{
public:
  Init_ActuatorCommand_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ActuatorCommand_GetResult_Response_result status(::prak_msgs::action::ActuatorCommand_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_ActuatorCommand_GetResult_Response_result(msg_);
  }

private:
  ::prak_msgs::action::ActuatorCommand_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::prak_msgs::action::ActuatorCommand_GetResult_Response>()
{
  return prak_msgs::action::builder::Init_ActuatorCommand_GetResult_Response_status();
}

}  // namespace prak_msgs


namespace prak_msgs
{

namespace action
{

namespace builder
{

class Init_ActuatorCommand_GetResult_Event_response
{
public:
  explicit Init_ActuatorCommand_GetResult_Event_response(::prak_msgs::action::ActuatorCommand_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::prak_msgs::action::ActuatorCommand_GetResult_Event response(::prak_msgs::action::ActuatorCommand_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::prak_msgs::action::ActuatorCommand_GetResult_Event msg_;
};

class Init_ActuatorCommand_GetResult_Event_request
{
public:
  explicit Init_ActuatorCommand_GetResult_Event_request(::prak_msgs::action::ActuatorCommand_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_ActuatorCommand_GetResult_Event_response request(::prak_msgs::action::ActuatorCommand_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ActuatorCommand_GetResult_Event_response(msg_);
  }

private:
  ::prak_msgs::action::ActuatorCommand_GetResult_Event msg_;
};

class Init_ActuatorCommand_GetResult_Event_info
{
public:
  Init_ActuatorCommand_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ActuatorCommand_GetResult_Event_request info(::prak_msgs::action::ActuatorCommand_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ActuatorCommand_GetResult_Event_request(msg_);
  }

private:
  ::prak_msgs::action::ActuatorCommand_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::prak_msgs::action::ActuatorCommand_GetResult_Event>()
{
  return prak_msgs::action::builder::Init_ActuatorCommand_GetResult_Event_info();
}

}  // namespace prak_msgs


namespace prak_msgs
{

namespace action
{

namespace builder
{

class Init_ActuatorCommand_FeedbackMessage_feedback
{
public:
  explicit Init_ActuatorCommand_FeedbackMessage_feedback(::prak_msgs::action::ActuatorCommand_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::prak_msgs::action::ActuatorCommand_FeedbackMessage feedback(::prak_msgs::action::ActuatorCommand_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::prak_msgs::action::ActuatorCommand_FeedbackMessage msg_;
};

class Init_ActuatorCommand_FeedbackMessage_goal_id
{
public:
  Init_ActuatorCommand_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ActuatorCommand_FeedbackMessage_feedback goal_id(::prak_msgs::action::ActuatorCommand_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ActuatorCommand_FeedbackMessage_feedback(msg_);
  }

private:
  ::prak_msgs::action::ActuatorCommand_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::prak_msgs::action::ActuatorCommand_FeedbackMessage>()
{
  return prak_msgs::action::builder::Init_ActuatorCommand_FeedbackMessage_goal_id();
}

}  // namespace prak_msgs

#endif  // PRAK_MSGS__ACTION__DETAIL__ACTUATOR_COMMAND__BUILDER_HPP_
