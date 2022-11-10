# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ros2_gopigo3_msg:srv/SPI.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'data_out'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SPI_Request(type):
    """Metaclass of message 'SPI_Request'."""

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
                'ros2_gopigo3_msg.srv.SPI_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__spi__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__spi__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__spi__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__spi__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__spi__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SPI_Request(metaclass=Metaclass_SPI_Request):
    """Message class 'SPI_Request'."""

    __slots__ = [
        '_data_out',
    ]

    _fields_and_field_types = {
        'data_out': 'sequence<uint8>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint8')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.data_out = array.array('B', kwargs.get('data_out', []))

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
        if self.data_out != other.data_out:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def data_out(self):
        """Message field 'data_out'."""
        return self._data_out

    @data_out.setter
    def data_out(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'B', \
                "The 'data_out' array.array() must have the type code of 'B'"
            self._data_out = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'data_out' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 255]"
        self._data_out = array.array('B', value)


# Import statements for member types

# Member 'data_in'
# already imported above
# import array

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SPI_Response(type):
    """Metaclass of message 'SPI_Response'."""

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
                'ros2_gopigo3_msg.srv.SPI_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__spi__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__spi__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__spi__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__spi__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__spi__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SPI_Response(metaclass=Metaclass_SPI_Response):
    """Message class 'SPI_Response'."""

    __slots__ = [
        '_data_in',
    ]

    _fields_and_field_types = {
        'data_in': 'sequence<uint8>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint8')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.data_in = array.array('B', kwargs.get('data_in', []))

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
        if self.data_in != other.data_in:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def data_in(self):
        """Message field 'data_in'."""
        return self._data_in

    @data_in.setter
    def data_in(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'B', \
                "The 'data_in' array.array() must have the type code of 'B'"
            self._data_in = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'data_in' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 255]"
        self._data_in = array.array('B', value)


class Metaclass_SPI(type):
    """Metaclass of service 'SPI'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ros2_gopigo3_msg')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ros2_gopigo3_msg.srv.SPI')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__spi

            from ros2_gopigo3_msg.srv import _spi
            if _spi.Metaclass_SPI_Request._TYPE_SUPPORT is None:
                _spi.Metaclass_SPI_Request.__import_type_support__()
            if _spi.Metaclass_SPI_Response._TYPE_SUPPORT is None:
                _spi.Metaclass_SPI_Response.__import_type_support__()


class SPI(metaclass=Metaclass_SPI):
    from ros2_gopigo3_msg.srv._spi import SPI_Request as Request
    from ros2_gopigo3_msg.srv._spi import SPI_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
