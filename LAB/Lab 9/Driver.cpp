#include<iostream>
#include "Header.h"
using namespace std;


int main()
{
    BinarySearchTree bt;
    for(int i=0 ; i<7; i++)
    {
        int val;
        cout<<"Enter Value : ";
        cin>>val;
        bt.InsertItem(val);
    }

    cout<<"Tree : \n";
    bt.PrintTree();
}