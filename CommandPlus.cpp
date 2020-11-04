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

void CommandPlus::setValue(const std::string& _value)
{
	value = _value;
}

void CommandPlus::setLocation(const Point& _locations)
{
	locations.push_back(_locations);
}