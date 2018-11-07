//
//  FilmCatalog.cpp
//  Program6
//
//  Created by zane saul on 10/30/17.
//  Copyright © 2017 zane saul. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>

#include "Film.h"
#include "FilmCatalog.h"
#include "Utils.h"

void FilmCatalog::initialize(){
    if (isInitialized)
        return;
    
    std::ifstream filmsFile;   // file for reading data
    filmsFile.open(inputFile.c_str(), std::ios::in);
    std::string id;                            // id converted to int
    std::string name; // the film's name
    std::string description; // the film's description
    std::string runningTime; // the film's running time in minutes <= 180
    std::string stringRating;
    
    std::getline( filmsFile, id, ',' );
    while( filmsFile ) {
        
        std::getline( filmsFile, name, ',' );
        std::getline( filmsFile, description, ',' );
        std::getline( filmsFile, runningTime, ',' );
        std::getline( filmsFile, stringRating, ',' );
        //std::cout << runningTime << std::endl;
        id = stringToint( id );
        
        Film*film = new Film( id, name, description, runningTime,
                              stringRating);
        //film->print();//?
        
        films.push_back(film);//?
        
        std::getline(filmsFile, id, ',');
    }
    isInitialized = true;
}
int FilmCatalog::stringToint (std::string aString){
    std::stringstream geek(aString);
    int intValue;
    geek >> intValue;
    return intValue;
}
FilmCatalog::FilmCatalog( const std::string theInputFile ){
    inputFile = theInputFile;
}

void FilmCatalog::add( Film *film ){
    initialize();
    films.push_back( film );//?
}
void FilmCatalog::clear( ){
    for (auto film : films) {
        delete film;
    }
    films.clear();
}
Film * FilmCatalog::get(int index){
    int size = films.size();
    if (index < 1)
        return nullptr;
    if (index > size)
        return nullptr;
    return films.at(index - 1);
}
    
int FilmCatalog::size( ){
    initialize();
    return films.size();
}
FilmCatalog::~FilmCatalog( ){
    for (auto film : films) {
        delete film;
    }
    films.clear();
}
