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

	placeCursorAt(cursorPosition);

} // end displayLines()

Editor::Editor()
{
} // end Editor()

Editor::Editor(string fileName) throw(invalid_argument)
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
	// inserts it into the ADT list into a new pos.
	while (!inFile.eof())
	{
		getline(inFile, temp);
		lines.insert(lineCounter, temp);
		lineCounter++;
	} // end while
} // end Editor(string fileName)
