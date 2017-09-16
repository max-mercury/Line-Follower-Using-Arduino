/*
MazeSolver.cpp - Library to solve maze using 5 line follower sensors.
*/

#include "Arduino.h"
#include "MotorControl.h"
#include "LineFollower.h"

#define threshold 550

MotorControl motorcontrol(5,6,7,8,9,10);

char arry[1000];
int i,j;
	
MazeSolver::MazeSolver(int pinA1,int pinA2,int pinA3,int pinA4,int pinA5,int ledpin)
{
	_pinA1 = pinA1;
	_pinA2 = pinA2;
	_pinA3 = pinA3;
	_pinA4 = pinA4;
	_pinA5 = pinA5;
	_ledpin = ledpin;
	i=0;
	j=0;
}

void MazeSolver::line_follower()
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
		arry[i] = 'R';
		i++;
	}
	else if( _pinA1 < threshold && _pinA2 < threshold && _pinA3 < threshold && _pinA4 > threshold && _pinA5 > threshold )	//00011
	{
		motorcontrol.right();
		arry[i] = 'R';
		i++;
	}
	else if( _pinA1 < threshold && _pinA2 < threshold && _pinA3 > threshold && _pinA4 > threshold && _pinA5 > threshold )	//00111
	{
		motorcontrol.right();
		arry[i] = 'R';
		i++;
	}
	else if( _pinA1 > threshold && _pinA2 < threshold && _pinA3 < threshold && _pinA4 < threshold && _pinA5 < threshold )	//10000
	{
		goahead();
		if ( _pinA1 < threshold && _pinA2 > threshold && _pinA3 > threshold && _pinA4 > threshold && _pinA5 < threshold )//01110
		{
			motorcontrol.straight();
			arry[i] = 'S';
			i++;
		}
		else if (_pinA1 < threshold && _pinA2 > threshold && _pinA3 > threshold && _pinA4 < threshold && _pinA5 < threshold)//01100
		{
			motorcontrol.straight();
			arry[i] = 'S';
			i++;
		}
		else if (_pinA1 < threshold && _pinA2 < threshold && _pinA3 > threshold && _pinA4 > threshold && _pinA5 < threshold)//00110
		{
			motorcontrol.straight();
			arry[i] = 'S';
			i++;
		}
		else
		{
			motorcontrol.left();
			arry[i] = 'L';
			i++;
		}
	}
	else if ( _pinA1 < threshold && _pinA2 < threshold && _pinA3 < threshold && _pinA4 < threshold && _pinA5 < threshold )//00000
	{
			motorcontrol.uturn();
			arry[i] = 'U';
			i++;
	}
	else if ( _pinA1 > threshold && _pinA2 > threshold && _pinA3 > threshold && _pinA4 > threshold && _pinA5 > threshold )//11111
	{
		goahead();
		if ( _pinA1 > threshold && _pinA2 > threshold && _pinA3 > threshold && _pinA4 > threshold && _pinA5 > threshold )
		{
			motorcontrol.stop();
			led_blink();
			_delay_ms(1000);
			maze_solver();
			maze_runner();
			arry[i] = 'W';
			i++;
		}
		else
		{
			motorcontrol.right();
			arry[i] = 'R';
			i++;
		}
	}
	else
	{}
}

void MazeSolver::led_blink()
{
	digitalWrite(_ledpin,HIGH);
	_delay_ms(500);
	digitalWrite(_ledping,LOW);
	_delay_ms(500);
}

void MazeSolver::maze_solver()
{
	for (i=0;i<len(arry)-1;i++)
	{
		if (arry[i]=='U')
		{
			if (arry[i-1]=='S' && arry[i+1]=='R')
			{
				replace(arry[i],'L');
				remove(arry[i-1]);
				remove(arry[i+1]);
			}
			else if (arry[i-1]=='R' && arry[i+1]=='R')
			{
				replace(arry[i],'S');
				remove(arry[i-1]);
				remove(arry[i+1]);
			}
			else if (arry[i-1]=='R' && arry[i+1]=='L')
			{
				replace(arry[i],'U');
				remove(arry[i-1]);
				remove(arry[i+1]);
			}
			else if (arry[i-1]=='R' && arry[i+1]=='S')
			{
				replace(arry[i],'L');
				remove(arry[i-1]);
				remove(arry[i+1]);
			}
			else if (arry[i-1]=='L' && arry[i+1]=='R ')
			{
				replace(arry[i],'U');
				remove(arry[i-1]);
				remove(arry[i+1]);
			}
			else{}
		}
	}
}

void MazeSolver::maze_runner()
{
	if( _pinA1 > threshold || _pinA5 > threshold )
	{
		if (arry[j] == 'L')
		{
			motorcontrol.left();
			j++;
		}
		else if (arry[j] == 'R')
		{
			motorcontrol.right();
			j++;
		}
		else if (arry[j] == 'S')
		{
			motorcontrol.straight();
			j++;
		}
		else if (arry[j] == 'W')
		{
			motorcontrol.stop();
			led_blink();
		}
		else
		{}
	}
	else if ( _pinA1 < threshold && _pinA2 > threshold && _pinA3 > threshold && _pinA4 > threshold && _pinA5 < threshold )
	{
		motorcontrol.straight();
	}
	else
	{}
}
