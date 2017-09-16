/*
LineFollower.cpp - Library for line follower using 5 sensors.
*/

#include "Arduino.h"
#include "MotorControl.h"
#include "LineFollower.h"

#define threshold 550

MotorControl motorcontrol(5,6,7,8,9,10);

LineFollower::LineFollower(int pinA1,int pinA2,int pinA3,int pinA4,int pinA5,int ledpin)
{
	_pinA1 = pinA1;
	_pinA2 = pinA2;
	_pinA3 = pinA3;
	_pinA4 = pinA4;
	_pinA5 = pinA5;
	_ledpin = ledpin;
}

void LineFollower::line_follower()
{
	if( _pinA1 < threshold && _pinA2 > threshold && _pinA3 > threshold && _pinA4 > threshold && _pinA5 < threshold )	//01110
	{
		motorcontrol.straight();
	}
	else if( _pinA1 < threshold && _pinA2 > threshold && _pinA3 < threshold && _pinA4 < threshold && _pinA5 < threshold )	//01000
	{
		motorcontrol.straight();
	}
	else if( _pinA1 < threshold && _pinA2 < threshold && _pinA3 > threshold && _pinA4 < threshold && _pinA5 < threshold )	//00100
	{
		motorcontrol.straight();
	}
	else if( _pinA1 < threshold && _pinA2 < threshold && _pinA3 < threshold && _pinA4 > threshold && _pinA5 < threshold )	//00010
	{
		motorcontrol.straight();
	}
	else if( _pinA1 < threshold && _pinA2 > threshold && _pinA3 > threshold && _pinA4 < threshold && _pinA5 < threshold )	//01100
	{
		motorcontrol.straight();
	}
	else if( _pinA1 < threshold && _pinA2 < threshold && _pinA3 > threshold && _pinA4 > threshold && _pinA5 < threshold )	//00110
	{
		motorcontrol.straight();
	}
	else if( _pinA1 < threshold && _pinA2 < threshold && _pinA3 < threshold && _pinA4 < threshold && _pinA5 > threshold )	//00001
	{
		motorcontrol.right();
	}
	else if( _pinA1 < threshold && _pinA2 < threshold && _pinA3 < threshold && _pinA4 > threshold && _pinA5 > threshold )	//00011
	{
		motorcontrol.right();
	}
	else if( _pinA1 < threshold && _pinA2 < threshold && _pinA3 > threshold && _pinA4 > threshold && _pinA5 > threshold )	//00111
	{
		motorcontrol.right();
	}
	else if( _pinA1 > threshold && _pinA2 < threshold && _pinA3 < threshold && _pinA4 < threshold && _pinA5 < threshold )	//10000
	{
		goahead();
		if ( _pinA1 < threshold && _pinA2 > threshold && _pinA3 > threshold && _pinA4 > threshold && _pinA5 < threshold )//01110
		{
			motorcontrol.straight();
		}
		else if (_pinA1 < threshold && _pinA2 > threshold && _pinA3 > threshold && _pinA4 < threshold && _pinA5 < threshold)//01100
		{
			motorcontrol.straight();
		}
		else if (_pinA1 < threshold && _pinA2 < threshold && _pinA3 > threshold && _pinA4 > threshold && _pinA5 < threshold)//00110
		{
			motorcontrol.straight();
		}
		else
		{
			motorcontrol.left();
		}
	}
	else if ( _pinA1 < threshold && _pinA2 < threshold && _pinA3 < threshold && _pinA4 < threshold && _pinA5 < threshold )//00000
	{
			motorcontrol.uturn();
	}
	else if ( _pinA1 > threshold && _pinA2 > threshold && _pinA3 > threshold && _pinA4 > threshold && _pinA5 > threshold )//11111
	{
		goahead();
		if ( _pinA1 > threshold && _pinA2 > threshold && _pinA3 > threshold && _pinA4 > threshold && _pinA5 > threshold )
		{
			motorcontrol.stop();
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
	digitalWrite(_ledping,LOW);
	_delay_ms(500);
}

