/** 
@purpose A text-editor.
@file main.cpp
@input A text file.
@output a display of the text file that was input*/

#include<iostream>
#include"Editor.h"
#include<memory>

using namespace std;

int main(int argc, const char * argv[])
{
	// argv[] reads in from the command line.
	if (argc < 1)
	{
		cerr << "argc is less than 1.\n";
			exit(1);
	}

	Editor miniVi(argv[1]);
	system("CLS"); // clears screen
	miniVi.run();
}