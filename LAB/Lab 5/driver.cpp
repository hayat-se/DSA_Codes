#include<iostream>
#include "linkedList.h"
using namespace std;


int main()
{
    LinkedList list;
    list.insertAtStart(5);
    list.insertAtStart(10);
    list.insertAtStart(20);
    list.insertAtStart(60);
    list.insertAtStart(30);
    list.insertAfter(6,10);
    list.removeFromStart();
    list.displayLinkedList();
    int x;
    list.removeFromEnd(x);
    cout<<"\nDeleted Value : "<<x <<"\n";
    list.displayLinkedList();
}