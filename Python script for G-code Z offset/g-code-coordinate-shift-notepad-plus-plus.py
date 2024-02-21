dx = 0.0
dy = 0.0
dz = 50.0

def AddNumberToX(match):
 return 'X%s' % (str(float(match.group(1))+dx))

def AddNumberToY(match):
 return 'Y%s' % (str(float(match.group(1))+dy))

def AddNumberToZ(match):
 return 'Z%s' % (str(float(match.group(1))+dz))

editor.rereplace('X([+-]?[0-9.]+)', AddNumberToX)
editor.rereplace('Y([+-]?[0-9.]+)', AddNumberToY)
editor.rereplace('Z([+-]?[0-9.]+)', AddNumberToZ)