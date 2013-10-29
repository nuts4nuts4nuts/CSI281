/*Author: David Johnston
Class: CSI-281-01
Assignment: pa 3
Date Assigned: 9/12/13
Due Date: 9/19/13 - 12:30
Description: The purpose of this program is to recieve a infix epression,
turn it into a postfix operation and calculate it.
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/

#ifndef QUEUE_H
#define QUEUE_H
#define NULL 0

#include <iostream>
#include "node.h"

using namespace std;

const int QUEUE_NOT_FOUND = -1;

template<class T>
class Queue
{
private:
	Node<T>* mHead;
	Node<T>* mTail;
	int  mCount;

public:
	Queue();
	~Queue();

	int getCount();
	T getData(int index);
	int getIndex(T searchKey);

	void clear();
	T dequeue();
	void display();
	void enqueue(T data);
	bool isEmpty();
	bool isExist(T searchKey);
};


/*      Pre:  None
 *     Post:  This object is initialized using the default
 *  Purpose:  To initialize the object
 *****************************************************************************/
template<class T>
Queue<T>::Queue()
{
	mHead = NULL;
	mTail = NULL;
	mCount = 0;
}

/*      Pre:  None
 *     Post:  All the nodes in the list is deleted
 *  Purpose:  To remove all the nodes in the list 
 *****************************************************************************/
template<class T>
Queue<T>::~Queue()
{
	Node<T>* tmp;
	Node<T>* toBeDeleted;
	tmp = mHead;

	// removing node by node
	while (tmp != NULL)
	{
		toBeDeleted = tmp;
		tmp = tmp->mNext;
		toBeDeleted->mNext = NULL;

		delete toBeDeleted;
	}

	// reinitialize the pointers
	mHead = NULL;
	mTail = NULL;
}

/*      Pre:  The object is instantiated
 *     Post:  The number of nodes in the linked list is returned to the caller
 *  Purpose:  To retrieve the number of nodes in the list
 *****************************************************************************/
template<class T>
int Queue<T>::getCount()
{
	return mCount;
}

/*      Pre:  The list is instantiated and the index is valid
 *     Post:  The data in the specified index is returned to the caller
 *  Purpose:  To retrieve the specified nodes in the list
 *****************************************************************************/
template<class T>
T Queue<T>::getData(int index)
{
	int  i;
	Node<T>* tmp;

	tmp = mHead;
	for (i = 0; i < index; i++)
	{
		tmp = tmp->mNext;
	}

	return tmp->mData;
}

/*      Pre:  The list is instantiated and the searchKey is available
 *     Post:  The function returns the index location of the found item.  If 
 *            the item is not found, the functions returns LINKED_LIST_NOT_FOUND,
 *            which is -1
 *  Purpose:  To retrieve the index of the specified search key
 *****************************************************************************/
template<class T>
int Queue<T>::getIndex(T searchKey)
{
	bool found = false;
	Node<T>* tmp;
	int  i = 0;
   
	tmp = mHead;
	while (tmp != NULL && !found)
	{
		if (tmp->mData == searchKey)
		{
			found = true;
		}
		else if (tmp->mData > searchKey)
		{
			tmp = NULL;
		}
		else
		{
			tmp = tmp->mNext;
		}
		
		i++;
	}

	if (!found)
	{
		return LINKED_LIST_NOT_FOUND;
	}
	else
	{
		return i;
	}
}

/*      Pre:  None
 *     Post:  All the nodes in the list is deleted
 *  Purpose:  To reset the list
 *****************************************************************************/
template<class T>
void Queue<T>::clear()
{
	if(mHead != NULL)
	{
		Node<T>* pCurr = mHead;
		Node<T>* pPrev;

		while( pCurr->mNext != NULL )
		{
			pPrev = pCurr;
			pCurr = pCurr->mNext;

			delete pPrev;
			pPrev = NULL;
		}

		//Delete the last node
		mHead = NULL;
		delete pCurr;
		pCurr = NULL;

	}
}

/*      Pre:  The list is instantiated and the searchKey is available
 *     Post:  
 *  Purpose:  To remove a specific value from the list
 *****************************************************************************/
template<class T>
T Queue<T>::dequeue()
{
	Node<T>* headNode = mHead;
	T data = mHead->mData;

	if (mHead == mTail)
	{
		delete mHead;
		mHead = NULL;
		mTail = NULL;
	}
	else
	{
		mHead = headNode->mNext;

		headNode->mNext = NULL;
		delete headNode;
		headNode = NULL;
	}

	mCount--;

	return data;
}

/*      Pre:  The list is instantiated
 *     Post:  The entire list is displayed on the screen
 *  Purpose:  To show the content of the list
 *****************************************************************************/
template<class T>
void Queue<T>::display()
{
	Node<T>* tmp;

	if (mHead == NULL)
	{
		cout << "The list is empty\n";
		return;
	}

	tmp = mHead;
	while (tmp != NULL)
	{
		cout << tmp->mData << " ";
		tmp = tmp->mNext;
	}
	cout << endl;
}

/*      Pre:  The list is instantiated and the data is available
 *     Post:  The data is inserted in the top of the Queue
 *  Purpose:  To insert data into the top of the Queue
 *****************************************************************************/
template<class T>
void Queue<T>::enqueue(T data)
{
	Node<T>* newNode;
	Node<T>* tailNode = mTail;

	newNode = new Node<T>(data);

	if(mHead == NULL)
	{
		mHead = newNode;
		mTail = newNode;
	}
	else
	{
		mTail = newNode;
		tailNode->mNext = newNode;
	}

	mCount++;
}

/*      Pre:  The list is instantiated 
 *     Post:  The function returns true is the list is empty; false otherwise
 *  Purpose:  To determine if the list is empty
 *****************************************************************************/
template<class T>
bool Queue<T>::isEmpty()
{
	return mHead == NULL;
}

/*      Pre:  The list is instantiated and the searchKey is available
 *     Post:  The function returns true if the search key is found; false otherwise 
 *  Purpose:  To determine if a specific value exists in the list or not
 *****************************************************************************/
template<class T>
bool Queue<T>::isExist(T searchKey)
{
	bool found = false;
	Node<T>* tmp;
	int  i = 0;
   
	tmp = mHead;
	while (tmp != NULL && !found)
	{
		if (tmp->mData == searchKey)
		{
			found = true;
		}
		else if (tmp->mData > searchKey)
		{
			tmp = NULL;
		}
		else
		{
			tmp = tmp->mNext;
		}
         
		i++;
	}

	return found;
}

#endif QUEUE_H