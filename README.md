# rcswitch-pi-revive

Reviving the rc-switch implementation for the Raspberry Pi, originally developed at [r10r/rcswitch-pi](https://github.com/r10r/rcswitch-pi).


# Changes to the original version by (oliverlorenz)

This is a special customized version to work with Intertechno Type B switches (tested with ITL-230 and ITR-1500)

Found the original code on http://www.gsurf.de/raspberry-pi-rcswitch-pi-und-openhab/ and changed them to work only with type B switches

usage:

./send [systemcode] [unitcode] [on/off]

./send 1 1 1 # on
./send 1 1 0 # off
