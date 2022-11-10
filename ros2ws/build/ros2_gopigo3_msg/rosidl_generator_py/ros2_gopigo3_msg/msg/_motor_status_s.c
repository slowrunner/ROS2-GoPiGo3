// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ros2_gopigo3_msg:msg/MotorStatus.idl
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
#include "ros2_gopigo3_msg/msg/detail/motor_status__struct.h"
#include "ros2_gopigo3_msg/msg/detail/motor_status__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ros2_gopigo3_msg__msg__motor_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[47];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("ros2_gopigo3_msg.msg._motor_status.MotorStatus", full_classname_dest, 46) == 0);
  }
  ros2_gopigo3_msg__msg__MotorStatus * ros_message = _ros_message;
  {  // low_voltage
    PyObject * field = PyObject_GetAttrString(_pymsg, "low_voltage");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->low_voltage = (Py_True == field);
    Py_DECREF(field);
  }
  {  // overloaded
    PyObject * field = PyObject_GetAttrString(_pymsg, "overloaded");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->overloaded = (Py_True == field);
    Py_DECREF(field);
  }
  {  // power
    PyObject * field = PyObject_GetAttrString(_pymsg, "power");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->power = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // encoder
    PyObject * field = PyObject_GetAttrString(_pymsg, "encoder");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->encoder = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->speed = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ros2_gopigo3_msg__msg__motor_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of MotorStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ros2_gopigo3_msg.msg._motor_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "MotorStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ros2_gopigo3_msg__msg__MotorStatus * ros_message = (ros2_gopigo3_msg__msg__MotorStatus *)raw_ros_message;
  {  // low_voltage
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->low_voltage ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "low_voltage", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // overloaded
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->overloaded ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "overloaded", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // power
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->power);
    {
      int rc = PyObject_SetAttrString(_pymessage, "power", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // encoder
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->encoder);
    {
      int rc = PyObject_SetAttrString(_pymessage, "encoder", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // speed
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
