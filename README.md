# Changes to the original version

This is a special customized version to work with Intertechno Type B switches (tested with ITL-230 and ITR-1500)

Found the original code on http://www.gsurf.de/raspberry-pi-rcswitch-pi-und-openhab/ and changed them to work only with type B switches

usage:

./send [systemcode] [unitcode] [on/off]

./send 1 1 1 # on
./send 1 1 0 # off

# About

rcswitch-pi is for controlling rc remote controlled power sockets 
with the raspberry pi. Kudos to the projects [rc-switch](http://code.google.com/p/rc-switch)
and [wiringpi](https://projects.drogon.net/raspberry-pi/wiringpi).
I just adapted the rc-switch code to use the wiringpi library instead of
the library provided by the arduino.

## Usage

First you have to install the [wiringpi](https://projects.drogon.net/raspberry-pi/wiringpi/download-and-install/) library.
After that you can compile the example program *send* by executing *make*. 
You may want to changet the used GPIO pin before compilation in the send.cpp source file.
