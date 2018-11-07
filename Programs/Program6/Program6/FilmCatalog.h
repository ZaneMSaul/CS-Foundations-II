//
//  FilmCatalog.h
//  Program6
//
//  Created by zane saul on 10/27/17.
//  Copyright © 2017 zane saul. All rights reserved.
//

#include <vector>
#include <string>

#ifndef FilmCatalog_h
#define FilmCatalog_h

class FilmCatalog{
private:
    std::string inputFile; // the name of the file to read from
    std::vector <Film*> films; // a vector of pointer to films
    bool isInitialized = false; // a flag to indicate the films were read
    
    void initialize ();
    int stringToint (std::string aString);
public:
    FilmCatalog( const std::string inputFile );

    void add( Film * ); // adds a Film to the catalog
    void clear( ); // deletes all Films from catalog
    Film *get(int index); // returns the film at the index
    int size (); // returns the size of the catalog

    
    virtual ~FilmCatalog( );
};

#endif /* FilmCatalog_h */
