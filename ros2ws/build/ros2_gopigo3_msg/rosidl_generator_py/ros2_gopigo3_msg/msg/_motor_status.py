# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ros2_gopigo3_msg:msg/MotorStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MotorStatus(type):
    """Metaclass of message 'MotorStatus'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ros2_gopigo3_msg')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ros2_gopigo3_msg.msg.MotorStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__motor_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__motor_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__motor_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__motor_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__motor_status

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MotorStatus(metaclass=Metaclass_MotorStatus):
    """Message class 'MotorStatus'."""

    __slots__ = [
        '_low_voltage',
        '_overloaded',
        '_power',
        '_encoder',
        '_speed',
    ]

    _fields_and_field_types = {
        'low_voltage': 'boolean',
        'overloaded': 'boolean',
        'power': 'int8',
        'encoder': 'float',
        'speed': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.low_voltage = kwargs.get('low_voltage', bool())
        self.overloaded = kwargs.get('overloaded', bool())
        self.power = kwargs.get('power', int())
        self.encoder = kwargs.get('encoder', float())
        self.speed = kwargs.get('speed', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.low_voltage != other.low_voltage:
            return False
        if self.overloaded != other.overloaded:
            return False
        if self.power != other.power:
            return False
        if self.encoder != other.encoder:
            return False
        if self.speed != other.speed:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def low_voltage(self):
        """Message field 'low_voltage'."""
        return self._low_voltage

    @low_voltage.setter
    def low_voltage(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'low_voltage' field must be of type 'bool'"
        self._low_voltage = value

    @builtins.property
    def overloaded(self):
        """Message field 'overloaded'."""
        return self._overloaded

    @overloaded.setter
    def overloaded(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'overloaded' field must be of type 'bool'"
        self._overloaded = value

    @builtins.property
    def power(self):
        """Message field 'power'."""
        return self._power

    @power.setter
    def power(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'power' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'power' field must be an integer in [-128, 127]"
        self._power = value

    @builtins.property
    def encoder(self):
        """Message field 'encoder'."""
        return self._encoder

    @encoder.setter
    def encoder(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'encoder' field must be of type 'float'"
            assert value >= -3.402823e+38 and value <= 3.402823e+38, \
                "The 'encoder' field must be a float in [-3.402823e+38, 3.402823e+38]"
        self._encoder = value

    @builtins.property
    def speed(self):
        """Message field 'speed'."""
        return self._speed

    @speed.setter
    def speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'speed' field must be of type 'float'"
            assert value >= -3.402823e+38 and value <= 3.402823e+38, \
                "The 'speed' field must be a float in [-3.402823e+38, 3.402823e+38]"
        self._speed = value
