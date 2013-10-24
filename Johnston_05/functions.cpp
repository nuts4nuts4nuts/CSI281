#include <iostream>
#include "header.h"
#include "timerSystem.h"

const int SIZE1 = 10,
		  SIZE2 = 100,
		  SIZE3 = 1000,
		  SIZE4 = 10000;

// creates the data sets
void createIntDataSets(string fileNameArray[])
{
	ofstream outStream;
	int i;
	int j;

	// Creates data set of SIZE 10
	outStream.open(fileNameArray[0]);

	for(i = 0; i < 10; i++)
	{
		outStream << (rand() % 10001) << " ";
	}

	outStream.close();

	//Creates data set of SIZE 100
	outStream.open(fileNameArray[1]);

	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			outStream << (rand() % 10001) << " ";
		}
		
		outStream << endl;
	}

	outStream.close();

	//Creates data set of SIZE 1,000
	outStream.open(fileNameArray[2]);

	for(i = 0; i < 100; i++)
	{
		for(j = 0; j < 10; j++)
		{
			outStream << (rand() % 10001) << " ";
		}

		outStream << endl;
	}

	outStream.close();

	//Creates data set of SIZE 10,000
	outStream.open(fileNameArray[3]);

	for(i = 0; i < 1000; i++)
	{
		for(j = 0; j < 10; j++)
		{
			outStream << (rand() % 10001) << " ";
		}

		outStream << endl;
	}

	outStream.close();
}

