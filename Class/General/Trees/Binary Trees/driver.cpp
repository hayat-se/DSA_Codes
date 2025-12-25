#include<iostream>
#include "Header.h"
using namespace std;


int main()
{
    BinaryTree b1(15);
    BT* b1Root = b1.getRoot();
    b1.setLeftNode(b1Root, 7);
    b1.setRightNode(b1Root, 20);

    BinaryTree b2(35);
    BT* b2Root = b2.getRoot();
    b2.setLeftNode(b2Root, 29);
    b2.setRightNode(b2Root, 40);

    BinaryTree mainTree(b1Root, b2Root, 25);
    BT* mainRoot = mainTree.getRoot();
    mainTree.preTraversal(mainRoot);
    cout<<"\n";
    mainTree.inTraversal(mainRoot);
    cout<<"\n";
    mainTree.postTraversal(mainRoot);

}