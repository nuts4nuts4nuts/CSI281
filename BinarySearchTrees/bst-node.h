/* ***       Author:  Wei Kian Chen
     *  Last Update:  September 4, 2013
     *        Class:  CSI-281
     *     Filename:  node.h
     *
     *  Description:
     *      This is the template node definition.
     *  
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my own work.
     **********************************************************************/

#ifndef BST_NODE_H
#define BST_NODE_H

#include <iostream>

using namespace std;

template <class T>
struct BST_Node
{
   T           mData;
   BST_Node<T> *mLeft, *mRight;

   /*      Pre:  None
    *     Post:  This object is initialized using default values
    *  Purpose:  To intialize date object
    *************************************************************************/
   BST_Node()
   {
      mData = T();
      mLeft = NULL;
      mRight = NULL;
   }


   /*      Pre:  None
    *     Post:  This object is initialized using specified data
    *  Purpose:  To intialize date object, and left and right are NULL
    *************************************************************************/
   BST_Node(T data)
   {
      mData = data;
      mLeft = NULL;
      mRight = NULL;
   }


   /*      Pre:  None
    *     Post:  This object is initialized using specified data
    *  Purpose:  To intialize date object, left and right are not NULL
    *************************************************************************/
   BST_Node(T data, BST_Node<T> *left, BST_Node<T> *right)
   {
      mData = data;
      mLeft = left;
      mRight = right;
   }
};




#endif