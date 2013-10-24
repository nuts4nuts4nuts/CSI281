#include <stdlib.h>
#include <time.h>
#include <string>
#include "header.h"
#include "sortingAlgorithms.h"

using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	string fileNameArray[4] = {"ints_10.txt", "ints_100.txt", "ints_1000.txt", "ints_10000.txt"};

	createIntDataSets(fileNameArray);

	for(int i = 1; i <= 3; i++)
	{
		cout << "\n\nBubble Sort, please wait...";
		evaluateSort(fileNameArray, BubbleSort, i);
		cout << "\n\nInsertion Sort, hopefully slightly faster...";
		evaluateSort(fileNameArray, InsertionSort, i);
		cout << "\n\nSelection Sort, pretty much the same...";
		evaluateSort(fileNameArray, SelectionSort, i);
		cout << "\n\nShell Sort, now we're getting somewhere (at least practically...)";
		evaluateSort(fileNameArray, ShellSort, i);
		cout << "\n\nMerge Sort, here we go, divide and conquer! (hope you have a lot of memory...)";
		evaluateSort(fileNameArray, MergeSort, i);
		cout << "\n\nQuick Sort, don't blink!";
		evaluateSort(fileNameArray, QuickSort, i);
		createIntDataSets(fileNameArray);
	}
	return 0;
}