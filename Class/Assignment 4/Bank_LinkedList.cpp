#include "BankLL.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
    LinkedList bankList;
    int choice, cnic;
    string name;
    double balance, amount;

    while (true)
    {
        cout << "\n========== BANK CUSTOMER MENU ==========\n";
        cout << "1. Add Customer\n";
        cout << "2. Remove Customer\n";
        cout << "3. Search Customer\n";
        cout << "4. Display All Customers\n";
        cout << "5. Sort and Display by Balance\n";
        cout << "6. Deposit Money\n";
        cout << "7. Withdraw Money\n";
        cout << "8. Exit\n";
        cout << "========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cin.ignore();
            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter 4-digit CNIC: ";
            cin >> cnic;
            cout << "Enter balance: ";
            cin >> balance;
            bankList.addCustomer(name, cnic, balance);
            break;

        case 2:
            cout << "Enter CNIC of customer to remove: ";
            cin >> cnic;
            bankList.removeCustomer(cnic);
            break;

        case 3:
            cout << "Enter CNIC to search: ";
            cin >> cnic;
            bankList.searchCustomer(cnic);
            break;

        case 4:
            bankList.displayAll();
            break;

        case 5:
            bankList.sortByBalance();
            break;

        case 6:
            cout << "Enter CNIC to deposit money: ";
            cin >> cnic;
            cout << "Enter amount: ";
            cin >> amount;
            bankList.depositMoney(cnic, amount);
            break;

        case 7:
            cout << "Enter CNIC to withdraw money: ";
            cin >> cnic;
            cout << "Enter amount: ";
            cin >> amount;
            bankList.withdrawMoney(cnic, amount);
            break;

        case 8:
            cout << "Exiting program...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
