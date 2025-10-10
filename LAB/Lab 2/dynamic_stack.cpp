#include<iostream>
#include "stack.h"
using namespace std;


int main()
{
    Stack<float> s1;
    float val;
    float max =0;
    float min =5;
    for(int i=0 ; i<5 ; i++)
    {
        float num;
        cout<<"Enter Number : ";
        cin>>num;
        s1.push(num);
    }

    for(int i=0 ; i<5 ; i++)
    {
        s1.pop(val);
        if(max < val)
        {
            max = val;
        }
    }

    // for(int i=0 ; i<5 ; i++)
    // {
    //     s1f.pop(val);
    //     if(min > val)
    //     {
    //         min = val;
    //     }
    // }

    cout<<"Max : "<<max <<"\n";
    // cout<<"Min : "<<min;

}