#include <softPwm.h>
#include <stdlib.h>
#include "servo.h"

#define PIN 3

int stirsetup() {
	if(wiringPiSetup() == -1)
		return 1;

	softPwmCreate(PIN,0,200);
}
int stir() {

	softPwmWrite(PIN,50);
	delay(5000);
	softPwmWrite(PIN, 0);
	return 0;
}
