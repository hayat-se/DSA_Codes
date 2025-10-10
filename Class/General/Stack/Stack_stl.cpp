#include<iostream>
#include<stack>
using namespace std;


int main()
{
    stack<string> names;
    for(int i=0 ; i<5 ; i++)  // setting values in Stack "names".
    {
        names.push(to_string(i));
    }


    if(names.empty()) // function to check whether the stack is empty or full
    {
        cout<<"Stack is Empty \n";
    }else
    {
        cout<<"Stack has elements \n";
        cout<<names.size()<<"\n"; // print the size of stack.
    }



    for(int i=0 ; i<5 ; i++) // print top element and then remove it.
    {
        cout<<names.top()<<"\n";
        names.pop();
    }



    if(names.empty()) // function to check whether the stack is empty or full
    {
        cout<<"Stack is Empty \n";
    }else
    {
        cout<<"Stack has elements \n";
    }
 
}