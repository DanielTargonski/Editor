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

//old displayLines()
//void Editor::displayLines()
//{
//	int position;
//	for (position = 1; position <= lines.getLength(); position++)
//		cout << lines.getEntry(position) << "\n";
//
//	placeCursorAt(uPos);
//} // end displayLines

template<typename TYPE>
int Editor::binarySearch(TYPE anArray[], int first, int last, TYPE target)
{
	int index;
	if (first > last)
		index = -1; // target not in original array
	else
	{
		// If target is in anArray, anArray[first] <= target <= anArray[last]
		int mid = first + (last - first) / 2;
		if (target == anArray[mid])
			index = mid; // target found at anArray[mid]
		else if (target < anArray[mid])
			// Point X
			index = binarySearch(anArray, first, mid - 1, target);
		else
			// Point Y
			index = binarySearch(anArray, mid + 1, last, target);
	}  // end if

	return index;
}  // end binarySearch

void Editor::displayLines()
{
	system("CLS");
	int position;
	string nextLine, nextWord, line{};

	for (position = 1; position <= lines.getLength(); position++)
	{
		nextLine = lines.getEntry(position);

		int i = 0;
		while (i < nextLine.length()) {
			string word;
			// isolate a word at a time (can contain underscores)
			if (isalpha(nextLine[i])) {
				while (isalpha(nextLine[i]) || nextLine[i] == '_') {
					word += nextLine[i];
					i++;
				}
				if (keywordBST.contains(word) != 1)
					colorText(1);
				else
					colorText(0);
				cout << word;
			}

			else {
				colorText(0);
				cout << nextLine[i];
				i++;
			}
		}

		cout << endl;
	}
	placeCursorAt(uPos);
} // end displayLines

void Editor::saveFile()
{
	ofstream outLines(textFile);
	int position;
	for (position = 1; position <= lines.getLength(); position++)
		outLines << lines.getEntry(position) << "\n";
}

Editor::Editor()
{
} // end Editor()

Editor::Editor(string _textFileName, const string _keyWordsFilename)
{
	ifstream inFile(_textFileName);
	string temp;
	textFile = _textFileName;
	ifstream inKeyWords(_keyWordsFilename);
	fillBST(keywordBST, inKeyWords);

	int lineCounter = 1;

	//make sure file opened correctly
	try
	{
		if (inFile.fail())
			throw invalid_argument("File failed to opened.");
	}
	catch (const invalid_argument& invArg)
	{
		cout << invArg.what() << endl <<
			"Please check the file name for accuracy and ensure it's in "
			<< "the proper directory.\n";
		exit(1);
	} // end try-catch

	// Loop reads a line into the "temp" string and
	// inserts it into the back of the ADT list "lines".
	while (!inFile.eof())
	{
		getline(inFile, temp);
		lines.insert(lineCounter, temp);
		lineCounter++;
	} // end while

	inFile.close();
	inKeyWords.close();

} // end Editor

void Editor::moveToEndOfConsole()
{
	uPos.setY(lines.getLength() - 1);
	if (lines.getEntry(uPos.getY() + 1).length() - 1 >= 0)
		uPos.setX(lines.getEntry(uPos.getY() + 1).length());
	else
		uPos.setX(0);

	placeCursorAt(uPos);
}

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
} // end moveDown

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
} // end moveUp

void Editor::moveLeft()
{
	if (uPos.getX() > 0)
	{
		uPos.setX(uPos.getX() - 1);
		placeCursorAt(uPos);
	} // end if
} // end moveLeft()

void Editor::moveRight()
{
	if (insert_mode)
	{
		if (uPos.getX() < lines.getEntry(uPos.getY() + 1).length()
			&& lines.getEntry(uPos.getY() + 1).length() > 0)
		{
			uPos.setX(uPos.getX() + 1);
			placeCursorAt(uPos);
		}
	}
	// Checks if current 'x' position is less than the length of the current
	// line so as not to go past last character in the string.
	if (uPos.getX() < lines.getEntry(uPos.getY() + 1).length() - 1
		&& lines.getEntry(uPos.getY() + 1).length() > 0)
	{
		uPos.setX(uPos.getX() + 1);
		placeCursorAt(uPos);
	} // end if
} // end moveRight

