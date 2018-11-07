/*
 File: Search_Algorith_zms24.cpp
 
 Author: Zane Saul
 C.S.2308.004
 Program: #2
 09/06/17
 
 Programming Assignment 1
 
 Write a C++ program that will implement the following functions:
 
 Returns the mean (average) of an array (vector) of values
 Returns the median of a vector of values
 Searches a vector of values for a given value, returns the index of the
 value
 if found or -1 if not found
 Searches a vector of sorted values for a given value, returns the index of
 the value if found or -1 if not found
 Sorts a vector of values from high to low  or from low to high using the
 selection sort algorithm; sort order is determined by the boolean parameter
 ascending. If ascending is true, sort from low to high, otherwise sort from
 high to low
 Your functions should adhere to the following signatures;
 
 Mean
 
 double computeMean (vector <int> numbers)
 Median
 
 int computeMedian (vector <int> numbers)
 Linear Search
 
 int searchLinear (int value, vector <int> numbers)
 Linear Binary
 
 int searchBinary (int value, vector <int> numbers)
 Selection Sort
 
 vector <int> sort <vector <int> numbers, bool ascending)
 
 
 
 Vector Values
 
 Use a random number generator to generate 101 values for your vector. As
 illustrated in class, use a call to the srand function with a seed value of
 75025 to initialize the generator. You will need to add a new include
 direction <cstdlib> to your code. This code should look like this:
 
 ...
 
 #include <cstdlib>
 
 ....
 
 // initialize the random number generator to the 25th Fibonacci number
 
 const unsigned int seed = 75025;
 
 Generate 101 random values for your vector, like this
 
 const int COUNT = 101;
 
 vector <int> numbers (COUNT);
 
 for (int i=0; i<COUNT; i++) {
 
 numbers[i] = rand() % 517;
 
 }
 Computations
 
 Compute the mean and the median of your vector values by calling your
 functions.
 Find (or not) the values; 33, 350, 517 in your vector. Print the index of
 those values
 Sort your vector values from high to low. Print the result
 Sort your vector values from low to high. Print the result.
 Find (or not) the values 186, 209, 22 in your vector using binary search.
 Print the index
 
 Extra Credit
 
 For extra credit find the mode(s) of the vector.. If there is none, print
 that fact. If there are multiple modes, print that fact.
 
 What signature should you use for the mode function?
 */

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

double computeMean ( vector <int> numbers );
int computeMedian ( vector <int> numbers );
int searchLinear ( int value, vector <int> numbers );
int searchBinary ( int value, vector <int> numbers );
vector <int> sort ( vector <int> numbers, bool ascending );
void printResults( vector <int> numbers );
void checkNumber( int check, int search, vector <int> numbers );
int computeMode( vector <int> numbers );

const int COUNT = 101;

int main( )
{
    const unsigned int seed = 75025;
    
    double mean,
           median,
           minimum = 99999999,
           maximum = 0;
    
    int check = 0,// used to check values from functions to be true or false
        search,
        mode;
    
    vector<int> numbers( COUNT );
    
    srand( seed );
    
    for( int i = 0; i < COUNT; i++ )
        numbers[i] = rand( ) % 517;
    
    /*Compute the mean and the median of your vector values by calling your
     functions.*/
    
    for( int i = 0; i < COUNT; i++ )
    {
        if( numbers[i] < minimum )
            minimum = numbers[i];
        if( numbers[i] > maximum )
            maximum = numbers[i];
    }
    
    cout << "The minimum value for the vector is: " << minimum << endl
         << "the maximum value for the vector is: " << maximum << endl;
    
    mean = computeMean( numbers );
    cout << "The mean of the vector is: " << mean << endl;
    
    median = computeMedian( numbers );
    cout << "The median of the vector is: " << median << endl;
    
    /*For extra credit find the mode(s) of the vector.. If there is none, print
      that fact. If there are multiple modes, print that fact.*/
    
    mode = computeMode( numbers );
    cout << "The mode of the vector is: " << mode << endl << endl << endl;

    
    /*Find (or not) the values; 33, 350, 517 in your vector. Print the index 
      of those values */
    
    search = 33;
    check = searchLinear( search, numbers );
    
    search = 350;
    check = searchLinear( search, numbers );
    
    search = 517;
    check = searchLinear( search, numbers );
    
    cout << endl << endl;
    
    /*Find (or not) the values 186, 209, 22 in your vector using binary
     search.*/
    
    search = 186;
    check = searchBinary ( search, numbers );
    
    search = 209;
    check = searchBinary ( search, numbers );
    
    search = 22;
    check = searchBinary ( search, numbers );
    
    cout << endl << endl;
    
    //Sort your vector values from high to low. Print the result
    
    cout << "Sorting index..." << endl;
    
    numbers = sort( numbers, 0 );
    printResults( numbers );
    
    cout << "Sort index from high to low complete." << endl << endl << endl;
    
    //Sort your vector values from low to high. Print the result.
    
    cout << "Sorting index..." << endl;
    
    numbers = sort( numbers, 1 );
    printResults( numbers );
    
    cout << "Sort index from low to high complete." << endl << endl << endl;
    
    //Print the index
    
    cout << "The index is as follows:" << endl;
    
    printResults( numbers );
    
    cout << "Index complete." << endl << endl;
    
    
    system("PAUSE>NUL");
    
    return 0;
}

