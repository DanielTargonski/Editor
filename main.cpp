/** 
@purpose A text-editor.
@file main.cpp
@input A text file.
@output a display of the text file that was input*/

#include<iostream>
#include"Editor.h"
#include<memory>

using namespace std;

void selectionSort(string arr[], int size);

void outputToFile(string arr[], int size, ostream& outData);

void makeKeywordArray(string keywordArr[], int size, ifstream& inData);

int main(int argc, const char * argv[])
{
	const int keywordSize = 60;
	string keywords[keywordSize];
	ifstream inKeywords("keywords.txt");
	string keyword;
	ofstream outKeywords("keywords.txt");

	makeKeywordArray(keywords, keywordSize, inKeywords);
	selectionSort(keywords, keywordSize);
	outputToFile(keywords, keywordSize, outKeywords);

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

void outputToFile(string arr[], int size, ostream& outData)
{
	for (int i = 0; i < size; i++)
	{
		outData << arr[i] << "\n";
	}
}

void selectionSort(string arr[], int size)
{
	int curString{}, nextString;
	for (curString = 0; curString < size; curString++)
	{
		nextString = curString + 1;
		while (arr[curString] >= arr[nextString])
		{
			swap(arr[curString], arr[nextString]);
		} // end while
	} // end for
} // end selectionSortFile

void makeKeywordArray(string keywordArr[], int size, ifstream& inData)
{
	int i = 0;
	while (!inData.eof())
	{
		inData >> keywordArr[i];
		i++;
	}
}