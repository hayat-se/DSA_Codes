#include<iostream>
using namespace std;

template<class numberType>
class Stack
{
    numberType* stackArray;
    int top;
    int max_size;

    public:
        Stack();
        Stack(int);
        bool isEmpty();
        bool isFull();
        void push(numberType);
        void pop(numberType&);
};

template<class numberType>
Stack<numberType>::Stack()
{
    max_size = 100;
    top = -1;
    stackArray = new numberType[max_size];
}

template<class numberType>
Stack<numberType>::Stack(int sz)
{
    max_size = sz;
    top = -1;
    stackArray = new numberType[max_size];
}


template<class numberType>
bool Stack<numberType>::isEmpty()
{
    if(top == -1){
        return true;
    }
    else
    {
        return false;
    }
}
template<class numberType>
bool Stack<numberType>::isFull()
{
    if(top == max_size-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class numberType>
void Stack<numberType>::push(numberType newValue)
{
    if(isFull())
    {
        cout<<"Stack overflow\n";
        return;
    }
    else
    {
        top++;
        stackArray[top] = newValue;
    }
}

template<class numberType>
void Stack<numberType>::pop(numberType &value)
{
    if(isEmpty())
    {
        cout<<"Stack is Empty\n";
        return;
    }
    else
    {
        value = stackArray[top];
        top--;
    }
}

