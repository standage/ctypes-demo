# (c) 2014 Daniel Standage <daniel.standage@gmail.com>
#     This is free and unencumbered software released into the public domain.
from ctypes import CDLL
import sys

ext = "so"
if sys.platform == "darwin":
  ext = "dylib"

mylib = CDLL("libmy.%s" % ext)
