#include<iostream>
using namespace std;

const int max_sz = 5;

class Stack
{
    
    int arr[max_sz];
    int top;
    
    public:
        Stack()
        {
            top = -1;
        }

        void push(int x)
        {
            if(top == max_sz-1)
            {
                cout<<"Stack is Full\n";
                return ;
            }
            else
            {
                top++;
                arr[top] = x; 
            }
        }

        int getTop()
        {
            if(top == -1)
            {
                cout<<"Stack is empty\n";
            }
            else
            {
                return arr[top];
            }
        }
};


int main()
{
    Stack nums;
    nums.push(3);
    cout<<nums.getTop();
}