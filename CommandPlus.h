/**
* Header file for the CommandPlus class.
@file CommandPlus.h
*/
#pragma once
#include<conio.h>
#include<vector>
#include"point.h"
#include"Editor.h"

using namespace std;
class CommandPlus {
private:
	char command{};
	Point location;
	string value;

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

	void setValue(const string& _value);

	string getValue();

	void setLocation(const Point& _location);

	int getYLocation();

	int getXLocation();
};
