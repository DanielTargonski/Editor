/** 
@purpose Making a text-editor.
@file main.cpp
@input A text file.
@output a display of the text file that was input*/

#include<iostream>
#include"Editor.h"
#include<memory>

using namespace std;

int main()
{
	string fileName("sample.txt");
	Editor miniVi(fileName);
	miniVi.displayLines();

	shared_ptr<LinkedList<string>> smartPtr(new LinkedList<string>());
	auto spList = make_shared<LinkedList<string>>();

} 