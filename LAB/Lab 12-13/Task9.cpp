#include <iostream>
#include <numeric>
#include <conio.h>
using namespace std;
int vec[] = {1, 2, 3, 4, 5};

int main()
{
    int sum = accumulate(vec, vec + 5, 0);
    cout << sum << endl;
    int prod = accumulate(vec, vec + 5, 1);
    cout << prod << endl;
    
    getch();
    return 0;
}