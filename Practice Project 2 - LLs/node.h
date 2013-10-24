/*Author: David Johnston
Class: CSI-281-01
Assignment: pa 3
Date Assigned: 9/12/13
Due Date: 9/19/13 - 12:30
Description: The purpose of this program is to recieve a infix epression,
turn it into a postfix operation and calculate it.
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/

#ifndef NODE_H
#define NODE_H

template<class T>
struct Node
{
public:
	Node()
	{
		mData = T();
		mNext = NULL;
	}

	Node( const T& data)
	{
		mData = data;
		mNext = NULL;
	}

	T mData;
	Node<T>* mNext;
};

#endif NODE_H