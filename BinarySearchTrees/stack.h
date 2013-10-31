/*Author: David Johnston
Class: CSI-281-01
Assignment: pa 3
Date Assigned: 9/12/13
Due Date: 9/19/13 - 12:30
Description: The purpose of this program is to recieve a infix epression,
turn it into a postfix operation and calculate it.
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/

#ifndef STACK_H
#define STACK_H
#define NULL 0

#include <iostream>
#include "node.h"

using namespace std;

const int STACK_NOT_FOUND = -1;

template<class T>
class Stack
{
private:
	Node<T>* mHead;
	Node<T>* mTail;
	int  mCount;

public:
	Stack();
	~Stack();

	int getCount();
	T getData(int index);
	int getIndex(T searchKey);

	void clear();
	void display();
	bool isEmpty();
	bool isExist(T searchKey);
	T pop();
	void push(T data);
};


/*      Pre:  None
 *     Post:  This object is initialized using the default
 *  Purpose:  To initialize the object
 *****************************************************************************/
template<class T>
Stack<T>::Stack()
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
Stack<T>::~Stack()
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
int Stack<T>::getCount()
{
	return mCount;
}

/*      Pre:  The list is instantiated and the index is valid
 *     Post:  The data in the specified index is returned to the caller
 *  Purpose:  To retrieve the specified nodes in the list
 *****************************************************************************/
template<class T>
T Stack<T>::getData(int index)
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
int Stack<T>::getIndex(T searchKey)
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
void Stack<T>::clear()
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

/*      Pre:  The list is instantiated
 *     Post:  The entire list is displayed on the screen
 *  Purpose:  To show the content of the list
 *****************************************************************************/
template<class T>
void Stack<T>::display()
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

/*      Pre:  The stack is instantiated 
 *     Post:  The function returns true is the list is empty; false otherwise
 *  Purpose:  To determine if the list is empty
 *****************************************************************************/
template<class T>
bool Stack<T>::isEmpty()
{
	return mHead == NULL;
}

/*      Pre:  The stack is instantiated and the searchKey is available
 *     Post:  The function returns true if the search key is found; false otherwise 
 *  Purpose:  To determine if a specific value exists in the list or not
 *****************************************************************************/
template<class T>
bool Stack<T>::isExist(T searchKey)
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

/*      Pre:  The list is instantiated and the searchKey is available
 *     Post:  The top of the stack is removed and the data therein is returned
 *  Purpose:  To remove the top of the stack
 *****************************************************************************/
template<class T>
T Stack<T>::pop()
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

/*      Pre:  The list is instantiated and the data is available
 *     Post:  The data is inserted in the top of the stack
 *  Purpose:  To insert data into the top of the stack
 *****************************************************************************/
template<class T>
void Stack<T>::push(T data)
{
	Node<T>* newNode;

	newNode = new Node<T>(data);

	newNode->mNext = mHead;
	mHead = newNode;

	mCount++;
}

#endif STACK_H