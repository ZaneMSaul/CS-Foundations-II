/*
 File: Film.cpp
 
 Author: Zane Saul
 C.S.2308.004
 Program: #5
 10/12/17
 
 Write a C++ program that defines a class Film with the following attributes /
 data values
 
 int id;               // the unique id of the film
 
 string name;          // the film's name
 
 string description;   // the film's description
 
 int runningTime;      // the film's running time in minutes <= 180
 
 FilmRating rating;    // the film's rating, from
 the enum FilmRating
 
 Also define the enum FilmRating; you can place the
 enum definition in the
 header file of Film;
 
 enum FilmRating  {G, PG, PG_13, NC_17, R, UNRATED};
 
 The film class should be defined using a separate Film.h file for all
 declarations, e.g., attributes and method prototypes. The Film.cpp file will
 include the implementation of the methods.
 
 Define the following methods for Film
 
 A constructor that has the signature
 Film (int id, string name, string description, int runningTime, string rating);
 
 This constructor should assign the parameters to the appropriate attributes of
 the class.
 Note: you will need to convert the rating parameter to a FilmRating type.
 
 A second constructor that has the signature
 Film (int id, string name, string description, int runningTime,
 FilmRating rating);
 
 This constructor should assign the parameters to the appropriate attributes of
 the class. Include a method print that will print the attributes of Film
 nicely. This should include the FilmRating attribute     as a string;
 
 Create getters and setters for all attributes except id; only a getter should
 be created for id;.
 Note: Figure out a way to initialize id.
 
 If you need helper functions (you will) determine their accessibility, i.e.,
 are they private or public?
 
 Define a Main Routine
 
 Write a main routine that does the following:
 Defines a vector of films
 Reads a comma delimited file of data on a few films (at least 4)
 Creates new Film objects from the data and adds them to the vector
 Prints all the Films in the vector after reading all the data from the file.
 Notes
 Please do not have any user input in this program.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Film.h"//;

using namespace std;

int main()
{
    string input,
           filmName,
           description,
           nothing,
           rating;
    
    int runningTime,
        i = 0;
    
    ifstream filmFile;
    
    vector<Film> films;
    
    filmFile.open( "films.dat", ios::in );
    
    getline( filmFile, filmName, ',' );
    while( filmFile )
    {
        cout << filmName << endl;
        getline( filmFile, description,  ',' );
        cout << description << endl;
        filmFile >> runningTime;
        cout << runningTime << endl;
        getline( filmFile, nothing, ',' );
        getline( filmFile, rating, ',' );
        cout << rating << endl;
        
        films.push_back( Film( i, filmName, description, rating, runningTime ));
        i++;
        
        getline( filmFile, filmName, ',' );
    }
    
    for( int i = 0; i < films.size( ); i++ )
        films[i].print( );
    
    return 0;
}
