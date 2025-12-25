#include <iostream>
#include <string>
using namespace std;

typedef struct Node* NodePtr;
struct Node
{
    string name;
    int cnic;
    double balance;
    NodePtr next;
    NodePtr pre;
};

class LinkedList
{
    NodePtr head;

public:
    LinkedList();
    bool isValidCNIC(int cnic);
    void addCustomer(string name, int cnic, double balance);
    void removeCustomer(int cnic);
    void searchCustomer(int cnic);
    void depositMoney(int cnic, double amount);
    void withdrawMoney(int cnic, double amount);
    void displayAll();
    void sortByBalance();
};


LinkedList::LinkedList()
{
    head = nullptr;
}

bool LinkedList::isValidCNIC(int cnic)
{
    return (cnic >= 1000 && cnic <= 9999);
}

void LinkedList::addCustomer(string name, int cnic, double balance)
{
    if (name.empty())
    {
        cout << "Name cannot be empty!\n";
        return;
    }
    if (!isValidCNIC(cnic))
    {
        cout << "CNIC must be a 4-digit number!\n";
        return;
    }
    if (balance < 0)
    {
        cout << "Balance cannot be negative!\n";
        return;
    }

    NodePtr newNode = new Node();
    newNode->name = name;
    newNode->cnic = cnic;
    newNode->balance = balance;
    newNode->next = nullptr;
    newNode->pre = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        cout << "Customer added successfully!\n";
        return;
    }

    NodePtr temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->pre = temp;
    cout << "Customer added successfully!\n";
}

void LinkedList::removeCustomer(int cnic)
{
    if (head == nullptr)
    {
        cout << "List is empty!\n";
        return;
    }

    NodePtr temp = head;

    while (temp != nullptr && temp->cnic != cnic)
        temp = temp->next;

    if (temp == nullptr)
    {
        cout << "Customer not found!\n";
        return;
    }

    if (temp->pre != nullptr)
        temp->pre->next = temp->next;
    else
        head = temp->next;

    if (temp->next != nullptr)
        temp->next->pre = temp->pre;

    delete temp;
    cout << "Customer removed successfully!\n";
}

void LinkedList::searchCustomer(int cnic)
{
    NodePtr temp = head;
    while (temp != nullptr)
    {
        if (temp->cnic == cnic)
        {
            cout << "\nCustomer Found:\n";
            cout << "Name: " << temp->name << endl;
            cout << "CNIC: " << temp->cnic << endl;
            cout << "Balance: " << temp->balance << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Customer not found!\n";
}

void LinkedList::depositMoney(int cnic, double amount)
{
    if (amount <= 0)
    {
        cout << "Amount must be positive!\n";
        return;
    }

    NodePtr temp = head;
    while (temp != nullptr)
    {
        if (temp->cnic == cnic)
        {
            temp->balance += amount;
            cout << "Deposited " << amount << " successfully!\n";
            cout << "New Balance: " << temp->balance << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Customer not found!\n";
}

void LinkedList::withdrawMoney(int cnic, double amount)
{
    if (amount <= 0)
    {
        cout << "Amount must be positive!\n";
        return;
    }

    NodePtr temp = head;
    while (temp != nullptr)
    {
        if (temp->cnic == cnic)
        {
            if (temp->balance < amount)
            {
                cout << "Insufficient balance!\n";
                return;
            }

            temp->balance -= amount;
            cout << "Withdrawn " << amount << " successfully!\n";
            cout << "Remaining Balance: " << temp->balance << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Customer not found!\n";
}

void LinkedList::displayAll()
{
    if (head == nullptr)
    {
        cout << "No customers to display!\n";
        return;
    }

    cout << "\nAll Customers:" << endl;
    cout << "--------------------------------------\n";
    NodePtr temp = head;
    while (temp != nullptr)
    {
        cout << "Name: " << temp->name << "\n";
        cout << "CNIC: " << temp->cnic << "\n";
        cout << "Balance: " << temp->balance << "\n";
        cout << "--------------------------------------" << endl;
        temp = temp->next;
    }
}

void LinkedList::sortByBalance()
{
    if (head == nullptr || head->next == nullptr)
    {
        cout << "Not enough customers to sort!\n";
        return;
    }

    bool swapped;
    do
    {
        swapped = false;
        NodePtr curr = head;

        while (curr->next != nullptr)
        {
            if (curr->balance > curr->next->balance)
            {
                swap(curr->name, curr->next->name);
                swap(curr->cnic, curr->next->cnic);
                swap(curr->balance, curr->next->balance);
                swapped = true;
            }
            curr = curr->next;
        }
    } while (swapped);

    cout << "\nCustomers sorted by balance successfully!\n";
    displayAll();
}
