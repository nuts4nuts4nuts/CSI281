#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <iostream>
#include <fstream>
#include "sortingAlgorithms.h"

using namespace std;

enum SortType
{
	BubbleSort,
	InsertionSort,
	SelectionSort,
	ShellSort,
	QuickSort,
	MergeSort
};

void createIntDataSets(string fileNameArray[]);

void evaluateSort(string fileNameArray[], SortType sort, int numRuns);

//Populates an array from a file
template<class T>
void populateArrayFromFile(string fileName, T anArray[], int arraySize)
{
	ifstream inStream;
	inStream.open(fileName);

	for(int i = 0; i < arraySize; i++)
	{
		inStream >> anArray[i];
	}

	inStream.close();
}

#endif HEADER_H