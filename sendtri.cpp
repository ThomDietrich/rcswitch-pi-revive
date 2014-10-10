/*
 Usage: ./sendtri <unitCode> <command>
 UnitCode is 1 for unit 1, 2 for unit 2,...8 for unit 8
 Command is 0 for OFF, 1 for ON
 */

#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    
    /*
     output PIN is hardcoded for testing purposes
     see https://projects.drogon.net/raspberry-pi/wiringpi/pins/
     for pin mapping of the raspberry pi GPIO connector
     */
    int PIN = 0;
    int unitCode = atoi(argv[1]);
    int command  = atoi(argv[2]);
    char on1[] = "011100001000S";
    char on2[] = "001100001000S";
    char on3[] = "010100001000S";
    char on4[] = "000100001000S";
    char on5[] = "011000001000S";
    char on6[] = "001000001000S";
    char on7[] = "010000001000S";
    char on8[] = "000000001000S";
    char off1[]= "011100000000S";
    char off2[]= "001100000000S";
    char off3[]= "010100000000S";
    char off4[]= "000100000000S";
    char off5[]= "011000000000S";
    char off6[]= "001000000000S";
    char off7[]= "010000000000S";
    char off8[]= "000000000000S";
    
    if (wiringPiSetup () == -1) return 1;
    RCSwitch mySwitch = RCSwitch();
    mySwitch.enableTransmit(PIN);
    
    switch(unitCode) {
        case 1:
	    if (command == 1) { 
                printf("Sending TriState code [%s]\n", on1);
    		mySwitch.sendTriState(on1);
	    } else {
                printf("Sending TriState code [%s]\n", off1);
    		mySwitch.sendTriState(off1);
	    }
            break;
        case 2:
	    if (command == 1) { 
                printf("Sending TriState code [%s]\n", on2);
    		mySwitch.sendTriState(on1);
	    } else {
                printf("Sending TriState code [%s]\n", off2);
    		mySwitch.sendTriState(off1);
	    }
            break;
        case 3:
	    if (command == 1) { 
                printf("Sending TriState code [%s]\n", on3);
    		mySwitch.sendTriState(on1);
	    } else {
                printf("Sending TriState code [%s]\n", off3);
    		mySwitch.sendTriState(off1);
	    }
            break;
        case 4:
	    if (command == 1) { 
                printf("Sending TriState code [%s]\n", on4);
    		mySwitch.sendTriState(on1);
	    } else {
                printf("Sending TriState code [%s]\n", off4);
    		mySwitch.sendTriState(off1);
	    }
            break;
        case 5:
	    if (command == 1) { 
                printf("Sending TriState code [%s]\n", on5);
    		mySwitch.sendTriState(on1);
	    } else {
                printf("Sending TriState code [%s]\n", off5);
    		mySwitch.sendTriState(off1);
	    }
            break;
        case 6:
	    if (command == 1) { 
                printf("Sending TriState code [%s]\n", on6);
    		mySwitch.sendTriState(on1);
	    } else {
                printf("Sending TriState code [%s]\n", off6);
    		mySwitch.sendTriState(off1);
	    }
            break;
        case 7:
	    if (command == 1) { 
                printf("Sending TriState code [%s]\n", on7);
    		mySwitch.sendTriState(on1);
	    } else {
                printf("Sending TriState code [%s]\n", off7);
    		mySwitch.sendTriState(off1);
	    }
            break;
        case 8:
	    if (command == 1) { 
                printf("Sending TriState code [%s]\n", on8);
    		mySwitch.sendTriState(on1);
	    } else {
                printf("Sending TriState code [%s]\n", off8);
    		mySwitch.sendTriState(off1);
	    }
            break;
        default:
            printf("unitCode[%i] is unsupported\n", unitCode);
            return -1;
    }
	return 0;
}
