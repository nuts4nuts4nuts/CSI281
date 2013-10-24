#include <string>

using namespace std;

/*template <class T>
void printArray(T array[], int size)
{
	for( int i = 0; i < size; i++ )
	{
		if( i == (size - 1) )
		{
			cout << array[i] << endl;
		}
		else
		{
			cout << array[i] << ", ";
		}
	}
}

template <class T1, class T2>
void swap(T1 &thing1, T2 &thing2)
{
	T1 temp;

	temp = thing1;
	thing1 = thing2;
	thing2 = temp;
}

template <class T1, class T2>
void swap(T1& thing1, T2& thing2, const int size)
{
	T1 temp[2] = {};

	for( int i = 0; i < size; i++ )
	{
		temp[i] = thing1[i];
		thing1[i] = thing2[i];
		thing2[i] = temp[i];
	}
}
*/
template <class T1>
T1 plus(T1& thing1, T1& thing2)
{
	T1 sum;
	sum = thing1 + thing2;
	return sum;
}

template <class T1, class T2, class T3>
T1 plus(T1& thing1, T2& thing2, T3& thing3)
{
	T1 sum;
	sum = thing1 + thing2 + thing3;
	return sum;
}