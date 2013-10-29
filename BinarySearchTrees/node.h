/*Author: David Johnston
Class: CSI-281-01
Assignment: pa 2
Date Assigned: 9/5/13
Due Date: 9/12/13 - 12:30
Description: The purpose of this program is to recieve two polynomials from the user and add them together using a linkedlist backbone.
Certification of Authenticity:
I certify that this assignment is entirely my own work, with collaboration from West Hall study group*/

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