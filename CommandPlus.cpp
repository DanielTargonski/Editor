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

void CommandPlus::setDelText(const string& _delText)
{
	deletedText = _delText;
}

string CommandPlus::getDelText()
{
	return deletedText;
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