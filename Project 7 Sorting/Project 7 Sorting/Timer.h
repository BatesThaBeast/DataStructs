/*
Class:			Timer
Author:			Dr. Glenn Stevenson
Description:	This class is used to monitor how much time elapses as a sort is performed. **All designed by Dr. Glenn Stevenson**
*/
#pragma once
#include <windows.h>

class Timer
{
private:
	LARGE_INTEGER start;
	LARGE_INTEGER stop;
	LARGE_INTEGER freq;
	double PCFreq;
	__int64 CounterStart;

public:
	Timer();
	void startTimer();
	void stopTimer();
	double getMilli();
	double getSeconds();
	double getMicro();

};
