#include <lcd.h>
#include <stdio.h>
#include <wiringPi.h>
#include "lcd.h"

#define LCD_RS 11
#define LCD_E 10
#define LCD_D4 6
#define LCD_D5 5
#define LCD_D6 4
#define LCD_D7 1

int lcd;

int lcdsetup()
{
	wiringPiSetup();
	if(lcd = lcdInit (2, 16, 4, LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0)) {
		printf("lcd init failed!\n");
		return -1;
	}

	return 0;
}
int lcdprint(char* first, char* second) {
	lcdHome(lcd);
	delay(100);
	lcdClear(lcd);
	delay(100);
	lcdPosition(lcd, 0, 0);
	lcdPuts(lcd, first);	
	delay(100);	
	lcdPosition(lcd, 0, 1);
	lcdPuts(lcd, second);
	
	return 0;
}
