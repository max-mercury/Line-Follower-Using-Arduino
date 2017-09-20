/*
MotorControl.cpp - Library to control 2 motors.
*/

#include "Arduino.h"
#include "MotorControl.h"

#define pwmvalue 150

MotorControl::MotorControl(int pinL1,int pinL2,int pwmL,int pinR1,int pinR2,int pwmR)
{
	_pinL1 = pinL1;
	_pinL2 = pinL2;
	_pwmL = pwmL;
	_pinR1 = pinR1;
	_pinR2 = pinR2;
	_pwmR = pwmR;
	pinMode(_pinL1,OUTPUT);
	pinMode(_pinL2,OUTPUT);
	pinMode(_pwmL,OUTPUT);
	pinMode(_pinR1,OUTPUT);
	pinMode(_pinR2,OUTPUT);
	pinMode(_pwmR,OUTPUT);
}

void MotorControl::straight()
{
	digitalWrite(_pinL2,HIGH);
	digitalWrite(_pinL1,LOW);
	analogWrite(_pwmL,pwmvalue);
	
	digitalWrite(_pinR2,HIGH);
	digitalWrite(_pinR1,LOW);
	analogWrite(_pwmR,pwmvalue);
}

void MotorControl::left()
{
	digitalWrite(_pinL2,LOW);
	digitalWrite(_pinL1,HIGH);
	analogWrite(_pwmL,pwmvalue);
	
	digitalWrite(_pinR2,HIGH);
	digitalWrite(_pinR1,LOW);
	analogWrite(_pwmR,pwmvalue);
}

void MotorControl::right()
{
	digitalWrite(_pinL2,HIGH);
	digitalWrite(_pinL1,LOW);
	analogWrite(_pwmL,pwmvalue);
	
	digitalWrite(_pinR2,LOW);
	digitalWrite(_pinR1,HIGH);
	analogWrite(_pwmR,pwmvalue);
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

void MotorControl::halt()
{
	digitalWrite(_pinL1,LOW);
	digitalWrite(_pinL2,LOW);
	analogWrite(_pwmL,0);
	digitalWrite(_pinR1,LOW);
	digitalWrite(_pinR2,LOW);
	analogWrite(_pwmR,0);
}