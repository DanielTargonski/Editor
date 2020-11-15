/**
* Header file for the CommandPlus class.
@file CommandPlus.h
*/
#pragma once
#include<conio.h>
#include"point.h"
#include"Editor.h"

using namespace std;
class CommandPlus {
private:
	char command{};
	Point location;
	string value;
	bool isChar{ false }, isString{ false };

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

	/** Sets the command to the passed paramter.
	@param  _command char, sets private member command.
	@pre  None.
	@post  Command char is set. */
	void setCommand(const char _command);

	/** Sets the string "deletedText"
	@pre  None.
	@post  Sets the private member "value".
	@param _delText is a string that will set the private
	"deletedText" member. */
	void setValue(const string _value);

	/** Getter method for private member "deletedText".
	@pre There must be something stored in the deletedText string.
	@post None.
	@return Returns the string stored in the private member "deletedText". */
	string getValue();

	/** Saves the (x,y) pair into the private "location" Point object.
	@pre None.
	@post The (x,y) position of the user is saved into private Point
	object member "location".
	@param _location Takes in the current users (x,y) coordinates. */
	void setLocation(const Point& _location);

	/** Getter method to return the Y coord in private member "location".
	@pre None.
	@post None.
	@return Returns the 'y' coordinate stored in private member "location". */
	int getYLocation();

	/** Getter method to retrieve the X coordinate in private member "location".
	@pre None.
	@post None.
	@return Returns the 'x' coordinate stored in private member "location". */
	int getXLocation();

	/** Sets bool isChar to true;
	@pre  None.
	@post  bool isChar is set to true. */
	void setTrueIsChar();

	/** Returns bool value of isChar.
	@pre  None.
	@post  None.
	@return  Bool value of isChar.*/
	bool getBoolIsChar();

	/** Sets bool isString to true.
	@pre  None.
	@post  bool isString is set to true.*/
	void setTrueIsString();

	/** Returns bool value of isString.
	@pre  None.
	@post  None.
	@return  Returns bool value of isString. */
	bool getBoolIsString();
};