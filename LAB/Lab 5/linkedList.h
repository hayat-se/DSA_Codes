#include<iostream>
using namespace std;

typedef struct Node* NodePtr;
struct Node
{
    int data;
    NodePtr next;
};

class LinkedList
{
    NodePtr head;
public:
    LinkedList()
    {
        head = nullptr;
    }
    void insertAtStart(int value)
    {
        NodePtr newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void insertAfter(int value, int target)
    {
        NodePtr newNode = new Node();

        for(NodePtr i = head ; i != NULL ; i= i->next)
        {
            if(i->data == target)
            {
                newNode->next = i->next;
                newNode->data = value;
                i->next = newNode;
                break;
            }
        }
    }

    void removeFromStart()
    {
        if(head != nullptr)
        {
            NodePtr temp = new Node();
            temp = head;
            head = head->next;
            delete temp;
        }else
        {
            cout<<"Linked List Empty\n";
        }
    }

    void displayLinkedList()
    {
        if(head != nullptr)
        {
            for(NodePtr i = head; i != NULL ; i = i->next)
            {
                cout<<i->data <<" ";
            }
        }else
        {
            cout<<"Linked List is Empty\n";
        }
    }


    void removeFromEnd(int& deletedValue)
    {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        if (head->next == nullptr) {
            deletedValue = head->data;
            delete head;
            head = nullptr;
            return;
        }

        NodePtr prev = nullptr;
        NodePtr curr = head;

        while (curr->next != nullptr) { 
            prev = curr;
            curr = curr->next;
        }

        deletedValue = curr->data;
        prev->next = nullptr;  
        delete curr;          
    }

};