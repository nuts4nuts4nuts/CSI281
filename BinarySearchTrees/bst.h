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
		void displayTree(BST_Node<T> *node, int tab);
		int getHeight(BST_Node<T> *node);
		void insert(BST_Node<T> *&node, const T &data);
		int leavesCount(BST_Node<T> *node);
		void makeDeletion(BST_Node<T> *&node);
		int nodesCount(BST_Node<T> *node);
		void remove(BST_Node<T> *&node, const T &searchKey);

	public:
		BST();
		~BST();

		bool bfs(T searchKey);
		bool dfs(T searchKey);
		int  getHeight();
		void insert(T data);
		bool isEmpty();
		bool isExists(T searchKey);
		int  leavesCount();
		int  nodesCount();
		void printPath(T searchKey);
		void remove(T searchKey);
		void showInOrder();
		void showPreOrder();
		void showPostOrder();
		void showTree();
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
bool BST<T>::bfs(T searchKey)
{
}


template <class T>
void BST<T>::destroySubtree(BST_Node<T> *node)
{
	if (node == NULL)
		return;

	destroySubtree(node->mLeft);
	destroySubtree(node->mRight);

	// Delete the node at the root.
	delete node;
}


template <class T>
bool BST<T>::dfs(T searchKey)
{
}


template <class T>
void BST<T>::displayInOrder(BST_Node<T> *node)
{
	if (node != NULL)
	{
		displayInOrder(node->mLeft);
		cout << node->mData << "  ";
		displayInOrder(node->mRight);
	}
}


template <class T>
void BST<T>::displayPreOrder(BST_Node<T> *node)
{
	if (node != NULL)
	{
		cout << node->mData << "  ";
		displayPreOrder(node->mLeft);		
		displayPreOrder(node->mRight);
	}
}


template <class T>
void BST<T>::displayPostOrder(BST_Node<T> *node)
{
	if (node != NULL)
	{
		displayPostOrder(node->mLeft);		
		displayPostOrder(node->mRight);
		cout << node->mData << "  ";
	 }
}


template <class T>
void BST<T>::displayTree(BST_Node<T> *node, int tab)
{
}


template <class T>
int BST<T>::getHeight()
{
	return getHeight(mRootNode) - 1;
}


template <class T>
int BST<T>::getHeight(BST_Node<T> *node)
{
	if (node == NULL)
	{
		return 0;
	}

  return 1 + max(getHeight(node->mLeft), getHeight(node->mRight));
}


template <class T>
void BST<T>::insert(T data)
{
	insert(mRootNode, data);
}


template <class T>
void BST<T>::insert(BST_Node<T> *&node, const T &data)
{
	// If the tree is empty, make a new node and make it 
	// the root of the tree.
	if (node == NULL)
	{ 
		node = new BST_Node<T>(data);
		return;
	}
		
	// If num is already in tree: return.
	if (node->mData == data)
	  return;

	// The tree is not empty: insert the new node into the
	// left or right subtree.
	if (data < node->mData)
		insert(node->mLeft, data);
	else
		insert(node->mRight, data);
}


template <class T>
bool BST<T>::isEmpty()
{
   return (mRootNode == NULL);
}


template <class T>
bool BST<T>::isExists(T searchKey)
{
	BST_Node<T> *tmp = mRootNode;

	while (tmp != NULL)
	{
		if (tmp->mData == searchKey)
			return true;
		else if (tmp->mData > searchKey)
			tmp = tmp->mLeft;
		else
			tmp = tmp->mRight;
	}
	return false;
}


template <class T>
int BST<T>::leavesCount()
{
	return leavesCount(mRootNode);
}


template <class T>
int BST<T>::leavesCount(BST_Node<T> *node)
{
	int leaveCount = 0;

	if(node->mRight == NULL && node->mLeft == NULL)
	{
		leaveCount++;
	}
	else
	{
		if(node->mRight != NULL)
		{
			leaveCount += leavesCount(node->mRight);
		}
		if(node->mLeft != NULL)
		{
			leaveCount += leavesCount(node->mLeft);
		}
	}

	return leaveCount;
}


template <class T>
void BST<T>::makeDeletion(BST_Node<T> *&node)
{
	// Used to hold node that will be deleted.
	BST_Node<T> *nodeToDelete = node; 
	
	// Used to locate the  point where the 
	// left subtree is attached.
	BST_Node<T> *attachPoint;          
				
	if (node->mRight == NULL)
	{
		  // Replace tree with its left subtree. 
		  node = node->mLeft;
	}            
	else if (node->mLeft == NULL)   	
	{
		  // Replace tree with its right subtree.
		  node = node->mRight;
	}  	
	else
	  //The node has two children
	{
		 // Move to right subtree.
		 attachPoint = node->mRight;

		 // Locate the smallest node in the right subtree
		 // by moving as far to the left as possible.
		 while (attachPoint->mLeft != NULL)
			 attachPoint = attachPoint->mLeft;

		 // Attach the left subtree of the original tree
		 // as the left subtree of the smallest node 
		 // in the right subtree.
		 attachPoint->mLeft = node->mLeft;

		 // Replace the original tree with its right subtree.
		 node = node->mRight;       
	  }

	 // Delete root of original tree
	 delete nodeToDelete;
}


template <class T>
int BST<T>::nodesCount()
{
	return nodesCount(mRootNode);
}


template <class T>
int BST<T>::nodesCount(BST_Node<T> *node)
{
	int nodeCount = 0;
	if (node != NULL)
	{
		nodeCount = 1 + nodesCount(node->mLeft) + nodesCount(node->mRight);
    }

    return nodeCount;
}


template <class T>
void BST<T>::printPath(T searchKey)
{

}


template <class T>
void BST<T>::remove(BST_Node<T> *&node, const T &searchKey)
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


template <class T>
void BST<T>::showTree()
{
}

#endif