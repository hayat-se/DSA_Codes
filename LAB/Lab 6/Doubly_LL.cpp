#include<iostream>
#include "D_LinkedList.h"
using namespace std;

int main()
{
    D_LinkedList list;
    int ch;
    m:
    cout<<"1) Insert At Start\n2) Insert at Middle\n3) Insert at End \n4) Remove from start \n5) Remove from Middle \n6) Remove from End \n7) Display Node List\n\n";
    cout<<"Enter your Option : ";
    cin>>ch;

    switch (ch)
    {
    case 1:
    {
        int x;
        cout<<"Enter Number : ";
        cin>>x;
        list.insertAtStart(x);
        goto m;
        break;
    }
    case 2:
    {
        int x, loc;
        cout<<"Enter Number : ";
        cin>>x;
        cout<<"Enter target Number : ";
        cin>>loc;
        list.insertAtMiddle(x, loc);  
        goto m;
        break;
    }
    case 3:
    {
        int x;
        cout<<"Enter Number : ";
        cin>>x;
        list.insertAtEnd(x);
        goto m;
        break;
    }
    case 4:
    {
        int del;
        list.deleteFromStart(del);
        cout<<del <<" deleted \n"; 
        goto m;
        break;
    }
    case 5:
    {
        int loc;
        int del; 
        cout<<"Enter target Number for Location : ";
        cin>>loc;
        list.removeFromMiddle(del, loc);
        cout<<del <<" deleted \n";
        goto m;
        break;
    }
    case 6:
    {
        int del;
        list.removeFromEnd(del);
        cout<<del <<" deleted \n"; 
        goto m;
        break;
    }
    case 7:
    {
        list.displayList();
        break;
    }
    default:
        cout<<"Invalid Option\n";
        break;
    }
}