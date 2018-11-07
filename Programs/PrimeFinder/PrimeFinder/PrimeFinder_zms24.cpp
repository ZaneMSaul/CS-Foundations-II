/*
 File: PrimeFinder_zms24.cpp
 
 Author: Zane Saul
 C.S.2308.004
 Program: #1
 09/06/17
 
 This program makes an attempt to find prime numbers.
*/

#include <iostream>

using namespace std;

bool primeDeterminer( int, double, bool );
void primeFinder( int, double, bool );

int main( )
{
    int number;
    
    double value = 0.0;
    
    bool prime = false;
    
    cout << "Welcome to Prime Finder, numbers calculated in "
         << "this program are prime numbers." << endl;

    cout << "Please enter an integer: ";
    cin >> number;
    cout << endl;
    
    prime = primeDeterminer( number, value, prime );
    
    if( prime == true )
        cout << "This number is prime.";
    else
        cout << "This number is not prime.";
    
    cout << endl << endl;
    
    cout << "Now enter another integer to find all prime numbers upto that "
         << "integer: ";
    cin >> number;
    cout << endl;
    
    cout << "Listed below are all prime numbers upto " << number << ":" << endl;
    
    primeFinder( number, value, prime );
    
    cout << endl;
    
    system("PAUSE>NUL");
    
    return 0;
}
/*
    Comments needed
 */
bool primeDeterminer( int number, double value, bool prime )
{
    for( int i = 1; i < number; i++ )
    {
        value = number % i;
        
        if( value == 0 )
        {
            if( i == 1 )
                prime = true;
            else if( number == i )
                prime = true;
            else
                prime = false;
        }
    }
    
    return prime;
}
/*
    Function: primeFinder
 
    The primary function of this definition is to print to screen all prime
    numbers upto the specific number provided.
 */
void primeFinder( int number, double value, bool prime )
{
    for( int i = 1; i < number; i++ )
    {
        for( int z = 1; z < i; z++ )
        {
            value = i % z;
            
            if( value == 0 )
            {
                if( z == 1 )
                    prime = true;
                else if( z == i )
                    prime = true;
                else
                    prime = false;
            }
        }
        
        if( prime == true )
            cout << i << ", ";
    }
}
