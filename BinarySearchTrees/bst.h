#ifndef _BST_H
#define _BST_H

#include <iostream>
#include "bst-node.h"

using namespace std;

template <class T>
class BST
{
	private:
		BST_Node<T> *mRootNode;

		BST(T data, BST_Node<T> *left, BST_Node<T> *right);

		void destroySubtree(BST_Node<T> *node);
		void displayInOrder(BST_Node<T> *node);
		void displayPreOrder(BST_Node<T> *node);
		void displayPostOrder(BST_Node<T> *node);
		void insert(BST_Node<T> *&node, T data);
		void makeDeletion(BST_Node<T> *&node);
		void remove(BST_Node<T> *&node, T searchKey);

	public:
		BST();
		~BST();

		void insert(T data);
      bool isEmpty();
		bool isExists(T searchKey);
		void remove(T searchKey);
		void showInOrder();
		void showPreOrder();
		void showPostOrder();
};


template <class T>
BST<T>::BST()
{
	mRootNode = NULL;
}


template <class T>
BST<T>::BST(T data, BST_Node<T> *left = NULL, BST_Node<T> *right = NULL)
{
   BST_Node<T> *newNode;

   newNode = new BST_Node(data, left, right);
   if (newNode != NULL)
	   mRootNode = newNode;
}


template <class T>
BST<T>::~BST()
{
	destroySubtree(mRootNode);
}


template <class T>
void BST<T>::destroySubtree(BST_Node<T> *node)
{
}


template <class T>
void BST<T>::displayInOrder(BST_Node<T> *node)
{
}


template <class T>
void BST<T>::displayPreOrder(BST_Node<T> *node)
{
}


template <class T>
void BST<T>::displayPostOrder(BST_Node<T> *node)
{
}


template <class T>
void BST<T>::insert(T data)
{
	insert(mRootNode, data);
}


template <class T>
void BST<T>::insert(BST_Node<T> *&node, T data)
{
	BST_Node<T> *newNode;

	newNode = new BST_Node(data);

	if(data > node->mData)
	{
		if(node->mData == NULL)
		{
			//node->mRight =
		}
	}
}


template <class T>
bool BST<T>::isEmpty()
{
   return (mRootNode == NULL);
}


template <class T>
bool BST<T>::isExists(T searchKey)
{
}


template <class T>
void BST<T>::makeDeletion(BST_Node<T> *&node)
{
}


template <class T>
void BST<T>::remove(BST_Node<T> *&node, T searchKey)
{
	if (node == NULL)
		return;
	else if (node->mData > searchKey)
		remove(node->mLeft, searchKey);
	else if (node->mData < searchKey)
		remove(node->mRight, searchKey);
	else
		// We have found the node to delete.
		makeDeletion(node);
}


template <class T>
void BST<T>::remove(T searchKey)
{
	remove(mRootNode, searchKey);
}


template <class T>
void BST<T>::showInOrder()
{
	displayInOrder(mRootNode);
}


template <class T>
void BST<T>::showPreOrder()
{
	displayPreOrder(mRootNode); 
}


template <class T>
void BST<T>::showPostOrder()
{
	displayPostOrder(mRootNode);
}


#endif