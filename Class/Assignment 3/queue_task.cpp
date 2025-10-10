#include<iostream>
#include<fstream>
#include "2D_queue.h"
using namespace std;


int checkPriority(char val)
{
    if(val >= '0' && val <='9')
    {
        return 1;
    }else if(val >= 'a' && val <= 'z')
    {
        return 2;
    }else if(val >= 'A' && val <= 'Z')
    {
        return 3;
    }else
    {
        return -1;
    }
}

int main()
{
    Que<char> q1[3];

    char ch;
    ifstream file("data.txt");

    if (!file) {
        cout << "Error: Could not open file!" << endl;
        return 1;
    }
    string word;
    while (getline(file,word)) 
    {
        for(int i=0 ; i<word.size(); i++)
        {
            int priority = checkPriority(word[i]);
            if(priority == 1)
            {
                q1[0].enqueue(word[i]);
            }else if(priority == 2)
            {
                q1[1].enqueue(word[i]);
            }else if(priority == 3)
            {
                q1[2].enqueue(word[i]);
            }else
            {
                cout<<"Special character found !!!\n";
            }
        }
        
    }
    for(int i = 0; i < 3; i++)
    {
        while(!q1[i].isEmpty())
        {
            char key;
            q1[i].dequeue(key);
            cout<<key <<", "; 
        }
        cout<<"\n";
    }

}