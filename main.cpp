/**
@purpose This is a simplified vi editor.
@file main.cpp
@input A text file.
@output a display of the text file that was input*/

#include<iostream>
#include"Editor.h"

using namespace std;

int main(int argc, const char* argv[])
{
	int numberOfCmdLineArgs = 0;

	// argv[] reads in from the command line.
	if (argc < 1)
	{
		cerr << "argc is less than 1.\n";
		exit(1);
	}

	//if user specifies 2 parameters then read in argv[2]
	Editor miniVi(argv[1], argv[2]);

	system("CLS"); // clears screen
	miniVi.run();
}