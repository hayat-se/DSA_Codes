#include <algorithm>
#include <iostream>
#include <deque>
#include <conio.h>
using namespace std;

int main()
{
    deque<int> v;
    for (int i = 0; i < 25; i++)
    {
        v.push_back(i);
    }
    random_shuffle(v.begin(), v.end());
    for (int j = 0; j < 25; j++) 
    {
        cout<< v.front() << " ";
        v.pop_front();
    }
    cout << endl;
    getch();

    return 0;
}