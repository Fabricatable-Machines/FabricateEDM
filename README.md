### Summary
We are building a Electrical Discharge Machining (EDM) CNC.

We have assembled most of the parts needed and will attempt assemby on the. 21-22 of February 2024.

### PSU - Powercore V1
We have the “Powercore V1” that was sold on kickstarter. It will generate the sparks and the kit comes with electrodes and some sample aluminium plates. I have purchased some titanium plates to test with also. Still needs some 3d-prints.

[Youtube video about the Powercore](https://youtu.be/D6MygL8R9kM?si=-dXRyd_AGkKtzGDO)

[Manual repo](https://github.com/Rack-Robotics/Powercore-V1.0-Manual)

The hardware and schematics repos are under the same organization.

### Motion platform - 3D printer
As our motion platform we are first intending to try recycling an old Ultimaker 1 3D printer. Its print bed is stationary in the XY plane but moves vertically. 

[Reprap wiki for Ultimaker 1](https://reprap.org/wiki/Ultimaker)

### CAM

The powercore team has made a CAM program called **EDMweb** that can be downloaded [here](https://github.com/Rack-Robotics/EDMWeb-Binaries). It is a fork of LASERweb.

The Ultimaker1 does not support moving bellow Z0 *(no negative coordinates allowed)*. We have a workaround by post processing the g-code with a python script and the Python Script plugin for Notepad++. The solution was found [here](https://www.cnczone.com/forums/g-code-programing/411754-cnc-cam-software.html).

Here is the script, it also in this repo:

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

And here is the tutorial for changing g-code coordinates with Notepad++ by lucaswalker:

    1) Install Python Script plugin from the Plugin Manager or from the official website.
    
    2) Then go to Plugins > Python Script > New Script. Choose a filename for your new file (eg add_numbers.py) and copy the code that follows:
    
    dx = 100.0
    dy = 100.0
    dz = 100.0
    
    def AddNumberToX(match):
     return 'X%s' % (str(float(match.group(1))+dx))
    
    def AddNumberToY(match):
     return 'Y%s' % (str(float(match.group(1))+dy))

    def AddNumberToZ(match):
     return 'Z%s' % (str(float(match.group(1))+dz))
    
    editor.rereplace('X([+-]?[0-9.]+)', AddNumberToX)
    editor.rereplace('Y([+-]?[0-9.]+)', AddNumberToY)
    editor.rereplace('Z([+-]?[0-9.]+)', AddNumberToZ)
    
    3) Run Plugins > Python Script > Scripts > add_numbers.py

The script needs to be in the scripts folder of Python Script: *C:\Program Files\Notepad++\plugins\PythonScript\scripts*. And you need to restart Notepad++ for the script to be available from the menu.

### Feedrates

 - Stainless steel 1mm thick - 1.5mm brass electrode: Feedrate: 0.3mm/m, plungerate: ?, wear ratio: 2

### Open questions and todos:
* Get de-ionized water
* Figure out what to use for a “bath”, can we print ABS and seal with acetone?
* CAD a tool mount for the ulitmaker XY-platform
* Print tool and part holder
* Do we need a custom postprocessor for the gcode?
* Can we live tune the feed speed using the spark feedback from the powercore, (using a separate microcontroller?  Do we need another firmware?)
* Get a US 110V transformer [300w from kjell.com](https://www.kjell.com/no/produkter/elektro-og-verktoy/stromadaptrer/acac-stromadapter/230-110-v-omformer-p44098) should be enough for typical feed rate //[source dev on discord](https://discord.com/channels/813870433165508688/1136460259809034363/1205999920125841528)
* 24V PSU for enable and to supply motherboard ([quickstart guide says to not use printer as 24V source](https://youtu.be/FpUhpkBXa6Q?si=DlgyjV4E4XxyUong)
