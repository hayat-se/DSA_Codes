#include<iostream>
using namespace std;

template<class itemType>
class Que
{
    int front;
    int rear;
    int MAX_SIZE=100;
    itemType* items;
    int count;

    public:
        Que();
        Que(int);
        void enqueue(itemType);
        void dequeue(itemType&);
        itemType Front();
        bool isEmpty();
        bool isFull();  
        int size();
};

template<class itemType>
Que<itemType>::Que()
{
    front =0;
    rear=0;
    items = new itemType[MAX_SIZE];
    count=0;
}

template<class itemType>
Que<itemType>::Que(int size)
{
    MAX_SIZE = size;
    front =0;
    rear=0;
    count =0;
    items = new itemType[MAX_SIZE];
}

template<class itemType>
bool Que<itemType>::isEmpty()
{
    return (count == 0);
}

template<class itemType>
bool Que<itemType>:: isFull()
{
    return (count == MAX_SIZE);
}

template<class itemType>
void Que<itemType>::enqueue(itemType item)
{
    if(!isFull())
    {
        items[rear] = item;
        rear = (rear +1) % MAX_SIZE;
        count++;
    }
    else
    {
        cout<<"Queue is FULL\n";
    }
}

template<class itemType>
void Que<itemType>::dequeue(itemType &item)
{
    if(!isEmpty())
    {
        item = items[front];
        front = (front +1) % MAX_SIZE;
        --count;
    }
    else
    {
        cout<<"Queue is Empty\n";
    }
}

template<class itemType>
itemType Que<itemType>::Front()
{
    if(!isEmpty())
    {
        return items[front];
    }
    else
    {
        cout<<"Queue is EMPTY\n";
    }
}

template<class itemType>
int Que<itemType>::size()
{
    return count;
}