/*
    Function: computeMean
 
    The function, computeMean, is called to find the average of all the numbers 
    in the vetor numbers.
 
        The mean of the index is: 244.782
 
    Receives: vector <int> numbers,
    Constants: Global Const int COUNT
    Returns: result
 */

double computeMean( vector <int> numbers )
{
    double result = 0.0;
    
    for( int i = 0; i < COUNT; i++ )
        result = result + numbers[i];
    
    result = result / COUNT;
    
    return result;
}

/*
    Function: computeMedian
 
    The function, computeMedian, is called to find middle value otherwise known 
    as the median. It will accomplish this using the numbers from the vector
    numbers.
 
        The median of the index is: 283
 
    Receives: vector <int> numbers,
    Constants: Global Const int COUNT
    Returns: result
 */

int computeMedian( vector <int> numbers )
{
    int temporary2;
    
    double result;
    double temporary = 0;
    
    temporary = COUNT / 2.0;
    
    temporary2 = temporary;
    
    
    if( .5 == temporary - temporary2 )
    {
        temporary = temporary - .5;
        temporary2 = temporary2 + 1;
        
        result = ( numbers[temporary] + numbers[temporary2] ) / 2.0;
    }
    else
        result = numbers[temporary];
    
    return result;
}

/*
    Function: computeMode
 
    The function, computeMode, is called to find the most occured number in the 
    vector numbers.
 
        The mode of the index is: 36
 
    Receives: vector <int> numbers,
    Constants: Global Const int COUNT
    Returns: result
 */

int computeMode( vector <int> numbers )
{
    int result = 0,
        temporary2 = 0;
    
    numbers = sort( numbers, 1 );
    
    for( int i = 0; i < COUNT; i++ )
    {
        int temporary = 1;
        
        if( numbers[i] == numbers[i + 1] )
        {
            while( numbers[i] == numbers[i + 1] )
            {
                i++;
                temporary++;
            }
            if( temporary2 < temporary )
            {
                temporary2 = temporary;
                result = numbers[i];
            }
        }
    }
    
    return result;
}

/*
    Function: searchLinear
 
    The function, searchLinear, is called to locate a number from the vector
    numbers. It will print out the storage location and value indicating
    the number was found. Further more if there are duplicates it will show that
    by printing as many duplicates as it finds. It will acomplish this by
    calling on checkNumber which will verify the number was found.
 
        Number 186 was not found!
        Number 209 was not found!
        Index: 5; Number: 36, located!
        Index: 6; Number: 36, located!
        Index: 7; Number: 36, located!
 
    Receives: int value, vector <int> numbers,
    Constants: Global Const int COUNT
    Returns: result
 */

int searchLinear( int value, vector <int> numbers )
{
    int result = -1;
    
    for( int i = 0; i < COUNT; i++ )
        if( numbers[i] == value )
        {
            result = 1;
            checkNumber( i, value, numbers );
        }
    if( result == -1 )
        checkNumber( result, value, numbers );
    
    return result;
}

