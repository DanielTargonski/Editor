/**
The Editor class currently reads from the Command line
a text fileName and outputs it in the console.
Commands:
h or left arrow key: Move left
l or right arrow key: Move right
j or down arrow key: Move down
k or up arrow key: Move up
q: Exits the editor.
x: Delete character.
dd: Delete's line the cursor position is on.
u: Undo last deletion.

@file Editor.h
*/

#pragma once
#include"LinkedList.h"
#include"point.h"
#include<string>
#include<fstream>
#include<Windows.h>
#include"CommandPlus.h"
#include"LinkedStack.h"
#include"BinarySearch.h"
#include<sstream>

using namespace std;

class Editor {
private:
	// Each node in lines stores a string.
	LinkedList<string> lines;
	// Stack that saves deleted text.
	LinkedStack<class CommandPlus> undoSt;
	// User Position (uPos), Keeps track of where the cursor is.
	Point uPos;

	// List holding all keywords to be colored
	string keyWords[60];

	const char QUIT = 'q';
	const int ESCAPE = 27;
	const int ENTER{ 13 };

public:
	// Does nothing for now.
	Editor();

	/** Opens a file from the passed string and creates the list
	@param filename string, takes in a
	@Pre  The passed string must be the name of a file and in the directory
	@Post  A list is created from the file that was passed as a string parameter */
	Editor(string fileName);

	/** displays everything in lines
	 @Pre  The list must not be empty.
	 @Post  The list is output to the console. */
	void displayLines();

	//WIP
	void displayLines2();

	/** Moves cursor down.
	@pre  There must be text below current location of cursor.
	@post  The cursor moves down one position.*/
	void moveDown();

	/** Moves the cursor up.
	@pre  There must be text above current location of cursor.
	@post  The cursor moves up one position.*/
	void moveUp();

	/** Moves the cursor to the left.
	@pre  There must be text to the left of current location of cursor.
	@post  The cursor moves one position to the left.*/
	void moveLeft();

	/** Moves the cursor to the right.
	@pre  There must be text to the right of the cursor.
	@post  The cursor moves one position to the right.
	*/
	void moveRight();

	/** Delete character that cursor is on.
	@pre  User cursor must be on a char or empty space
	@post  The char in the string is deleted and pushed
	onto the LinkedStack.
	*/
	void deleteChar();

	/** Deletes line that cursor is on.
	@pre  Cursor is on a line.
	@post  Line is deleted and pushed into the undo stack.
	*/
	void deleteLine();

	/** Runs the editor.
	@pre  None.
	@post  The editor begins running and allows you
	to move a cursor around the text.
	*/
	void run();

	/** Undo previous deletion.
	@pre  Something must've been deleted.
	@post  Inserts deleted char/string back into lines.
	*/
	void undo();

	void colorText(int value);

	void InsertMode();

	template<typename T>
	void selectionSort(T arr[], int size);

	void outputToFile(string arr[], int size, ostream& outData);

	void makeKeywordArray(string keywordArr[], int size, ifstream& inData);
};
