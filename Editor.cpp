//@file Editor.cpp

#include"Editor.h"

void placeCursorAt(Point coordinate) {
	COORD coord;
	coord.X = coordinate.getX();
	coord.Y = coordinate.getY();
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord);
}

void Editor::displayLines()
{
	int position;
	for (position = 1; position <= lines.getLength(); position++)
		cout << lines.getEntry(position) << "\n";

	placeCursorAt(uPos);

} // end displayLines()

Editor::Editor()
{
} // end Editor()

Editor::Editor(string fileName)
{
	ifstream inFile(fileName);
	string temp;
	int lineCounter = 1;

	//make sure file opened correctly
	try
	{
		if (inFile.fail())
		{
			throw invalid_argument("File failed to opened.");
		} // end if
	} // end try
	catch (const invalid_argument& invArg)
	{
		cout << invArg.what() << endl <<
			"Please check the file name for accuracy and ensure it's in "
			<< "the proper directory.\n";
		exit(1);
	} // end catch

	// Loop reads a line into the "temp" string and
	// inserts it into the back of the ADT list "lines".
	while (!inFile.eof())
	{
		getline(inFile, temp);
		lines.insert(lineCounter, temp);
		lineCounter++;
	} // end while
} // end Editor(string fileName)

// Moves the cursorPositiion down by 1
// @pre 
// @post
void Editor::moveDown()
{
	if (uPos.getY() < lines.getLength()-1 && uPos.getX() <= lines.getEntry(uPos.getY() + 1).length())
	{
		// set x to last char in line under current line
		if (uPos.getX() > lines.getEntry(uPos.getY()+2).length())
			uPos.setX(lines.getEntry(uPos.getY()+2).length() - 1);

		uPos.setY(uPos.getY() + 1);
		placeCursorAt(uPos);
	}
}

void Editor::moveUp()
{
	if (uPos.getY() > 0)
	{
		// set x to last char in the string above
		if (uPos.getX() > lines.getEntry(uPos.getY()).length())
			uPos.setX(lines.getEntry(uPos.getY()).length() - 1);

		uPos.setY(uPos.getY() - 1);
		placeCursorAt(uPos);
	}
}

void Editor::moveLeft()
{
	if (uPos.getX() > 0)
	{
		uPos.setX(uPos.getX() - 1);
		placeCursorAt(uPos);
	}
}

void Editor::moveRight()
{
	if (uPos.getX() < lines.getEntry(uPos.getY()+1).length()-1)
	{
		uPos.setX(uPos.getX() + 1);
		placeCursorAt(uPos);
	}
}

void Editor::run()
{
	const char QUIT = 'q';
	const int ESCAPE = 27;
	CommandPlus cmd;

	while (cmd.getCommand() != QUIT)
	{
		cmd.setCommand();
		switch (cmd.getCommand())
		{
		case 'j':
			moveDown();
			//placeCursorAt(uPos);
			break;
		case 'k':
			moveUp();
			//placeCursorAt(uPos);
			break;
		case 'l':
			moveRight();
			//placeCursorAt(uPos);
			break;
		case 'h':
			moveLeft();
			//placeCursorAt(uPos);
			break;
		default:
			break;
		} 
	}
}