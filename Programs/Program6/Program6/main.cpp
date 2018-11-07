 /*
 Write a C++ program, Films and Actors that extends the program Actors that you
 will be given. This assignment is very like Assignment 5, but you will add more
 functionality and you will observe the style guide which we have discussed in
 previous classes.
 
 Films and Actors will add a classes Film, FilmCatalog, and Utils to the program
 Actors.
 
 Film Class
 Film will have the following attributes:
 
 int id; // the unique id of the film
 string name; // the film's name
 string description; // the film's description
 int runningTime; // the film's running time in minutes <= 180
 FilmRating rating; // the film's rating, from the enum FilmRating
 
 Also define the enum FilmRating; you can place the enum definition in the
 header file of Film;
 
 enum FilmRating {G, PG, PG_13, NC_17, R, UNRATED};
 
 The film class should be defined using a separate Film.h file for all
 declarations, e.g., attributes and method prototypes. The Film.cpp file will
 include the implementation of the methods.
 Define the following methods for Film
 
 A constructor that has the signature
 Film (string id, string name, string description,
 string runningTime, string rating);
 This constructor should assign the parameters to the appropriate attributes of
 the class. Use the this notation., for example:
 
 Film (string id, string name, string description …) {
 …
 this->name = name;
 }
 
 Note: you will need to write helper methods to convert string parameters to
 their appropriate types in order to assign them to Film’s attributes.
 
 A second constructor that has the signature
 Film (int id, string name, string description,
 int runningTime, FilmRating rating);
 
 Include a method print that will print the attributes of Film nicely. This
 should include the FilmRating attribute as a string;
 
 Create getters (only) for all attributes.
 
 
 
 FilmCatalog Class
 
 
 
 FilmCatalog will have the following attributes:
 
 std::string inputFile; // the name of the file to read from
 std::vector<Film*> films; // a vector of pointer to films
 bool isInitialized; // a flag to indicate the films were read
 
 
 Define the following methods for FilmCatalog
 
 A constructor that has the signature
 
 FilmCatlog (const string inputFile);
 
 A destructor that cleans up all the film objects on the heap and has the
 signature
 
 virtual ~FilmCatlog ();
 
 
 
 Methods that utilize methods in vector:
 
 void add (Film *) // adds a Film to the catalog
 
 void clear () // deletes all Films from catalog
 
 Film *get(int index) // returns the film at the index
 
 int size () // returns the size of the catalog
 
 
 
 
 A private initialize method that reads the data from the inputFile
 
 void initialize()
 
 Assume a just-in-time approach to initialization: determine which methods
 should call the initialize method
 
 
 Important Note: the get method for ActorInventory and FilmCatalog should return
 the object at the specified index value – 1. The index is the id of the object;
 ids are numbered 1 .. n. The vector numbers contents 0 .. n-1. Your program
 will need to make adjustments.
 Also: check for index out of bounds and return a null pointer if index isn’t in
 range.
 
 Utils Class
 The Utils class should have a constructor which is private, i.e., the class
 should never be instantiated. Utils will have one static method: stringToInt
 
 static int stringToInt (std::string aString)
 
 This method should be used to convert strings to integers for your Actor and
 Film classes.
 
 Extend the Main Routine
 
 
 Write a main routine that does the following:
 Defines a vector of films
 Reads a comma delimited file of data that will be supplied to you on 1000 films
 Creates new Film objects from the data and adds them to the vector
 Prints all the Films in the vector after reading all the data from the file.
 */
/*
 * Main.cpp
 *
 *  Created on: Oct 5, 2017
 *   Author: Patricia Carando
 *
 *   Actors program represents a common pattern in object-oriented programming:
 *   a set of objects (Actor) is managed by another object (ActorInventory). The
 *   manager of the set includes a vector where the Actor objects are stored. The
 *   ActorInventory exposes a small set of the methods of vector to allow any client
 *   of ActoryInventory to perform some operations on the collection, e.g., add, get
 *   elements of the collection.
 *
 *   Note: We will use the styles illustrated here for the rest of the course:
 *   1. No "using namespace std" any longer. When employing elements of namespace
 *      std, the elements will be scoped, e.g., std::cout
 *   2. We'll allocate objects on the heap, not on the stack Actor *actor = new Actor ...
 *        Not: Actor actor;
 *   3. We'll used const wherever feasible and appropriate
 *
 */

#include <iostream>
#include <vector>
#include "Film.h"
#include "FilmCatalog.h"
#include "Utils.h"
#include "Actor.h"
#include "ActorInventory.h"


int main () {
    ActorInventory actorInventory ("actors.dat");
    FilmCatalog filmCatalog ("films.dat");
    
    int size = actorInventory.size();
    int sizeFilm = filmCatalog.size();
    
    std::vector<Film> films;
    
    std::cout << "ActorInventory now contains " << size << "  elements"
              << std::endl;
    std::cout << "FilmCatalog now contains " << sizeFilm << "  elements"
              << std::endl;

    for (int i=1; i<=size; i++) {
        Actor *actor = actorInventory.get(i);
        actor->print();
    }
   
    for (int i=1; i<=sizeFilm; i++) {
        Film *film = filmCatalog.get(i);
        film->print();
    }

    actorInventory.clear();
    filmCatalog.clear();
    
    size = actorInventory.size();
    sizeFilm = filmCatalog.size();
    
    std::cout << "ActorInventory now contains " << size << "  elements"
              << std::endl;
    
    std::cout << "FilmCatalog now contains " << size << "  elements"
              << std::endl;
}

