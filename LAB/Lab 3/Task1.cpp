#include<iostream>
using namespace std;

void getNums(int n){
    if(n == 0)
    {
        cout<<n;
        return;
    }else
    {
        cout<<n <<" ";
        getNums(n-1);
    }
}

int main()
{
    getNums(5);

}