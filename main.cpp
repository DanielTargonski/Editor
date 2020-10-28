/** 
@purpose Making a text-editor.
@file main.cpp
@input A text file.
@output a display of the text file that was input*/

#include<iostream>
#include"Editor.h"
#include<memory>

using namespace std;

void main(int argc, const char * argv[])
{
	string fileName("sample.txt");
	Editor miniVi(fileName);
	miniVi.displayLines();
	miniVi.run();
}