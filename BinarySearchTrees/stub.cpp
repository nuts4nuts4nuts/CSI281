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

   cout << "Number of nodes: ";
   cout << tree.nodesCount();
   cout << endl;

   cout << "Number of leaves: ";
   cout << tree.leavesCount();
   cout << endl;

   cout << "Height of tree: ";
   cout << tree.getHeight();
   cout << endl;

   system("pause");

   return 0;
}