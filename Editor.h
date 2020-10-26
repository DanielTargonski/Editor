//@file Editor.h

#pragma once
#include"LinkedList.h"
#include"point.h"
#include<string>
#include<fstream>
#include<Windows.h>

using namespace std;

class Editor {
private:
	LinkedList<string> lines;
	// Keep track of where the cursor is
	Point cursorPosition;

public:
	Editor();

	// insert the string
	Editor(string fileName) throw(invalid_argument);

	// displays everything in lines
	void displayLines();

};
