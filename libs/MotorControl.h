/*
MotorControl.h - Library to control 2 motors.
*/

#ifndef MotorControl_h
#define MotorControl_h

#include "Arduino.h"

class MotorControl
{
	public:
		MotorControl(int pinL1,int pinL2,int pwmL,int pinR1,int pinR2,int pwmR);
		void straight();
		void left();
		void right();
		void uturn();
		void goahead();
		void halt();
	private:
		int _pinL1;
		int _pinL2;
		int _pwmL;
		int _pinR1;
		int _pinR2;
		int _pwmR;
};
#endif