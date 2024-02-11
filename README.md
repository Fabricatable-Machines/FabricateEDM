## Summary
We are building a Electrical Discharge Machining (EDM) CNC.

We have assembled most of the parts needed and will attempt assemby on the. 21-22 of February 2024.

## PSU - Powercore V1
We have the “Powercore V1” that was sold on kickstarter. It will generate the sparks and the kit comes with electrodes and some sample aluminium plates. I have purchased some titanium plates to test with also. Still needs some 3d-prints.

[Youtube video about the Powercore](https://youtu.be/D6MygL8R9kM?si=-dXRyd_AGkKtzGDO)

[Manual repo](https://github.com/Rack-Robotics/Powercore-V1.0-Manual)

The hardware and schematics repos are under the same organization.

## Motion platform - 3D printer
As our motion platform we are first intending to try recycling an old Ultimaker 1 3D printer. Its print bed is stationary in the XY plane but moves vertically. 

[Reprap wiki for Ultimaker 1](https://reprap.org/wiki/Ultimaker)

## Open questions and todos:
* Get de-ionized water
* Figure out what to use for a “bath”, can we print ABS and seal with acetone?
* CAD a tool mount for the ulitmaker XY-platform
* Print tool and part holder
* Do we need a custom postprocessor for the gcode?
* Can we live tune the feed speed using the spark feedback from the powercore, (using a separate microcontroller?  Do we need another firmware?)
* Get a US 110V transformer [300w from kjell.com](https://www.kjell.com/no/produkter/elektro-og-verktoy/stromadaptrer/acac-stromadapter/230-110-v-omformer-p44098) should be enough for typical feed rate //[source dev on discord](https://discord.com/channels/813870433165508688/1136460259809034363/1205999920125841528)
* 24V PSU for enable and to supply motherboard ([quickstart guide says to not use printer as 24V source](https://youtu.be/FpUhpkBXa6Q?si=DlgyjV4E4XxyUong)
