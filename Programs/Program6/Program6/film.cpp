//
//  film.cpp
//  Program6
//
//  Created by zane saul on 10/30/17.
//  Copyright © 2017 zane saul. All rights reserved.
//

#include <iostream>
#include <iomanip>

#include "Film.h"
#include "Utils.h"
Film::Film( std::string aid, std::string aname,
            std::string adescription, std::string arunningTime,
            std::string arating ) {
    this->stringId = Utils::stringToInt( aid );
    this->name = aname;
    this->description = adescription;
    this->runningTime = Utils::stringToInt( arunningTime );
    this->rating = stringToFilmRating(arating);
}

Film::Film( int aID, std::string aName, std::string aDescription,
           int aRunningTime, FilmRating aRating) {
    id = aID;
    name = aName;
    description = aDescription;
    rating = aRating;
    runningTime = aRunningTime;
}

int Film::getId() const {
    return id;
}

std::string Film::getName() const {
    return name;
}

std::string Film::getDescription() const {
    return description;
}

int Film::getRunningTime() const {
    return runningTime;
}

void Film::print() {
    
    std::cout << "Film title" << std::right << std::setw(10) << ": "
              << name << std::endl
              << "Film description" << std::right << std::setw(4)
              << ": " << description << std::endl
              << "Film running time" << std::right << std::setw(3)
              << ": " << runningTime << " mins" << std::endl
              << "Film rating" << std::right << std::setw(9) << ": "
              << filmRatingToString( rating )
              << std::endl << std::endl;
}

FilmRating Film::stringToFilmRating( std::string stringRating){
    int const N_RATINGS = 6;
    std::string stringRatings[] = { "G", "PG", "PG-13", "NC-17", "R", "UNRATED" };
    FilmRating ratings[] = { G, PG, PG_13, NC_17, R, UNRATED };
    
    for( int i = 0; i < N_RATINGS; i++ )
        if( stringRating == stringRatings[i] )
            return ratings[i];
    
    return UNRATED;
}

std::string Film::filmRatingToString( FilmRating rating){
    int const N_RATINGS = 6;
    std::string stringRatings[] = { "G", "PG", "PG-13", "NC-17", "R", "UNRATED" };
    FilmRating ratings[] = { G, PG, PG_13, NC_17, R, UNRATED };
    
    for( int i = 0; i < N_RATINGS; i++ )
        if( rating == ratings[i] )
            return stringRatings[i];
    
    return "UNRATED";
}
