/*Author: David Johnston
Class: CSI-281-01
Assignment: pa 6
Date Assigned: 10/24/13
Due Date: 10/31/13 - 12:30
Description: The purpose of this program is to show off some functionality of binary search trees.
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/

#include <iostream>
#include "bst.h"

using namespace std;

int main()
{
   BST<int> tree;

   cout << "Inserting:  5\n";
   tree.insert(5);

   cout << "Inorder:  ";
   tree.showInOrder();
   cout << endl;

   cout << "Preorder:  ";
   tree.showPreOrder();
   cout << endl;

   cout << "Postorder:  ";
   tree.showPostOrder();
   cout << endl;

   cout << "***\n";

   cout << "Inserting:  8\n";
   tree.insert(8);

   cout << "Inorder:  ";
   tree.showInOrder();
   cout << endl;

   cout << "Preorder:  ";
   tree.showPreOrder();
   cout << endl;

   cout << "Postorder:  ";
   tree.showPostOrder();
   cout << endl;

   cout << "***\n";

   cout << "Inserting:  3\n";
   tree.insert(3);

   cout << "Inorder:  ";
   tree.showInOrder();
   cout << endl;

   cout << "Preorder:  ";
   tree.showPreOrder();
   cout << endl;

   cout << "Postorder:  ";
   tree.showPostOrder();
   cout << endl;

   cout << "***\n";

   cout << "Inserting:  12\n";
   tree.insert(12);

   cout << "Inorder:  ";
   tree.showInOrder();
   cout << endl;

   cout << "Preorder:  ";
   tree.showPreOrder();
   cout << endl;

   cout << "Postorder:  ";
   tree.showPostOrder();
   cout << endl;

   cout << "***\n";

   cout << "Inserting:  9\n";
   tree.insert(9);
   
   cout << "Inorder:  ";
   tree.showInOrder();
   cout << endl;

   cout << "Preorder:  ";
   tree.showPreOrder();
   cout << endl;

   cout << "Postorder:  ";
   tree.showPostOrder();
   cout << endl;

   cout << "***\n";

   cout << "Inserting: 1\n";
   tree.insert(1);

   cout << "Inorder:  ";
   tree.showInOrder();
   cout << endl;

   cout << "Preorder:  ";
   tree.showPreOrder();
   cout << endl;

   cout << "Postorder:  ";
   tree.showPostOrder();
   cout << endl;

   cout << "***\n";

   cout << "Inserting: 15\n";
   tree.insert(15);

   cout << "Inorder:  ";
   tree.showInOrder();
   cout << endl;

   cout << "Preorder:  ";
   tree.showPreOrder();
   cout << endl;

   cout << "Postorder:  ";
   tree.showPostOrder();
   cout << endl;

   cout << "***\n";

   cout << "Number of nodes: ";
   cout << tree.nodesCount();
   cout << endl;

   cout << "Number of leaves: ";
   cout << tree.leavesCount();
   cout << endl;

   cout << "Height of tree: ";
   cout << tree.getHeight();
   cout << endl;

   cout << "***\n";

   cout << "Path of tree to 9: ";
   tree.printPath(9);
   cout << endl;

   cout << "Path of tree to 10: ";
   tree.printPath(10);
   cout << endl;

   cout << "***\n";

   cout << "Breadth first search for 9: ";
   tree.bfs(9);
   cout << endl;

   cout << "Breadth first search for 10: ";
   tree.bfs(10);
   cout << endl;

   cout << "***\n";

   cout << "Depth first search for 9: ";
   tree.dfs(9);
   cout << endl;

   cout << "Depth first search for 10: ";
   tree.dfs(10);
   cout << endl;

   cout << "***\n";

   cout << "Display tree:\n";
   tree.showTree();

   system("pause");

   return 0;
}