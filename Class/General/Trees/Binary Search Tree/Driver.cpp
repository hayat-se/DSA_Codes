#include<iostream>
#include "BinarySearchTree.h"
using namespace std;


int main()
{
    BST b1;
    b1.insertItem(7);
    b1.insertItem(29);
    b1.insertItem(40);
    b1.insertItem(15);
    b1.insertItem(20);
    b1.insertItem(25);
    b1.insertItem(35);

    Node* b1Root = b1.getRoot();

    b1.preTraversal(b1Root);
    cout<<"\n";
    b1.inTraversal(b1Root);
    cout<<"\n";
    b1.postTraversal(b1Root);

}