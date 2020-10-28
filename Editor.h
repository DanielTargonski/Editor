//@file Editor.h

#pragma once
#include"LinkedList.h"
#include"point.h"
#include<string>
#include<fstream>
#include<Windows.h>
#include"CommandPlus.h"

using namespace std;

class Editor {
private:
	LinkedList<string> lines;
	// Keep track of where the cursor is
	Point uPos;

public:
	Editor();

	// Opens a file from the passed string and creates the list
	//@param filename string, takes in a 
	// @Pre: The passed string must be the name of a file and in the directory
	// @Post: A list is created from the file that was passed as a string parameter
	Editor(string fileName);

	// displays everything in lines
	// Precondition: The list must not be empty.
	// Postcondition: The list is output to the console.
	void displayLines();

	void moveDown();

	void moveUp();

	void moveLeft();

	void moveRight();

	void run();



};
