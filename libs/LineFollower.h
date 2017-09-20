/*
LineFollower.h - Library for line follower using 5 sensors.
*/

#ifndef LineFollower_h
#define LineFollower_h

#include "Arduino.h"

class LineFollower
{
	public:
		LineFollower(int pinA1,int pinA2,int pinA3,int pinA4,int pinA5,int ledpin);
		void line_follower();
		void led_blink();
	private:
		int _pinA1;
		int _pinA2;
		int _pinA3;
		int _pinA4;
		int _pinA5;
		int _ledpin;
};
#endif