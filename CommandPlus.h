/**
* Header file for the CommandPlus class.
@file CommandPlus.h
*/
#pragma once
#include<conio.h>
#include <vector>
#include "point.h"

class CommandPlus {
private:
	char command{};
	std::vector<Point> locations;
	std::string value;
public:
	// Default constructor.
	// Does nothing as of now.
	CommandPlus();

	/** Returns the command char.
	@pre  None.
	@post  Returns private member char "command".
	*/
	char getCommand();

	/** Sets the command char by calling _getwch();
	@pre  None.
	@post  Private member command char is set.
	*/
	void setCommand();

	void setLocation(const Point& _locations);
	void setValue(const std::string& _value);
};
