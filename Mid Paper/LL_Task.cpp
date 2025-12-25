#include<iostream>
#include "Header.h"
using namespace std;



int main()
{
    LinkedList list;
    list.insertSorted("hayat", 3);
    list.insertSorted("haider", 1);
    list.insertSorted("abd", 6);
    list.displayStudents();
    list.deleteNode(2);
    cout<<"after delete\n";
    list.displayStudents();

}