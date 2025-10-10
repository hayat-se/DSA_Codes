#include<iostream>
#include<iomanip>
using namespace std;


class House{
    string owner;
    string address;
    int bedrooms;
    float price;
public:
    static int totalHouses;
    static int getNoOfHouses()
    {
        return totalHouses;
    }
    void setData()
    {
        cin.ignore();
        cout<<"Enter owner name : ";
        getline(cin, owner);
        cout<<"Enter address : ";
        getline(cin, address);
        cout<<"Enter Number of bedrooms : ";
        cin>>bedrooms;
        cout<<"Enter price of Property : ";
        cin>>price;
    }

    void printDetails()
    {
        cout<<owner << setw(20) << address << setw(20) <<bedrooms <<setw(20) <<price <<"\n";
    }

    friend void searchForHouse(House houses[])
    {
        int allHouses = houses->getNoOfHouses();
        float prc;
        int sz;
        cout<<"Enter your Budget : ";
        cin>>prc;
        cout<<"Enter Number of bedroom need : ";
        cin >>sz;
        for(int i=0 ; i<allHouses ; i++)
        {
            if(prc >= houses[i].price && sz <= houses[i].bedrooms)
            {
                cout<<"House #"<<i+1 <<"\n";
                houses[i].printDetails();
            }
            else
            {
                cout<<"No HOuse found\n";
            }
        }
    }
};

void addHouse(House houses[])
    {
        char op;
        int count = 0;

        top:
        cout<<"Do you want to add House details ? (Y/N) : ";
        cin>>op;

        while (op == 'Y' || op == 'y')
        {
            houses[count].setData();
            count++;
            goto top;
        }
    
        if(count > 0)
        {
            cout<<"Owner Name" << setw(20) << "Address" << setw(20) <<"Bedrooms" <<setw(20) <<"Price" <<"\n";
            for (int i = 0; i < count; i++)
            {
                houses[i].printDetails();
            }   
        }else
        {
        cout<<"NO Data Found!!!!!!!!!\n";
        }
        houses->totalHouses = count;

    }

    int House ::totalHouses = 0;

int main()
{
    House allHouses[100];
    House* houses = allHouses;
    
    do
    {
        int op;
        cout<<"1. Add House \n2. Search for House \n3. Exit\n";
        cout<<"Enter your Option :";
        cin>>op;

        if(op == 1)
        {
            addHouse(houses);
        }
        else if(op == 2)
        {
            searchForHouse(houses);
        }else{
            cout<<"Thanks for using this App.";
            exit(0);
        }
    }while(true);
    
}