void Editor::deleteChar()
{
	if (lines.getEntry(uPos.getY() + 1).length() > 0)
	{
		CommandPlus cmd;
		cmd.setTrueIsChar(); // sets isChar to true so we know how to undo this.
		cmd.setValue(lines.getEntry(uPos.getY() + 1).substr(uPos.getX(), 1));
		cmd.setLocation(uPos);
		undoSt.push(cmd);
	} // end if

	// replace the string and displaylines again
	lines.replace(uPos.getY() + 1, lines.getEntry(uPos.getY() + 1).erase(uPos.getX(), 1));

	// Update x position.
	if (uPos.getX() > 0)
		uPos.setX(uPos.getX() - 1);

	system("CLS"); // clears screen
	displayLines();
} // end deleteChar

void Editor::deleteLine()
{
	bool removed = false;
	CommandPlus cmd;
	cmd.setTrueIsString(); // sets isString to true.
	cmd.setValue(lines.getEntry(uPos.getY() + 1));
	cmd.setLocation(uPos);
	undoSt.push(cmd);

	// This prevents the last node from being deleted;
	// instead replacing it with an empty string.
	if (lines.getLength() == 1)
	{
		lines.replace(1, "");
		removed = true;
	} // end if

	// When deleting a line, the Y-coord should be decremented so to prevent
	// the cursor from being on an empty line.
	if (uPos.getY() > 0 && !removed)
	{
		lines.remove(uPos.getY() + 1);
		uPos.setY(uPos.getY() - 1);
		removed = true;
	} // end if
	if (!removed)
		lines.remove(uPos.getY() + 1);

	// If the x position is greater than the length of the new line
	// then put the cursor position to the last char of the line.
	// If the line is empty (a "" string) then set 'x' coord to 0.
	if (lines.getEntry(uPos.getY() + 1).length() > 0)
		uPos.setX(lines.getEntry(uPos.getY() + 1).length() - 1);
	else
		uPos.setX(0);

	system("CLS"); // clears screen
	displayLines();
} // end deleteLine

void Editor::undo()
{
	CommandPlus tempCmd;
	if (!undoSt.isEmpty())
	{
		tempCmd = undoSt.peek();
		undoSt.pop();
		// If we are undoing a string deletion then we insert it back
		// to where it was deleted and display the lines again.
		if (tempCmd.getBoolIsString() == true)
			lines.insert(tempCmd.getYLocation() + 1, tempCmd.getValue());

		// Else, we are restoring a character, which requires the string
		// to be replaced with the character in the exact place it originally was.
		else
		{
			lines.replace(tempCmd.getYLocation() + 1,
				lines.getEntry(tempCmd.getYLocation() + 1).insert(tempCmd.getXLocation(), tempCmd.getValue()));
			// This increments the x position as you are undoing as long as
			// the length of the line is longer than the x position.
			// We only want to increment 'x' if we're undoing chars, which is why it's inside this
			// else statement.
			if (uPos.getX() < lines.getEntry(uPos.getY() + 1).length() - 1)
				uPos.setX(uPos.getX() + 1);
		}

		// This stops the x cursor from going out of bounds
		if (uPos.getX() >= lines.getEntry(uPos.getY() + 1).length())
			uPos.setX(lines.getEntry(uPos.getY() + 1).length() - 1);
		//This stops the x-coord from going negative.
		if (uPos.getX() < 0)
			uPos.setX(0);

		system("CLS"); // clears screen
		displayLines();
	} // end if
} // end undo

