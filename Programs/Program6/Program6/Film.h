//
//  Film.h
//  Program6
//
//  Created by zane saul on 10/27/17.
//  Copyright © 2017 zane saul. All rights reserved.
//

#ifndef Film_h
#define Film_h

#include <string>

enum FilmRating {G, PG, PG_13, NC_17, R, UNRATED};

class Film{
private:
    int id; // the unique id of the film
    std::string stringId;
    std::string stringRunningTime;
    std::string stringRating;
    std::string name; // the film's name
    std::string description; // the film's description
    int runningTime; // the film's running time in minutes <= 180
    FilmRating rating; // the film's rating, from the enum FilmRating
    FilmRating stringToFilmRating( std::string );
    std::string filmRatingToString( FilmRating );
    
public:
    Film( std::string id, std::string name, std::string description,
          std::string runningTime, std::string rating );
    Film( int id, std::string name, std::string description,
          int runningTime, FilmRating rating);
    int getId() const;
    std::string getName() const;
    std::string getDescription() const;
    int getRunningTime() const;
    void print();
};

#endif /* Film_h */
