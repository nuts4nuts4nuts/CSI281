template<class T>
int sequentialSearch(T list[], int numItems, T& searchKey)
{
	int index = -1;
	int i = 0;

	while(i < numItems && index == -1)
	{
		if(searchKey == list[i])
		{
			index = i;
		}
		i++;
	}

	return index;
}

template<class T>
int binarySearch(T list[], int upperBound, T searchKey)
{
	int index = -1;
	int lowerBound = 0;
	int mid;

	while(lowerBound <= upperBound && index == -1)
	{
		mid = (lowerBound + upperBound) / 2;

		if(searchKey > mid)
		{
			lowerBound = mid + 1;
		}
		else if(searchKey < mid)
		{
			upperBound = mid - 1;
		}
		else
		{
			index = mid;
		}
	}

	return index;
}

template<class T>
int binarySearch(T list[], int lowerBound, int upperBound, T searchKey)
{
	int index = -1;
	int mid;

	while(lowerBound <= upperBound && index == -1)
	{
		mid = (lowerBound + upperBound) / 2;

		if(searchKey > mid)
		{
			binarySearch(list, mid, upperBound, searchKey);
		}
		else if(searchKey < mid)
		{
			binarySearch(list, lowerBound, mid, searchKey);
		}
		else
		{
			index = mid;
		}
	}

	return index;
}