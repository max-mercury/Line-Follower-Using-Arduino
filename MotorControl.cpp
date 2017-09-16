/*
MotorControl.cpp - Library to control 2 motors.
*/

#include "Arduino.h"
#include "MotorControl.h"

#define pwmvalue 150

MotorControl::MotorControl(int pinL1,int pinL2,int pwmL,int pinR1,int pinR2,int pwmR)
{
	pinMode(pinL1,OUTPUT);
	pinMode(pinL2,OUTPUT);
	pinMode(pwmL,OUTPUT);
	pinMode(pinR1,OUTPUT);
	pinMode(pinR2,OUTPUT);
	pinMode(pwmR,OUTPUT);
	_pinL1 = pinL1;
	_pinL2 = pinL2;
	_pwmL = pwmL;
	_pinR1 = pinR1;
	_pinR2 = pinR2;
	_pwmR = pwmR;
}

void MotorControl::straight()
{
	digitalWrite(_pinL1,HIGH);
	digitalWrite(_pinL2,LOW);
	analogWrite(pwmL,pwmvalue);
	
	digitalWrite(_pinR1,HIGH);
	digitalWrite(_pinR2,LOW);
	analogWrite(pwmR,pwmvalue);
}

void MotorControl::left()
{
	digitalWrite(_pinL1,LOW);
	digitalWrite(_pinL2,HIGH);
	analogWrite(pwmL,pwmvalue);
	
	digitalWrite(_pinR1,HIGH);
	digitalWrite(_pinR2,LOW);
	analogWrite(pwmR,pwmvalue);
}

void MotorControl::right()
{
	digitalWrite(_pinL1,HIGH);
	digitalWrite(_pinL2,LOW);
	analogWrite(pwmL,pwmvalue);
	
	digitalWrite(_pinR1,LOW);
	digitalWrite(_pinR2,HIGH);
	analogWrite(pwmR,pwmvalue);
}

void MotorControl::uturn()
{
	left();
}

void MotorControl::goahead()
{
	straight();
	_delay_ms(100);
}