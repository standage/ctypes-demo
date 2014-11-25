#!/usr/bin/env python
from my import *
g1 = Gizmo(15, "Gizmo 1")
g2 = Gizmo(20, "Gizmo 2", g1)
d1 = Data(None, "Empty data", "useless=true;level=9000", g2)
print str(g1)
print str(g2)
print str(d1)
