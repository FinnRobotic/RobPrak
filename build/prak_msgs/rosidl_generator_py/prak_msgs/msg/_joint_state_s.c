// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from prak_msgs:msg/JointState.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "prak_msgs/msg/detail/joint_state__struct.h"
#include "prak_msgs/msg/detail/joint_state__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool prak_msgs__msg__joint_state__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
    if (class_attr == NULL) {
      return false;
    }
    PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
    if (name_attr == NULL) {
      Py_DECREF(class_attr);
      return false;
    }
    PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
    if (module_attr == NULL) {
      Py_DECREF(name_attr);
      Py_DECREF(class_attr);
      return false;
    }

    // PyUnicode_1BYTE_DATA is just a cast
    assert(strncmp("prak_msgs.msg._joint_state", (char *)PyUnicode_1BYTE_DATA(module_attr), 26) == 0);
    assert(strncmp("JointState", (char *)PyUnicode_1BYTE_DATA(name_attr), 10) == 0);

    Py_DECREF(module_attr);
    Py_DECREF(name_attr);
    Py_DECREF(class_attr);
  }
  prak_msgs__msg__JointState * ros_message = _ros_message;
  {  // shoulder_pan_joint
    PyObject * field = PyObject_GetAttrString(_pymsg, "shoulder_pan_joint");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->shoulder_pan_joint = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // shoulder_lift_joint
    PyObject * field = PyObject_GetAttrString(_pymsg, "shoulder_lift_joint");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->shoulder_lift_joint = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // elbow_joint
    PyObject * field = PyObject_GetAttrString(_pymsg, "elbow_joint");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->elbow_joint = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // wrist_1_joint
    PyObject * field = PyObject_GetAttrString(_pymsg, "wrist_1_joint");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->wrist_1_joint = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // wrist_2_joint
    PyObject * field = PyObject_GetAttrString(_pymsg, "wrist_2_joint");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->wrist_2_joint = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // wrist_3_joint
    PyObject * field = PyObject_GetAttrString(_pymsg, "wrist_3_joint");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->wrist_3_joint = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * prak_msgs__msg__joint_state__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of JointState */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("prak_msgs.msg._joint_state");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "JointState");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  prak_msgs__msg__JointState * ros_message = (prak_msgs__msg__JointState *)raw_ros_message;
  {  // shoulder_pan_joint
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->shoulder_pan_joint);
    {
      int rc = PyObject_SetAttrString(_pymessage, "shoulder_pan_joint", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // shoulder_lift_joint
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->shoulder_lift_joint);
    {
      int rc = PyObject_SetAttrString(_pymessage, "shoulder_lift_joint", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // elbow_joint
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->elbow_joint);
    {
      int rc = PyObject_SetAttrString(_pymessage, "elbow_joint", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // wrist_1_joint
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->wrist_1_joint);
    {
      int rc = PyObject_SetAttrString(_pymessage, "wrist_1_joint", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // wrist_2_joint
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->wrist_2_joint);
    {
      int rc = PyObject_SetAttrString(_pymessage, "wrist_2_joint", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // wrist_3_joint
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->wrist_3_joint);
    {
      int rc = PyObject_SetAttrString(_pymessage, "wrist_3_joint", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
