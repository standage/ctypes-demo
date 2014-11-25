# (c) 2014 Daniel Standage <daniel.standage@gmail.com>
#     This is free and unencumbered software released into the public domain.
from load import mylib

class Gizmo:

  def __init__(self, count, label, model=None):
    self.g = mylib.my_gizmo_create(count, label, model)
    self._as_parameter_ = self.g

  def __del__(self):
    mylib.my_gizmo_delete(self.g)

  def __str__(self):
    return mylib.my_gizmo_get_label(self.g) +": "+ str(mylib.my_gizmo_get_gcount(self.g))

  def from_param(cls, obj):
    if not isinstance(obj, Gizmo):
      raise TypeError("argument must be of class 'Gizmo'")
    return obj._as_parameter_

  from_param = classmethod(from_param)

  def register(cls, mylib):
    from ctypes import c_void_p, c_uint, c_char_p
    mylib.my_gizmo_create.restype = c_void_p
    mylib.my_gizmo_create.argtypes = [c_uint, c_char_p, c_void_p]
    mylib.my_gizmo_delete.restype = None
    mylib.my_gizmo_delete.argtypes = [c_void_p]
    mylib.my_gizmo_get_gcount.restype = c_uint
    mylib.my_gizmo_get_gcount.argtypes = [c_void_p]
    mylib.my_gizmo_get_label.restype = c_char_p
    mylib.my_gizmo_get_label.argtypes = [c_void_p]

  register = classmethod(register)