/*
    Function: searchBinary
 
    The function, searchBinary, is called to locate a number from the sorted 
    vector numbers. It will print out the storage location and value indicating
    the number was found. Further more if there are duplicates it will show that
    by printing as many duplicates as it finds. It will acomplish this by  
    calling on checkNumber which will verify the number was found.
 
        Number 186 was not found!
        Number 209 was not found!
        Index: 5; Number: 36, located!
        Index: 6; Number: 36, located!
        Index: 7; Number: 36, located!
 
    Receives: int value, vector <int> numbers,
    Constants: Global Const int COUNT
    Returns: result
 */

int searchBinary( int value, vector <int> numbers )
{
    int minimum = 0,
        maximum = COUNT,
        average,
        result = -1,
        check = 1;
    
    average = ( maximum + minimum ) / 2;
    
    numbers = sort( numbers, 1 );
    
    do
    {
        if( value == numbers[average] )
        {
            result = average;
            check = 0;
            do
            {
            checkNumber( result++, value, numbers );
            }while( value == numbers[result] );
            
        }
        else if( value > numbers[average] )
        {
            minimum = average + 1;
            average = ( maximum + minimum ) / 2;
        }
        else if( value < numbers[average] )
        {
            maximum = average - 1;
            average = ( maximum + minimum ) / 2;
        }
        if( minimum > maximum || maximum < minimum )
        {
            check = 0;
            checkNumber( result, value, numbers );
        }
    }while( check );
    
    return result;
}

/*
    Function: sort
 
    The function, sort, is called to create a temporary copy of the vector 
    numbers. It uses the bool ascending to determine the order it will store 
    values. If true values will be stored from lowest integer to highest. 
    Otherwise stored highest to lowest.
 
        0 0     0 514
        1 5     1 506
        2 12    2 505
        3 26    3 502
        4 27    4 502
        5 36    5 483
        6 36    6 478
 
    Receives: vector <int> numbers, bool ascending
    Constants: Global Const int COUNT
    Returns: vector <int> numbers
 */

vector <int> sort( vector <int> numbers, bool ascending )
{
    if( ascending == true )
    {
        for( int i = 0; i < COUNT; i++ )
        {
            int y;
            
            for( int z = i; z < COUNT; z++ )
            {
                int temp;
                if( numbers[i] > numbers[z] )
                {
                    temp = numbers[i];
                    numbers[i] = numbers[z];
                    numbers[z] = temp;
                    y = z;
                }
            }
        }
    }
    else
    {
        for( int i = 0; i < COUNT; i++ )
        {
            for( int z = i; z < COUNT; z++ )
            {
                int temp;
                if( numbers[i] < numbers[z] )
                {
                    temp = numbers[i];
                    numbers[i] = numbers[z];
                    numbers[z] = temp;
                }
            }
        }
    }
    return numbers;
}

/*
    Function: printResults
 
    The function, printResults, is called print all the values in the vector
    numbers. It will first print the index number then the value stored in that
    location.
 
        0 514
        1 506
        2 505
        3 502
        4 502
        5 483
        6 478
 
    Receives: vector <int> numbers
    Constants: Global Const int COUNT
    Returns: Nothing. Prints to console.
 */

void printResults( vector <int> numbers )
{
    for( int i = 0; i < COUNT; i++ )
    {
        cout << i << " " << numbers[i] << endl;
    }
}

/*
    Function: checkNumber
    
    The function, checkNumber, is called to verify whether or not the requested
    number was located. Printing out to screen the results. If found prints the 
    index number then the number in that storage location.
 
    Number 209 was not found!
    Index: 5; Number: 36, located!
 
    Receives: int check, int search, vector <int> numbers
    Constants: None
    Returns: Nothing. Prints to console.
 */

void checkNumber( int check, int search, vector <int> numbers )
{
    if( check != -1 )
        cout << "Index: " << check << "; Number: " << numbers[check]
             << ", located!" << endl;
    else
        cout << "Number " << search << " was not found!" << endl;
}
