# (c) 2014 Daniel Standage <daniel.standage@gmail.com>
#     This is free and unencumbered software released into the public domain.
from my.Gizmo import Gizmo
from my.load import mylib

class Data:

  def __init__(self, datap, desc, meta, gizmo=None):
    self.d = mylib.my_data_create(datap, desc, meta, gizmo)
    self._as_parameter_ = self.d

  def __del__(self):
    mylib.my_data_delete(self.d)

  def __str__(self):
    return mylib.my_data_description(self.d)

  def from_param(cls, obj):
    if not isinstance(obj, Data):
      raise TypeError("argument must be of class 'Data'")
    return obj._as_parameter_

  from_param = classmethod(from_param)

  def register(cls, mylib):
    from ctypes import c_void_p, c_char_p
    mylib.my_data_create.restype = c_void_p
    mylib.my_data_create.argtypes = [c_void_p, c_char_p, c_char_p, Gizmo]
    mylib.my_data_delete.restype = None
    mylib.my_data_delete.argtypes = [c_void_p]
    mylib.my_data_description.restype = c_char_p
    mylib.my_data_description.argtypes = [c_void_p]

  register = classmethod(register)
