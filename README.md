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
* Get a 110V (120V?) transformer with enough power (kjell has a 300w but we don’t know the specs on the powercore, pending discord)
