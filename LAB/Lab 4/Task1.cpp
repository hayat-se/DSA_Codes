#include<iostream>
#include "queue.h"
using namespace std;


int main()
{
    system("cls");
    Que<int> q1(6);

    for(int i=0 ; i<5 ; i++)
    {
        q1.Enqueue(i+1);
    }

    int n;
    cout<<"Enter Number to reverse : ";
    cin>>n;
    int arr[n];

    for(int i=0 ; i<n ; i++)
    {
        q1.Dequeue(arr[i]);
    }

    for(int i=n-1 ; i>=0 ; i--)
    {
        cout<<arr[i] <<" ";
    }

    int z;
    int w = q1.size();
    for(int i=0 ; i < w; i++)
    {
        q1.Dequeue(z);
        cout<<z <<" ";
    }

}