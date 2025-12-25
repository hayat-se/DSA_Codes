#include<iostream>
#include "LinkedList.h"
using namespace std;


int main()
{
    LinkedList list1, list2, finalList; 
    // finalList is Used for storing the final concatinated LinkedList

    // Adding elements to 1nd List
    list1.insertAtStart(1);
    list1.insertAtEnd(2);
    list1.insertAtEnd(3);
    list1.insertAtEnd(4);
    list1.insertAtEnd(5);


    // Adding elements to 2nd List
    list2.insertAtStart(6); 
    list2.insertAtEnd(3);
    list2.insertAtEnd(8);
    list2.insertAtEnd(9);
    list2.insertAtEnd(10);


    list1.concateList(list2);
    list1.displayList();


}