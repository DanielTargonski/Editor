/**
@purpose A text-editor.
@file main.cpp
@input A text file.
@output a display of the text file that was input*/

#include<iostream>
#include"Editor.h"
#include<memory>

using namespace std;

/** Finds the largest item in an array.
@pre  The size of the array is >= 1.
 @post  The arguments are unchanged.
 @param theArray  The given array.
 @param size  The number of elements in theArray.
 @return  The index of the largest entry in the array. */
template < typename Type>
int findIndexOfLargest(const Type theArray[], int size);

/** Sorts  the items in an array into ascending order.
@pre  None.
 @post  The array is sorted into ascending order; the size of the array
	is unchanged.
@param theArray  The array to sort.
 @param n  The size of theArray. */
template <typename Type>
void selectionSort(Type theArray[], int n);

void outputToFile(const string arr[], int size, ostream& outData);

void makeKeywordArray(string keywordArr[], int size, ifstream& inData);

int main(int argc, const char* argv[])
{
	string keyWords[60];
	ifstream inKeywords("keywords.txt");
	int numberOfCmdLineArgs = 0;

	makeKeywordArray(keyWords, 60, inKeywords);

	// argv[] reads in from the command line.
	if (argc < 1)
	{
		cerr << "argc is less than 1.\n";
		exit(1);
	}

	//try
	//{
	//	cout << "How many command line arguments are you passing?\n";
	//	cin >> numberOfCmdLineArgs;
	//	if (numberOfCmdLineArgs < 1)
	//		throw invalid_argument("User entered less than 1 cmd line argument.");
	//}
	//catch (const std::exception& invArg)
	//{
	//	while (numberOfCmdLineArgs < 1)
	//	{
	//		cout << invArg.what() << '\n' << "You must pass at least 1 argument.\n";
	//		cout << "How many command line arguments are you passing?\n";
	//		cin >> numberOfCmdLineArgs;
	//	}
	//}

	//if user specifies 2 parameters then read in argv[2]
	Editor miniVi(argv[1], keyWords, 60);

	system("CLS"); // clears screen
	miniVi.run();
}

void outputToFile(const string arr[], int size, ostream& outData)
{
	for (int i = 0; i < size; i++)
	{
		outData << arr[i] << "\n";
	}
}

template <typename TYPE>
int findIndexOfLargest(const TYPE theArray[], int size)
{
	int indexSoFar = 0; // Index of largest entry found so far
	for (int currentIndex = 1; currentIndex < size; currentIndex++)
	{
		// At this point, theArray[indexSoFar] >= all entries in
			// theArray[0..currentIndex − 1]
		if (theArray[currentIndex] > theArray[indexSoFar])
			indexSoFar = currentIndex;
	}  // end for

	return indexSoFar; // Index of largest entry
}  // end findIndexOfLargest

void makeKeywordArray(string keywordArr[], int size, ifstream& inData)
{
	int i = 0;
	string newWord;
	while (inData.good())
	{
		//getline(inData, keywordArr[i]);
		inData >> keywordArr[i];
		i++;
	}
}

template <typename Type>
void selectionSort(Type theArray[], int n)
{
	// last = index of the last item in the subarray of items yet
		 //        to be sorted;
		// largest = index of the largest item found
	for (int last = n - 1; last >= 1; last--)
	{
		// At this point, theArray[last+1..n–1] is sorted, and its
		   // entries are greater than those in theArray[0..last].
	   // Select the largest entry in theArray[0..last]
		int largest = findIndexOfLargest(theArray, last + 1);

		// Swap the largest entry, theArray[largest], with
		 // theArray[last]
		swap(theArray[largest], theArray[last]);
	}  // end for
}
