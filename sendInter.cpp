/*
 * Usage: ./sendInter <familyCode> <groupCode> <deviceCode> <command>
 * Command is 0 for OFF and 1 for ON
 */

#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

	/*
	* output PIN is hardcoded for testing purposes
	* see https://projects.drogon.net/raspberry-pi/wiringpi/pins/
	* for pin mapping of the raspberry pi GPIO connector
	*/
	int PIN = 0;
	char familyCode = argv[1][0];
	int groupCode = atoi(argv[2]);
	int deviceCode = atoi(argv[3]);
	int command  = atoi(argv[4]);

	if (wiringPiSetup () == -1) return 1;
		printf("sending familyCode[%c] groupCode[%i] deviceCode[%i] command[%i]\n", familyCode, groupCode, deviceCode, command);
		RCSwitch mySwitch = RCSwitch();
		mySwitch.enableTransmit(PIN);

	switch(command) {
		case 1:
		  mySwitch.switchOn(familyCode, groupCode, deviceCode);
		  break;
		case 0:
		  mySwitch.switchOff(familyCode, groupCode, deviceCode);
		  break;
		default:
		  printf("command[%i] is unsupported\n", command);
		  return -1;
	}
	return 0;
}