//Evaluates the speed of a sorting algorithm on 4 lists and outputs the results
void evaluateSort(string fileNameArray[], SortType sort, int numRuns)
{
	TimerSystem timer;

	int upperBound1 = SIZE1 - 1,
		upperBound2 = SIZE2 - 1,
		upperBound3 = SIZE3 - 1,
		upperBound4 = SIZE4 - 1;

	int array1[SIZE1];
	int array2[SIZE2];
	int array3[SIZE3];
	int array4[SIZE4];

	populateArrayFromFile(fileNameArray[0], array1, SIZE1);
	populateArrayFromFile(fileNameArray[1], array2, SIZE2);
	populateArrayFromFile(fileNameArray[2], array3, SIZE3);
	populateArrayFromFile(fileNameArray[3], array4, SIZE4);

	string fileString;
	string sortName;
	ofstream outStream;

	void (*pLinSort)(int[], int, Comparison) = NULL;
	void (*pDandCSort)(int[], int, int, Comparison) = NULL;

	if(sort == BubbleSort)
	{
		pLinSort = &bubbleSort;
		fileString = "BubbleSort.txt";
	}
	else if(sort == InsertionSort)
	{
		pLinSort = &insertionSort;
		fileString = "InsertionSort.txt";
	}
	else if(sort == SelectionSort)
	{
		pLinSort = &selectionSort;
		fileString = "SelectionSort.txt";
	}
	else if(sort == ShellSort)
	{
		pLinSort = &shellSort;
		fileString = "ShellSort.txt";
	}
	else if(sort == QuickSort)
	{
		pDandCSort = &quickSort;
		fileString = "QuickSort.txt";
	}
	else if(sort == MergeSort)
	{
		pDandCSort = &mergeSort;
		fileString = "MergeSort.txt";
	}
	
	sortName = fileString;
	sortName.erase(fileString.length() - 4, 4);

	if(numRuns == 1)
	{
		outStream.open(fileString, ios::trunc);
		outStream << sortName << " Evaluation: \n\n";
	}
	else
	{
		outStream.open(fileString, ios::app);
	}

	if(pLinSort)
	{
		outStream << "\nRun " << numRuns << ":\n";

		outStream << "\nRandom Numbers: \n";
		timer.startClock();
		pLinSort(array1, SIZE1, ascending);
		outStream << sortName << " took " << timer.getTime() << " seconds to sort an array of size " << SIZE1 << ".\n";

		timer.startClock();
		pLinSort(array2, SIZE2, ascending);
		outStream << sortName << " took " << timer.getTime() << " seconds to sort an array of size " << SIZE2 << ".\n";

		timer.startClock();
		pLinSort(array3, SIZE3, ascending);
		outStream << sortName << " took " << timer.getTime() << " seconds to sort an array of size " << SIZE3 << ".\n";

		timer.startClock();
		pLinSort(array4, SIZE4, ascending);
		outStream << sortName << " took " << timer.getTime() << " seconds to sort an array of size " << SIZE4 << ".\n";

		outStream << "\nBest Case: \n";
		timer.startClock();
		pLinSort(array1, SIZE1, ascending);
		outStream << sortName << " took " << timer.getTime() << " seconds to sort an array of size " << SIZE1 << ".\n";

		timer.startClock();
		pLinSort(array2, SIZE2, ascending);
		outStream << sortName << " took " << timer.getTime() << " seconds to sort an array of size " << SIZE2 << ".\n";

		timer.startClock();
		pLinSort(array3, SIZE3, ascending);
		outStream << sortName << " took " << timer.getTime() << " seconds to sort an array of size " << SIZE3 << ".\n";

		timer.startClock();
		pLinSort(array4, SIZE4, ascending);
		outStream << sortName << " took " << timer.getTime() << " seconds to sort an array of size " << SIZE4 << ".\n";

		outStream << "\nWorst Case: \n";
		timer.startClock();
		pLinSort(array1, SIZE1, descending);
		outStream << sortName << " took " << timer.getTime() << " seconds to sort an array of size " << SIZE1 << ".\n";

		timer.startClock();
		pLinSort(array2, SIZE2, descending);
		outStream << sortName << " took " << timer.getTime() << " seconds to sort an array of size " << SIZE2 << ".\n";

		timer.startClock();
		pLinSort(array3, SIZE3, descending);
		outStream << sortName << " took " << timer.getTime() << " seconds to sort an array of size " << SIZE3 << ".\n";

		timer.startClock();
		pLinSort(array4, SIZE4, descending);
		outStream << sortName << " took " << timer.getTime() << " seconds to sort an array of size " << SIZE4 << ".\n";
	}
	else
	{
		outStream << "\nRun " << numRuns << ":\n";

		outStream << "\nRandom Numbers: \n";
		timer.startClock();
		pDandCSort(array1, 0, upperBound1, ascending);
		outStream << sortName << " took " << timer.getTime() << " seconds to sort an array of size " << SIZE1 << ".\n";

		timer.startClock();
		pDandCSort(array2, 0, upperBound2, ascending);
		outStream << sortName << " took " << timer.getTime() << " seconds to sort an array of size " << SIZE2 << ".\n";

		timer.startClock();
		pDandCSort(array3, 0, upperBound3, ascending);
		outStream << sortName << " took " << timer.getTime() << " seconds to sort an array of size " << SIZE3 << ".\n";

		timer.startClock();
		pDandCSort(array4, 0, upperBound4, ascending);
		outStream << sortName << " took " << timer.getTime() << " seconds to sort an array of size " << SIZE4 << ".\n";

		outStream << "\nBest Case: \n";
		timer.startClock();
		pDandCSort(array1, 0, upperBound1, ascending);
		outStream << sortName << " took " << timer.getTime() << " seconds to sort an array of size " << SIZE1 << ".\n";

		timer.startClock();
		pDandCSort(array2, 0, upperBound2, ascending);
		outStream << sortName << " took " << timer.getTime() << " seconds to sort an array of size " << SIZE2 << ".\n";

		timer.startClock();
		pDandCSort(array3, 0, upperBound3, ascending);
		outStream << sortName << " took " << timer.getTime() << " seconds to sort an array of size " << SIZE3 << ".\n";

		timer.startClock();
		pDandCSort(array4, 0, upperBound4, ascending);
		outStream << sortName << " took " << timer.getTime() << " seconds to sort an array of size " << SIZE4 << ".\n";

		outStream << "\nWorst Case: \n";
		timer.startClock();
		pDandCSort(array1, 0, upperBound1, descending);
		outStream << sortName << " took " << timer.getTime() << " seconds to sort an array of size " << SIZE1 << ".\n";

		timer.startClock();
		pDandCSort(array2, 0, upperBound2, descending);
		outStream << sortName << " took " << timer.getTime() << " seconds to sort an array of size " << SIZE2 << ".\n";

		timer.startClock();
		pDandCSort(array3, 0, upperBound3, descending);
		outStream << sortName << " took " << timer.getTime() << " seconds to sort an array of size " << SIZE3 << ".\n";

		timer.startClock();
		pDandCSort(array4, 0, upperBound4, descending);
		outStream << sortName << " took " << timer.getTime() << " seconds to sort an array of size " << SIZE4 << ".\n";
	}
}