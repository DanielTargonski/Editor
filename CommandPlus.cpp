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

void CommandPlus::setCommand(const char _command)
{
	command = _command;
}

void CommandPlus::setValue(const string _value)
{
	value = _value;
}

string CommandPlus::getValue()
{
	return value;
}

void CommandPlus::setLocation(const Point& _location)
{
	location = _location;
}

int CommandPlus::getYLocation()
{
	return location.getY();
}

int CommandPlus::getXLocation()
{
	return location.getX();
}

void CommandPlus::setTrueIsChar()
{
	isChar = true;
}

bool CommandPlus::getBoolIsChar()
{
	return isChar;
}

void CommandPlus::setTrueIsString()
{
	isString = true;
}

bool CommandPlus::getBoolIsString()
{
	return isString;
}