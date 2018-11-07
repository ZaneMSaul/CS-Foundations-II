/*
 
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printIdInfo( ostream &out, const string AUTHORS, const int SECTION,
                 const string DUE_DATE );

int main( )
{
    const string AUTHORS = "Zane Saul",
                 DUE_DATE = "--/--/--";
    
    const int SECTION = 004,
              MAX_INVENTORY = 30;
    
    int menu_choice;
    
    struct machine
    {
        string name;
        double price;
        int inventory;
        int location;
    };
    
    srand(time(NULL));
    
    struct machine machine1;
    
    for( int i = 0; i < 9; i++ )
    {
        machine[i].inventory = rand( ) % MAX_INVENTORY + 0;
    }
    
    printIdInfo( cout, AUTHORS, SECTION, DUE_DATE );
    
    cout << "Choose from one of the following:" << endl
         << "1." << "Coke" << endl
         << "2." << "Coke Zero" << endl
         << "3." << "Diet Coke" << endl
         << "4." << "Sprite" << endl
         << "5." << "Dasani" << endl
         << "6." << "Fanta" << endl
         << "7." << "Poweraid" << endl
         << "8." << "Coke" << endl << endl;
         << "9." << "Cancel Transaction" << endl << endl << endl;
    
    switch ( menu_choice )
    {
        case 1:
            
            break;
        case 2;
            
            break;
        case 3:
            
            break;
        case 4;
            
            break;
        case 5:
            
            break;
        case 6;
            
            break;
        case 7:
            
            break;
        case 8;
            
            break;
        case 9:
            
            break;
        case 10;
            
            break;
    }
    system("PAUSE>NUL");
    
    return 0;
}

/*
 Function: printIdInfo
 
 Author: Zane Saul
 C.S.2308.004
 Program: #3 Soda Machine
 Due_Date: --/--/--
 
 The function, functionname, prints the authors’ personal information (name,
 class/section number, lab section number, due date) on the first, second,
 third and fourth lines of output. printIdInfo should print two blank lines
 after the due date.
 
 Receives: ostream &out, const string AUTHORS, const int SECTION, const
 string DUE_DATE
 Constants: AUTHORS, SECTION, DUE_DATE
 Returns: Nothing. Prints to the output source.
 
 */

void printIdInfo( ostream &out, const string AUTHORS, const int SECTION,
                 const string DUE_DATE )
{
    out << AUTHORS << endl
    << "C.S.2308." << SECTION << endl
    << DUE_DATE << endl << endl << endl;
}
