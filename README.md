### Summary
We are building a Electrical Discharge Machining (EDM) CNC.

[EDM on wikipedia: ](https://en.wikipedia.org/wiki/Electrical_discharge_machining)
*Electrical discharge machining (EDM), also known as spark machining, spark eroding, die sinking, wire burning or wire erosion, is a metal fabrication process whereby a desired shape is obtained by using electrical discharges (sparks).*

 
 #### Hackaton 21-22 of February 2024.

Cut 0.5 mm Aluminium parts

![image](https://github.com/Fabricatable-Machines/FabricateEDM/assets/3476653/b793300d-9cf0-4a9d-a21c-f98e820e3691)

![image](https://github.com/Fabricatable-Machines/FabricateEDM/assets/3476653/d9c0335d-7e6c-42ab-912d-1bd8c9638546)

[![image](https://github.com/Fabricatable-Machines/FabricateEDM/assets/3476653/b63d0721-819b-4e95-97eb-6c598b2c9c6e)](https://photos.app.goo.gl/N2ZNjn7RKqB6QSyi7)

Also experimented with 5mm steel (no luck), 1mm stainless steel (success with extreme electrode wear) and titanium.

We belive lower feedrates will yeild better results during:

[EDM Hackaton #2](https://meetu.ps/e/MYcvP/d1LWY/i) in Oslo 20 March at [Bitraf Makerspace](https://bitraf.no/)

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

**NB It seems we have been fooled by the the Ultimaker1 firmware. There is probably a minimum feedrate of about 4mm/m that the firmware has rounded our feedrates up to**

 - Titanium 0.5mm thick - 1.5mm brass electrode: Feedrate: 0.15mm/m, plungerate: 0.04mm/m, wear ratio: 0.5 *(Drilling and cutting worked, but shorted randomly some times. Settings might be at the edge of capacity.* **Don't use these settings, only for reference**
 - Stainless steel 1mm thick - 1.5mm brass electrode: Feedrate: 0.3mm/m, plungerate: ?, wear ratio: 2 **Don't use these settings, only for reference**

### Open questions and todos:
* Get more de-ionized water [Biltema](https://www.biltema.no/bil---mc/bilbatterier/batteritilbehor/destillert-vann-4-liter-2000054547)
* Test re-use of water using a funnel and some filters (what grade?)
* Can we live tune the feed speed using the spark feedback from the powercore, (using a separate microcontroller?  
* Make/find a place for the machine at bitraf, label it properly.
* Write bitraf wiki-guide on how to use, programs needed and settings
