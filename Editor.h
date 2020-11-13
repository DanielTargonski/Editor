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
	// Holds key words to be highlighted.
	string keyWords[60];

	const char QUIT = 'q';
	const int ESCAPE = 27;
	const int ENTER{ 13 };
	bool insert_mode{ false };

public:

	// Does nothing for now.
	Editor();

	/** Opens a file from the passed string and creates the list
	@param  filename string, takes in the name of the file to open.
	@param  _keyWords[] string array, sends a sorted list of keywords to the editor class.
	@param  size int, The size of the _keyWords[] array parameter.
	@Pre  The passed string must be the name of a file and in the directory
	@Post  A list is created from the file that was passed as a string parameter */
	Editor(string fileName, const string _keyWords[], int size);

	/** displays everything in lines
	 @Pre  The list must not be empty.
	 @Post  The list is output to the console. */
	void displayLines();

	//WIP
	void displayLines2();

	/** Moves cursor down. Command 'j'
	@pre  There must be text below current location of cursor.
	@post  The cursor moves down one position.*/
	void moveDown();

	/** Moves the cursor up. Command: 'k'
	@pre  There must be text above current location of cursor.
	@post  The cursor moves up one position.*/
	void moveUp();

	/** Moves the cursor to the left. Command 'h'
	@pre  There must be text to the left of current location of cursor.
	@post  The cursor moves one position to the left.*/
	void moveLeft();

	/** Moves the cursor to the right. Command: 'l'
	@pre  There must be text to the right of the cursor.
	@post  The cursor moves one position to the right.
	*/
	void moveRight();

	/** Delete character that cursor is on. Command: 'x'
	@pre  User cursor must be on a char or empty space
	@post  The char in the string is deleted and pushed
	onto the LinkedStack.
	*/
	void deleteChar();

	/** Deletes line that cursor is on. Command: 'dd'
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

	/** Undo previous deletion. Command 'u'
	@pre  Something must've been deleted.
	@post  Inserts deleted char/string back into lines.
	*/
	void undo();

	/** Colors a string
	@param  value int, changes color depending on int passed.*/
	void colorText(int value);

	void InsertMode();

	/** Moves cursor to end of console with command ":,"
	@pre  none.
	@post  (x,y) coords are set to match the last char at the 
	bottom of the list location.
	*/
	void moveToEndOfConsole();

	/** Exits program without saving to file. Command ":q"
	@pre  none
	@post  Depends on where it is called.
	@return  returns a 'q'.
	*/
	char exitWithoutSaving();

};
