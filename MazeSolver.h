/*
MazeSolver.h - Library to solve maze using 5 line follower sensors.
*/

#ifndef MazeSolver_h
#define MazeSolver_h

#include "Arduino.h"

class MazeSolver_h
{
	public:
		MazeSolver(int pinA1,int pinA2,int pinA3,int pinA4,int pinA5,int ledpin);
		void maze_solver();
		void maze_runner();
		void maze_solver();
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