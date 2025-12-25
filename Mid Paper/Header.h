#include<iostream>
using namespace std;

struct Node
{
    string name;
    int roll_no;
    Node* pre;
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

    LinkedList(string name, int rollNo)
    {
        head->name = name;
        head->roll_no = rollNo;
        head->pre = NULL;
        head->next = NULL;
    }

    void insertSorted(string name, int rollNo)
    {
        Node* newNode = new Node();
        newNode->name = name;
        newNode->roll_no = rollNo;

        if(head == NULL)
        {
            newNode->pre = NULL;
            newNode->next = NULL;
            head = newNode;
        }
        else if(head->roll_no > rollNo)
        {
            Node* temp = head;
            newNode->pre = NULL;
            newNode->next = head;
            head->pre = newNode;
            head = newNode;
        }
        else
        {
            Node* finalNode;
            for(Node* temp = head; temp != NULL; temp = temp->next)
            {
                finalNode = temp;
            }

            if(rollNo > finalNode->roll_no)
            {
                finalNode->next = newNode;
                newNode->pre = finalNode;
                newNode->next = NULL;
            }
            else
            {
                for(Node* current = head; current != NULL; current = current->next)
                {
                    if(current->roll_no == rollNo)
                    {
                        cout<<"Error!!! Duplicate Roll-No found.";
                        return;
                    }
                    else
                    {
                        if(current->roll_no > rollNo)
                        {
                            newNode->pre = current->pre;
                            newNode->next = current;
                            current->pre->next = newNode;
                            current->pre = newNode;
                        }
                    }
                }
            }
        }
    }

    void deleteNode(int rollNo)
    {
        bool rollFound = false;
        if(head == NULL)
        {
            cout<<"No Student exist\n";
            return;
        }
        else if(head->roll_no == rollNo)
        {
            rollFound = true;
            Node* temp = head;
            head->next->pre = NULL;
            head = head->next;
            delete temp;
        }
        else
        {
            for(Node* current = head; current != NULL; current = current->next)
            {
                if(rollNo == current->roll_no)
                {
                    rollFound = true;
                    Node* temp = current;
                    temp->pre->next = temp->next;
                    temp->next->pre = temp->pre;
                }
            }

            if(rollFound == false)
            {
                cout<<"No Student with Roll-No  "<<rollNo <<" found...\n";
                return;
            }
        }
    }

    void displayStudents()
    {
        cout<<"*** Student List ***\n\n";
        for(Node* current = head; current != NULL; current = current->next)
        {
            cout<<"Name : "<<current->name <<"\n";
            cout<<"Roll-No : "<<current->roll_no <<"\n\n";
        }
    }
};