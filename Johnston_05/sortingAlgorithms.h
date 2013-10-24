#ifndef SORTING_ALGORITHMS
#define SORTING_ALGORITHMS

typedef bool (*Comparison)(int&, int&);

template<class T>
void swapElements(T& elementOne, T& elementTwo)
{
	T tempElement;

	tempElement = elementOne;
	elementOne = elementTwo;
	elementTwo = tempElement;
}

template<class T>
void bubbleSort(T list[], int size, Comparison comparison)
{
	bool swapped = true;

	while(swapped)
	{
		swapped = false;

		for(int i = 0; i < size - 1; i++)
		{
			if(comparison(list[i + 1], list[i]))
			{
				swapElements(list[i], list[i + 1]);

				swapped = true;
			}
		}
	}
}

template<class T>
void insertionSort(T list[], int size, Comparison comparison)
{
	T value;
	int j;

	for(int i = 1; i < size; i++)
	{
		value = list[i];
		j = i - 1;

		while(j >= 0 && comparison(value, list[j]))
		{
			list[j + 1] = list[j];
			j = j--;
		}

		list[j + 1] = value;
	}
}

template<class T>
void selectionSort(T list[], int size, Comparison comparison)
{
	int minIndex;

	for(int i = 0; i < size - 1; i++)
	{
		minIndex = i;

		for(int j = i + 1; j < size; j++)
		{
			if(comparison(list[j], list[minIndex]))
			{
				minIndex = j;
			}
		}

		if(minIndex != i)
		{
			swapElements(list[i], list[minIndex]);
		}
	}
}

template<class T>
void shellSort(T list[], int size, Comparison comparison)
{
	int gap = size / 2;

	while(gap > 0)
	{
		for(int i = 0; i < size - gap; i++)
		{
			if(comparison(list[i + gap], list[i]))
			{
				swapElements(list[i], list[i + gap]);
			}
		}

		gap = gap / 2;
	}

	bubbleSort(list, size, comparison);
}

template<class T>
void mergeSort(T list[], int lowerBound, int upperBound, Comparison comparison)
{
	int mid;

	if(lowerBound < upperBound)
	{
		mid = (lowerBound + upperBound) / 2;
		mergeSort(list, lowerBound, mid, comparison);
		mergeSort(list, mid + 1, upperBound, comparison);
		merge(list, lowerBound, mid, upperBound, comparison);
	}
}

template<class T>
void merge(T list[], int& lowerBound, int& mid, int& upperBound, Comparison comparison)
{
	int size1 = mid - lowerBound + 1;
	int size2 = upperBound - mid;

	T* tmp1 = new T[size1 + 1];
	T* tmp2 = new T[size2 + 2];

	int i;
	for(i = 0; i < size1; i++)
	{
		tmp1[i] = list[lowerBound + i];
	}

	int j;
	for(j = 0; j < size2; j++)
	{
		tmp2[j] = list[mid + j + 1];
	}

	if(comparison == ascending)
	{
		tmp1[i] = INT_MAX;
		tmp2[j] = INT_MAX;
	}
	else
	{
		tmp1[i] = INT_MIN;
		tmp2[j] = INT_MIN;
	}

	i = 0;
	j = 0;

	for(int k = lowerBound; k <= upperBound; k++)
	{
		if(comparison(tmp1[i], tmp2[j]))
		{
			list[k] = tmp1[i];
			i++;
		}
		else
		{
			list[k] = tmp2[j];
			j++;
		}
	}

	tmp1 = NULL;
	tmp2 = NULL;
	delete[] tmp1;
	delete[] tmp2;
}

template<class T>
void quickSort(T list[], int lowerBound, int upperBound, Comparison comparison)
{
	int i = lowerBound;
	int j = upperBound;

	Comparison negComparison;
	if( comparison == ascending)
	{
		negComparison = descending;
	}
	else
	{
		negComparison = ascending;
	}

	T pivot = list[(lowerBound + upperBound) / 2];

	while(i <= j)
	{
		while(comparison(list[i], pivot))
		{
			i++;
		}

		while(negComparison(list[j], pivot))
		{
			j--;
		}

		if(i <= j)
		{
			swapElements(list[i], list[j]);
			i++;
			j--;
		}
	}

	if(lowerBound < j)
	{
		quickSort(list, lowerBound, j, comparison);
	}

	if(i < upperBound)
	{
		quickSort(list, i, upperBound, comparison);
	}
}

template<class T>
bool ascending(T& x, T& y)
{ 
	return x < y; 
}

template<class T>
bool descending(T& x, T& y)
{
	return x > y;
}

#endif SORTING_ALGORITHMS