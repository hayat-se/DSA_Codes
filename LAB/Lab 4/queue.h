#include<iostream>
using namespace std;

template<class ItemType>
class Que 
{
    public:
        Que( );
        Que( int max ); // PARAMETERIZED CONSTRUCTOR
        ~Que( ) ; // DESTRUCTOR . . .
        int IsFull( ) const;    
        int IsEmpty( ) const;
        void Enqueue( ItemType newItem );
        void Dequeue( ItemType& item );
        int size();
        ItemType Front(); 
    private:
        int front;
        int rear;
        int maxQue;
        int count;
        ItemType* items; // DYNAMIC ARRAY IMPLEMENTATION
};
template<class ItemType>
Que<ItemType>::Que() // Default Constructor
{
    maxQue = 501;
    front = 0;
    rear = 0;
    count = 0;
    items = new ItemType[maxQue]; // dynamically allocates
}

template<class ItemType>
Que<ItemType>::Que( int max )// PARAMETERIZED Constructor
{
    maxQue = max + 1;
    front = 0;
    rear = 0;
    count = 0;
    items = new ItemType[maxQue]; // dynamically allocates
}
template<class ItemType>
Que<ItemType>::~Que( )
{
    delete [ ] items; // deallocates array
}

template<class ItemType>
int Que<ItemType>::IsEmpty( ) const
{
    return (count == 0);
}
template<class ItemType>
int Que<ItemType>::IsFull( ) const
{
    return ( count == maxQue );
}
template<class ItemType>
void Que<ItemType>::Enqueue( ItemType newItem )
{
    if (IsFull())   
    cout << "Over Flow";
    else
    { 
        items[rear] = newItem;
        rear = (rear + 1) % maxQue;
        ++count;
    }
}

template<class ItemType>
void Que<ItemType>::Dequeue( ItemType& item )
{
    if (IsEmpty())
    cout << "Under Flow";
    else
    { 
        item = items[front];
        front = (front + 1) % maxQue;
        --count;
    }
}

template<class ItemType>
int Que<ItemType>::size()
{
    return count;
}

template<class ItemType>
ItemType Que<ItemType>::Front()
{
    if(!IsEmpty())
    {
        return items[front];
    }else
    {
        cout<<"Queue is Empty\n";
    }
}