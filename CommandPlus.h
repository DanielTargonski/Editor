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
	string deletedText;

public:
	// Default constructor.
	// Does nothing as of now.
	CommandPlus();

	/** Returns the command char.
	@pre  None.
	@post  Returns private member char "command".
	@return  returns the character of the private member "command" */
	char getCommand();

	/** Sets the command char by calling _getwch();
	@pre  None.
	@post  Private member command char is set. */
	void setCommand();

	/** Sets the string "deletedText"
	@pre  None.
	@post  Sets the private member "deletedText".
	@param _delText is a string that will set the private
	"deletedText" member. */
	void setDelText(const string& _delText);

	string getDelText();

	void setLocation(const Point& _location);

	int getYLocation();

	int getXLocation();
};
