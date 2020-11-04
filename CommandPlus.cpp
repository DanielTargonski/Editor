/**
* Implementation file for the CommandPlus class.
@file CommandPlus.cpp
*/
#include"CommandPlus.h"

using namespace std;

CommandPlus::CommandPlus()
{
}

char CommandPlus::getCommand()
{
	return command;
}

void CommandPlus::setCommand()
{
	command = _getwch();
}

void CommandPlus::setValue(const string& _value)
{
	value = _value;
}

void CommandPlus::setLocation(const Point& _location)
{
	location.push_back(_location);
}