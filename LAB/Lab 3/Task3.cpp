#include<iostream>
using namespace std;

bool isPrime(int n, int i=2)
{
    if(n <=2 )
    {
        if(n==2){
            return true;
        }else{
            false;
        }
    }

    if(n % i == 0)
    {
        cout<<"check , n ="<<n <<", i =" <<i<<"\n";
        return false;
    }
    if(i*i > n){
        return true;
    }
    return isPrime(n, i+1);
}

int main()
{
    int num = 13;
    cout<<"Number : "<<num <<"\n";
    // cout<<isPrime(num);
    if(isPrime(num) == 1){
        cout<<"Prime Number \n";
    }else{
        cout<<"not prime\n";
    }
    
}