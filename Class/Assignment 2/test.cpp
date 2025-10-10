#include <iostream>
#include <fstream>
#include <string>
#include "stack.h"
using namespace std;


bool isBalanced(string data, Stack<char> &s1)
{
    
    while (!s1.isEmpty()) {
        char tmp;
        s1.pop(tmp);
    }

    char previous = ' ';
    for(int i=0 ; i<data.length() ; i++)
    {
        char current = data[i];
        if(isalnum(current))
        {
            if(isalnum(previous) || previous == ')')
            {
                return false;
            }
        }

        if(current == '(')
        {
            s1.push(current);
            if(isalnum(previous) || previous == ')')
            {
                return false;
            }
        }

        if(current == ')')
        {
            if(s1.isEmpty())
            {
                return false;
            }
            if(
            previous == '+' || 
            previous == '-' || 
            previous == '*' || 
            previous == '/' || 
            previous == '(' )
            {
                return false;
            }
            if(s1.peak() != '(')
            {
                return false;
            }
            char poppedValue;
            s1.pop(poppedValue);
        }

        if(current == '+' || current == '-' || current == '*' || current == '/')
        {
            if(
            previous == ' ' || 
            previous == '+' || 
            previous == '-' || 
            previous == '*' || 
            previous == '/' ||
            previous == '(')
            {
                return false;
            }
        }
        previous = current;
    }

    if(
        !s1.isEmpty() || 
        previous == '+' || 
        previous == '-' || 
        previous == '*' || 
        previous == '/' ||
        previous == '(')
        {
            return false;
        }

    return true;
}

int main() {
    ifstream file("data.txt");
    Stack<char> s1;

    if (!file) {
        cout << "Error: Could not open file!" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
        bool res = isBalanced(line, s1);
        if(res == 1){
            cout<<line <<" is Balanced \n";
        }else
        {
            cout<<line <<" is not - Balanced \n";
        }
    }

    file.close();
}
