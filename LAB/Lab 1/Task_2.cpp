#include <iostream> 
#include <fstream>
using namespace std; 


int main ( )
{ 
    char name[10];
    float mt1, mt2, final, avg;
    ifstream fin ; //Create file input stream object 
    ofstream fout ; //Create file output stream object
    fin.open ( "input.dat") ; //Open input file 
    fout.open ( "output.dat"); //Open output file
    while (!fin.eof()) //Read data from input file
    {
        fin >> name >> mt1 >> mt2 >> final; 
        avg = 0.25*mt1 + 0.25*mt2 + 0.5*final ;
        fout << name << '\t' << avg << endl ; //Write result to output file
    }
    fin.close ( ) ; //Close input file 
    fout.close ( ) ; //Close output file
}