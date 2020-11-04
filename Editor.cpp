/** Implementation file for the "Editor" class.
@file Editor.cpp
*/

#include"Editor.h"

void placeCursorAt(Point coordinate) {
	COORD coord;
	coord.X = coordinate.getX();
	coord.Y = coordinate.getY();
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord);
} // end placeCursorAt

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
			throw invalid_argument("File failed to opened.");
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

void Editor::moveDown()
{
	// Checks if the current Y position is less than the number of lines
	// in the list subtract 1 from getLength because the Y position is always
	// 1 less than the list line number. Also checks to see if the current
	// 'x' position is less than or equal to the length of the string below it.
	if (uPos.getY() < lines.getLength() - 1)
	{
		// set x to last char in line under current line
		if (uPos.getX() >= lines.getEntry(uPos.getY() + 2).length())
			uPos.setX(lines.getEntry(uPos.getY() + 2).length() - 1);
		if (uPos.getX() < 0)
			uPos.setX(0);

		uPos.setY(uPos.getY() + 1);
		placeCursorAt(uPos);
	} // end if
} // end moveDown()

void Editor::moveUp()
{
	if (uPos.getY() > 0)
	{
		// Sets 'x' coordinate to last char in the string above current line
		if (uPos.getX() >= lines.getEntry(uPos.getY()).length())
			uPos.setX(lines.getEntry(uPos.getY()).length() - 1);
		if (uPos.getX() < 0)
			uPos.setX(0);

		uPos.setY(uPos.getY() - 1);
		placeCursorAt(uPos);
	} // end if
} // end moveUp()

void Editor::moveLeft()
{
	if (uPos.getX() > 0)
	{
		uPos.setX(uPos.getX() - 1);
		placeCursorAt(uPos);
	} // end if
} // end moveLeft()

void Editor::moveRight()
{	// Checks if current 'x' position is less than the length of the current
	// line so as not to go past last character in the string.
	if (uPos.getX() < lines.getEntry(uPos.getY() + 1).length() - 1
		&& lines.getEntry(uPos.getY() + 1).length() > 0)
	{
		uPos.setX(uPos.getX() + 1);
		placeCursorAt(uPos);
	} // end if
} // end moveRight()

void Editor::deleteChar()
{
	CommandPlus cmd;

	undoSt.push(lines.getEntry(uPos.getY()+1).substr(uPos.getX(), 1));
	// replace the string and displaylines again
	lines.replace(uPos.getY()+1, lines.getEntry(uPos.getY() + 1).erase(uPos.getX(), 1));
	
	if (uPos.getX() > 0)
	uPos.setX(uPos.getX() - 1);

	system("CLS"); // clears screen
	displayLines();
} // end deleteChar()

void Editor::deleteLine()
{
	undoSt.push(lines.getEntry(uPos.getY() + 1));
	lines.remove(uPos.getY() + 1);

	system("CLS"); // clears screen
	displayLines();
} // end deleteLine()

void Editor::run()
{
	const char QUIT = 'q';
	const int ESCAPE = 27;
	unsigned int count{};
	CommandPlus cmd;

	// Keeps program running while users does not enter 'q' or ESC
	// Allows user to enter certain commands to move cursor around txt file
	while (cmd.getCommand() != QUIT && cmd.getCommand() != ESCAPE)
	{
		cmd.setCommand();
		switch (cmd.getCommand())
		{
		case 'j':
		case 80: // up arrow key 
			moveDown();
			count = 0;
			break;
		case 'k':
		case 72: // down arrow key
			moveUp();
			count = 0;
			break;
		case 'l':
		case 77: // right arrow key
			moveRight();
			count = 0;
			break;
		case 'h':
		case 75: // left arrow key
			moveLeft();
			count = 0;
			break;
		case 'x':
			deleteChar();
			count = 0;
			break;
		case 'd':
			count++;
			if (count == 2) {
				deleteLine();
				count = 0;
			}
			break;
		case QUIT:
			exit(1);
			break;
		case ESCAPE:
			exit(1);
			break;
		default:
			count = 0;
			break;
		}
	} // end while
} // end run()