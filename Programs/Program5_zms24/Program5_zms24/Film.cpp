/*
 * Film.cpp
 *
 *  Created on: Oct 2, 2017
 *      Author: two
 */

#include "Film.h"

#include <iostream>
#include <iomanip>

using namespace std;

Film::Film( int anID, string aName, string aDescription, string aRating,
           int theRunningTime )
{
    id = anID;
    name = aName;
    description = aDescription;
    rating = stringToFilmRating( aRating );
    runningTime = theRunningTime;
}

Film::Film( int anID, string aName, string aDescription, FilmRating aRating,
           int theRunningTime )
{
    id = anID;
    name = aName;
    description = aDescription;
    rating = aRating;
    runningTime = theRunningTime;
}
;

string Film::getDescription( ) const
{
    return description;
}

string Film::getName( ) const
{
    return name;
}
int Film::getRunningTime( ) const
{
    return runningTime;
}

void Film::print( ) const
{
    cout << "Film title" << right << setw(10) << ": " << name << endl
         << "Film description" << right << setw(4) << ": " << description
         << endl
         << "Film running time" << right << setw(3) << ": " << runningTime
         << " mins" << endl
         << "Film rating" << right << setw(9) << ": " << rating << endl << endl;
}

void Film::setRunningTime( int filmRunningTime )
{
    runningTime = filmRunningTime;
}

void Film::setName( string theName )
{
    name = theName;
}

void Film::setDescription( string theDescription )
{
    description = theDescription;
}

FilmRating Film::stringToFilmRating( string stringRating )
{
    int const N_RATINGS = 6;
    string stringRatings[] = { "G", "PG", "PG-13", "NC-17", "R", "UNRATED" };
    FilmRating ratings[] = { G, PG, PG_13, NC_17, R, UNRATED };
    
    for( int i = 0; i < N_RATINGS; i++ )
        if( stringRating == stringRatings[i] )
            return ratings[i];
    
    return UNRATED;
}
string Film::filmRatingToString( FilmRating rating )
{
    int const N_RATINGS = 6;
    string stringRatings[] = { "G", "PG", "PG-13", "NC-17", "R", "UNRATED" };
    FilmRating ratings[] = { G, PG, PG_13, NC_17, R, UNRATED };
    
    for( int i = 0; i < N_RATINGS; i++ )
        if( rating == ratings[i] )
            return stringRatings[i];
    
    return "UNRATED";
}

int Film::stringToInt( string stringInt )
{
    return 0;
}
