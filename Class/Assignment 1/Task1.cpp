#include<iostream>
#include "stack.h"
using namespace std;

bool checkPalindrome(string var)
{
    for(int i=0 ; i< var.size(); i++)
    {
        int start = 0; 
        int end = var.size() - 1;
        while(start < end)
        {
             if(var[start] != var[end])
            {            
                return false;
            }
            else 
            {
                return true;
            }
            start++;
            end--;
        }
    }
}

int main()
{
    Stack<string> s1;
    string var;
    int size;
    cout<<"\t\t PALINDROME CHECKER\n\n";
    cout<<"Number of Items you want to add to Stack : ";
    cin>>size;
    for(int i=0 ; i<size ; i++)
    {
        string word;
        cout<<"Enter Value to check : ";
        cin>>word;
        s1.push(word);
    }

    string name;
    cout<<"Palindrom Strings are : ";
    for(int i=0 ; i<size ; i++)
    {
        s1.pop(name);
        if(checkPalindrome(name))
        {
            cout<<name <<" ";
        }
    }


}