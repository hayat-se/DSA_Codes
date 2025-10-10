#include<iostream>
using namespace std;

int binCoff(int n, int k)
{
    if(n > 0)
    {
        if(n == k)
        {
            return 1;
        }else if(k==0)
        {
            return 1;
        }else
        {
            // cout<<"n = "<<n <<" , k = "<<k<<"\n";
            return binCoff(n-1, k-1) + binCoff(n-1,k);
        }
    }else
    {
        return 1;
    }
}

int main()
{
    int x = binCoff(5,2);
    cout<<x << "\n";
}