/*
LineFollower.cpp - Library for line follower using 5 sensors.
*/

#include "Arduino.h"
#include "MotorControl.h"
#include "LineFollower.h"

#define threshold 550

MotorControl motorcontrol(1,2,3,4,7,5);

LineFollower::LineFollower(int pinA1,int pinA2,int pinA3,int pinA4,int pinA5,int ledpin)
{
	_pinA1 = pinA1;
	_pinA2 = pinA2;
	_pinA3 = pinA3;
	_pinA4 = pinA4;
	_pinA5 = pinA5;
	_ledpin = ledpin;
	pinMode(_ledpin,OUTPUT);
}

void LineFollower::line_follower()
{
	if( analogRead(_pinA1) < threshold && analogRead(_pinA2) > threshold && analogRead(_pinA3) > threshold && analogRead(_pinA4) > threshold && analogRead(_pinA5) < threshold )	//01110
	{
		motorcontrol.straight();
	}
	else if( analogRead(_pinA1) < threshold && analogRead(_pinA2) > threshold && analogRead(_pinA3) < threshold && analogRead(_pinA4) < threshold && analogRead(_pinA5) < threshold )	//01000
	{
		motorcontrol.straight();
	}
	else if( analogRead(_pinA1) < threshold && analogRead(_pinA2) < threshold && analogRead(_pinA3) > threshold && analogRead(_pinA4) < threshold && analogRead(_pinA5) < threshold )	//00100
	{
		motorcontrol.straight();
	}
	else if( analogRead(_pinA1) < threshold && analogRead(_pinA2) < threshold && analogRead(_pinA3) < threshold && analogRead(_pinA4) > threshold && analogRead(_pinA5) < threshold )	//00010
	{
		motorcontrol.straight();
	}
	else if( analogRead(_pinA1) < threshold && analogRead(_pinA2) > threshold && analogRead(_pinA3) > threshold && analogRead(_pinA4) < threshold && analogRead(_pinA5) < threshold )	//01100
	{
		motorcontrol.straight();
	}
	else if( analogRead(_pinA1) < threshold && analogRead(_pinA2) < threshold && analogRead(_pinA3) > threshold && analogRead(_pinA4) > threshold && analogRead(_pinA5) < threshold )	//00110
	{
		motorcontrol.straight();
	}
	else if( analogRead(_pinA1) < threshold && analogRead(_pinA2) < threshold && analogRead(_pinA3) < threshold && analogRead(_pinA4) < threshold && analogRead(_pinA5) > threshold )	//00001
	{
		motorcontrol.right();
	}
	else if( analogRead(_pinA1) < threshold && analogRead(_pinA2) < threshold && analogRead(_pinA3) < threshold && analogRead(_pinA4) > threshold && analogRead(_pinA5) > threshold )	//00011
	{
		motorcontrol.right();
	}
	else if( analogRead(_pinA1) < threshold && analogRead(_pinA2) < threshold && analogRead(_pinA3) > threshold && analogRead(_pinA4) > threshold && analogRead(_pinA5) > threshold )	//00111
	{
		motorcontrol.right();
	}
	else if( analogRead(_pinA1) > threshold && analogRead(_pinA2) < threshold && analogRead(_pinA3) < threshold && analogRead(_pinA4) < threshold && analogRead(_pinA5) < threshold )	//10000
	{
		motorcontrol.goahead();
		if ( analogRead(_pinA1) < threshold && analogRead(_pinA2) > threshold && analogRead(_pinA3) > threshold && analogRead(_pinA4) > threshold && analogRead(_pinA5) < threshold )//01110
		{
			motorcontrol.straight();
		}
		else if (analogRead(_pinA1) < threshold && analogRead(_pinA2) > threshold && analogRead(_pinA3) > threshold && analogRead(_pinA4) < threshold && analogRead(_pinA5) < threshold)//01100
		{
			motorcontrol.straight();
		}
		else if (analogRead(_pinA1) < threshold && analogRead(_pinA2) < threshold && analogRead(_pinA3) > threshold && analogRead(_pinA4) > threshold && analogRead(_pinA5) < threshold)//00110
		{
			motorcontrol.straight();
		}
		else
		{
			motorcontrol.left();
		}
	}
	else if ( analogRead(_pinA1) < threshold && analogRead(_pinA2) < threshold && analogRead(_pinA3) < threshold && analogRead(_pinA4) < threshold && analogRead(_pinA5) < threshold )//00000
	{
			motorcontrol.uturn();
	}
	else if ( analogRead(_pinA1) > threshold && analogRead(_pinA2) > threshold && analogRead(_pinA3) > threshold && analogRead(_pinA4) > threshold && analogRead(_pinA5) > threshold )//11111
	{
		motorcontrol.goahead();
		if ( analogRead(_pinA1) > threshold && analogRead(_pinA2) > threshold && analogRead(_pinA3) > threshold && analogRead(_pinA4) > threshold && analogRead(_pinA5) > threshold )
		{
			motorcontrol.halt();
			led_blink();
		}
		else
		{
			motorcontrol.right();
		}
	}
	else
	{}
}

void LineFollower::led_blink()
{
	digitalWrite(_ledpin,HIGH);
	_delay_ms(500);
	digitalWrite(_ledpin,LOW);
	_delay_ms(500);
}

