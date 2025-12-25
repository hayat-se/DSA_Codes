#include<iostream>
#include "Header.h"
using namespace std;


int main()
{
    BinaryTree b1(15);
    BT* b1Root = b1.getRoot();
    b1.setLeftNode(b1Root, 7);
    b1.setRightNode(b1Root, 20);
    // b1.inTraversal(b1Root);

    cout<<"\n";

    BinaryTree b2(35);
    BT* b2Root = b2.getRoot();
    b2.setLeftNode(b2Root, 29);
    b2.setRightNode(b2Root, 40);
    // b2.inTraversal(b2Root);

    BinaryTree b3(b1Root, b2Root, 25);
    BT* b3Root = b3.getRoot();
    b3.inTraversal(b3Root);
    cout<<"\n";
    b3.postTraversal(b3Root);
    cout<<"\n";
    b3.preTraversal(b3Root);

}