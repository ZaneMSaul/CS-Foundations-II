/*
 * Film.h
 *
 *  Created on: Oct 2, 2017
 *    
 */

#ifndef FILM_H_
#define FILM_H_

#include <string>

using namespace std;

enum FilmRating {
    G, PG, PG_13, NC_17, R, UNRATED
};

class Film
{
    private:
        int id;
        string name;
        string description;
        FilmRating rating;
        int runningTime;
        int stringToInt( string );
        FilmRating stringToFilmRating( string );
        string filmRatingToString( FilmRating );
    
    public:
        Film( int id, string name, string description, string rating,
              int runningTime );
        Film( int id, string name, string description, FilmRating rating,
              int runningTime );
    
        string getName() const;
        string getDescription() const;
    
        int getRunningTime() const;
    
        void print() const;
        void setName( string name );
        void setDescription( string description );
        void setRunningTime( int runningTime );
    
};

#endif /* FILM_H_ */
