#include <list>
#include <algorithm>
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    list<int> v;

    for (int i = 0; i < 25; i++)
    {
        v.push_back(i);
    }
    for (int j = 0; j < 25; j++) 
    {
    cout << v.front() << " ";
    v.pop_front();
    }
    cout << endl;

    getch();
    return 0;
}