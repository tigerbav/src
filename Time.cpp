#include "Time.h"
#include <iostream>
void Time::showTime()
{
	++seconds;
	if (seconds >= 60)
		++minutes;
}
int Time::returnS()
{
	return seconds;
}
int Time::returnM()
{
	return minutes;
}