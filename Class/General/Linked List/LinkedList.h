#include<iostream>
using namespace std;

struct Node
{
    int info;
    Node* prev;
    Node* next;
};


class LinkedList
{
    Node* head;
public:
    LinkedList()
    {
        head = NULL;
    }

    void insertAtStart(int val)
    {
        if(head == NULL)
        {
            // cout<<"No Node\n";
            Node* newNode = new Node();
            newNode->info = val;
            newNode->prev = NULL;
            newNode->next = NULL;
            head = newNode;
        }else
        {
            // cout<<"Node exist\n";
            Node* newNode = new Node();
            newNode->info = val;
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            newNode->prev = NULL;
        }
    }

    void deleteFromStart(int &toDeleted)
    {
        if(head == NULL)
        {
            cout<<"NO Item in List \n";
        }else
        {
            Node* temp = new Node();
            temp = head;
            toDeleted = temp->info;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
    }

    void insertAtMiddle(int val,int target)
    {
        if(head == NULL)
        {
            cout<<"Empty List\n";
        }else
        {
            for(Node* temp = head; temp != NULL ; temp = temp->next)
            {
                if(target == temp->info)
                {
                    Node* newNode = new Node();
                    newNode->info = val;
                    newNode->prev = temp;
                    newNode->next = temp->next;
                    temp->next->prev = newNode;
                    temp->next = newNode;
                }
            }
        }
    }

    void removeFromMiddle(int &toDelete, int target)
    {
        if(head == NULL)
        {
            cout<<"Empty List\n";
        }else
        {
            for(Node* temp = head; temp!= NULL; temp= temp->next)
            {
                if(target == temp->info)
                {
                    toDelete = temp->info;
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                }
            }
        }
    }

    void insertAtEnd(int val)
    {
        if(head == NULL)
        {
            cout<<"Empty List\n";
        }else
        {
            Node* lastNode = new Node();
            for(Node* temp = head; temp != NULL ; temp = temp->next)
            {
                lastNode = temp; 
            }
            Node* newNode = new Node();
            newNode->info = val;
            newNode->prev = lastNode;
            newNode->next = NULL;
            lastNode->next = newNode;
        }
    }

    void removeFromEnd(int &toDelete)
    {
        if(head == NULL)
        {
            cout<<"Empty List\n";
        }else
        {
            Node* lastNode = new Node();
            for(Node* temp = head; temp != NULL ; temp = temp->next)
            {
                lastNode = temp; 
            }
            toDelete = lastNode->info;
            lastNode->prev->next = NULL;
            delete lastNode;
        }
    }

    void displayList()
    {
        if(head != NULL)
        {
            Node* temp = new Node();
            for(temp = head ; temp != NULL ; temp = temp->next)
            {
                cout<<temp->info <<" -> ";
            }
            cout<<"\n";
        }
    }

    void concateList(LinkedList list)
    {
        Node* finalNode;
        for(Node* temp = head; temp != NULL; temp = temp->next)
        {
            finalNode = temp;
        }

        finalNode->next = list.head;
    }

    friend LinkedList concateLLists(LinkedList list1, LinkedList list2)
    {
        LinkedList FinalNode = list1; // first add the first list to the new List that we will return.
        Node* firstListLastNode; // find the last node of first List, to attach it with the 2nd list.
        for(Node* temp = FinalNode.head; temp!=NULL ; temp = temp->next)
        {
            firstListLastNode = temp; 
        }// this loop give us last node.
        firstListLastNode->next = list2.head;
        
        return FinalNode;
    }
};