void Editor::InsertMode()
{
	CommandPlus tmpCommand;
	tmpCommand.setValue(lines.getEntry(uPos.getY() + 1));
	undoSt.push(tmpCommand);

	char userInput{};

	while (true)
	{
		// Get user input
		userInput = _getch();

		if (userInput == ESCAPE)
		{
			// Reset cursor if past length
			if (uPos.getX() > lines.getEntry(uPos.getY() + 1).length() - 1)
			{
				uPos.setX(uPos.getX() - 1);
				placeCursorAt(uPos);
			}
			insert_mode = false;
			break;
		}

		// WIP
		if (userInput == ENTER)
		{
			string first_half{ lines.getEntry(uPos.getY() + 1).substr(0, uPos.getX()) };
			string second_half{ lines.getEntry(uPos.getY() + 1).substr(uPos.getX()) };

			// Replace the node cursor is at with new string
			lines.replace(uPos.getY() + 1, first_half);

			// Insert new node next to cursor node with new string
			lines.insert(uPos.getY() + 2, second_half);

			// New coordinate
			uPos.setX(0);
			uPos.setY(uPos.getY() + 1);

			system("CLS"); // clears screen
			displayLines();
			continue;
		}

		// WIP
		// TRYING TO USE ARROW KEYS ON INSERT MODE

		//switch (userInput)
		//{
		//case -32: // down arrow key
		//	moveDown();
		//	continue;
		//case 72: // up arrow key
		//	moveUp();
		//	break;
		//case 77: // right arrow key
		//	moveRight();
		//	break;
		//case 75: // left arrow key
		//	moveLeft();
		//	break;
		//}

		// Replace new node with modified string
		lines.replace(uPos.getY() + 1, lines.getEntry(uPos.getY() + 1).insert(uPos.getX(), 1, userInput));

		system("CLS"); // clears screen
		displayLines();

		tmpCommand.setValue(lines.getEntry(uPos.getY() + 1));
		undoSt.push(tmpCommand);

		// Fix and move to new position
		uPos.setX(uPos.getX() + 1);
	}
}

void Editor::colorText(int value)
{
	COORD coord;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	FlushConsoleInputBuffer(hConsole);

	SetConsoleTextAttribute(hConsole, value + 240);
}

void Editor::exitWithoutSaving()
{
	int lengthOfLines = lines.getLength();
	for (int i = 0; i < lengthOfLines / 5 + 1; i++)
		cout << "\n\n\n\n\n";
	exit(1);
}

void Editor::createSpace()
{
	for (int i = 0; i < lines.getLength() / 5 + 1; i++)
		cout << "\n\n\n\n\n";
}

void Editor::fillBST(BinarySearchTree<string>& aBST, ifstream& inData)
{
	string tempWord;
	while (inData.good())
	{
		inData >> tempWord;
		aBST.add(tempWord);
	}

}

void Editor::run()
{
	displayLines();

	bool run{ true };
	int lengthOfLines{};
	unsigned int count{};
	CommandPlus cmd;
	const int upArrowKey = 72;
	const int downArrowKey = 80;
	const int rightArrowKey = 77;
	const int leftArrowKey = 75;

	// Keeps program running while users does not enter ':q'
	// Allows user to enter certain commands to move cursor around txt file
	while (run)
	{
		Point semi(1, lines.getLength() + 3);
		cmd.setCommand();
		switch (cmd.getCommand())
		{
		case 'j':
		case downArrowKey: // down arrow key
			moveDown();
			count = 0;
			break;
		case 'k':
		case upArrowKey: // up arrow key
			moveUp();
			count = 0;
			break;
		case 'l':
		case rightArrowKey: // right arrow key
			moveRight();
			count = 0;
			break;
		case 'h':
		case leftArrowKey: // left arrow key
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
		case 'u':
			undo();
			count = 0;
			break;
		case 'i':
			insert_mode = true;
			InsertMode();
			count = 0;
			break;
		case ':':
			placeCursorAt(semi);
			cout << ":";
			cmd.setCommand();
			cout << cmd.getCommand();
			if (cmd.getCommand() == ',')
				moveToEndOfConsole();
			else if (cmd.getCommand() == 'q')
				exitWithoutSaving();
			else if (cmd.getCommand() == 'w')
				saveFile();

			displayLines();
			count = 0;
			break;
		default:
			count = 0;
			break;
		} // end switch
	} // end while

	// Creates space so that the text doesn't get obstructed by the
	// closing of terminal message.
	createSpace();
} // end run