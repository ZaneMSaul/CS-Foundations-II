/*
 File: Program4_zms24.cpp
 
 Author: Zane Saul
 C.S.2308.004
 Program: #4
 09/25/17

 Write a C++ program that will perform operations on a pointer array of structs.
 The struct is the same as Film from Assignment 2, but with a small difference:

 struct Film {
    int id; // the unique id of the film
    string name; // the film's name
    string description; // the film's description
    int runningTime; // the film's running time in minutes <= 180
    FilmRating rating; // the film's rating, from the enum FilmRating
 };

 enum FilmRating {G, PG, PG_13, NC_17, R, UNRATED};

 Both the struct and the enum are in the global scope.
 Your program should perform the following operations:

 Initialize an array pointer of Film with at least 4 elements; use any film
 names, ratings, running times, and descriptions you like, real or imagined.
 Print the results from your original definition using printFilms (see below) .
 See an example at the end of this document.
 Using dynamic memory allocation, write a function resize that conforms to the
 following signature
 Film * resize (Film *films, int currentSize, int newSize)
 This function should
 Allocate new memory in the indicated amount (newSize)
 Copy the elements in films into the newly allocated memory
 Delete the old films array memory
 Return the newly created array pointer memory
 
 Using dynamic memory allocation, write a function reverse that conforms to the
 following signature
 Film * reverse (Film *films, int currentSize)
 This function should
 Allocate new memory in the indicated amount (currentSize)
 Copy the elements in films into the newly allocated memory in reverse order

 Define and use the following “helper” functions in your program
 string filmRatingToString(FilmRating rating): Returns a readable version of the
 rating constant, e.g., with an input of G returns the string “G”;
 void printFilm (Film film): Prints the struct film to the console in a readable
 format,
 void printFilms (Film *films, int size): Prints a pointer array of structs in a
 readable format;
 
 Testing Your Program
 
 After initializing your pointer array with Films, print the films. Label the
 output appropriately
 
 Create a new pointer array of Films by performing a reverse call with the
 original array.
 
 Perform a resize on the Film pointer array, extending its size by 1. Add a new
 film at the end of the pointer array. Print the films. Label the output
 accordingly.
 
 Perform a resize on the Film pointer array, extending its size by 2. Add 2 new
 films at the end of the pointer array. Print the films. Label the output
 accordingly.
 
 Perform a resize on the Film pointer array, setting the size to 2. Print the
 films. Label the output accordingly.
 
 Questions and Issues Regarding This Assignment
 You will have until the end of the week (Tuesay 9/26 at 5pm) to raise any
 questions or issues that you have with this assignment. These are best raised
 on Slack. Responses will be posted on TRACS and Slack.
 
 Following the question period, I will assume you have sufficient information to
 implement the program solution. At that point, you should refer to the
 assignment instructions.
 Example: Assignment for Pointer Array of 4 films
 
 films[0].id = 0;
 films[0].name = "Under World";
 films[0].description = "Vampires vs. Werewolves";
 films[0].runningTime = 134;
 films[0].rating = R;
 
 films[1].id = 1;
 films[1].name = "Bambi";
 films[1].description = "A young deer grows up";
 films[1].runningTime = 70;
 films[1].rating = G;
 
 films[2].id = 2;
 films[2].name = "Blade Runner";
 films[2].description =
 "A Blade Runner must pursue and try to terminate four replicants";
 films[2].runningTime = 117;
 films[2].rating = R;
 
 films[3].id = 3;
 films[3].name = "Limitless";
 films[3].description = "A mysterious pill helps a man use 100% of his brain";
 films[3].runningTime = 105;
 films[3].rating = PG_13;
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <iomanip>

using namespace std;

enum FilmRating {G, PG, PG_13, NC_17, R, UNRATED};

struct Film
{
    int id; // the unique id of the film
    string name; // the film's name
    string description; // the film's description
    int runningTime; // the film's running time in minutes <= 180
    FilmRating rating; // the film's rating, from the enum FilmRating
};

void printFilms( Film *films, int i );
Film *resize( Film *films, int currentSize, int newSize );
Film *reverse( Film *films, int currentSize );
string filmRatingToString( FilmRating rating );
void printFilm( Film film );

int main( )
{
    int size = 4;
    int newSize = size;
    
    /*
     Initialize an array pointer of Film with at least 4 elements; use any film
     names, ratings, running times, and descriptions you like, real or imagined.
     */
    
    Film *films = new Film[4];
    
    films[0].id = 0;
    films[0].name = "Under World";
    films[0].description = "Vampires vs. Werewolves";
    films[0].runningTime = 134;
    films[0].rating = R;
    
    films[1].id = 1;
    films[1].name = "Bambi";
    films[1].description = "A young deer grows up";
    films[1].runningTime = 70;
    films[1].rating = G;
    
    films[2].id = 2;
    films[2].name = "Blade Runner";
    films[2].description = "A Blade Runner must pursue and try to terminate"
                           " four replicants";
    films[2].runningTime = 117;
    films[2].rating = R;
    
    films[3].id = 3;
    films[3].name = "Limitless";
    films[3].description = "A mysterious pill helps a man use 100% of his"
                           " brain";
    films[3].runningTime = 105;
    films[3].rating = PG_13;
    
    /*
     Print the results from your original definition using printFilms
     */
    
    printFilms( films, newSize );
    
    /*
     Using dynamic memory allocation, write a function reverse that conforms to
     the following signature
     Film * reverse (Film *films, int currentSize)
     This function should
     Allocate new memory in the indicated amount (currentSize)
     Copy the elements in films into the newly allocated memory in reverse order
    
     Create a new pointer array of Films by performing a reverse call with the
     original array.
     */
    
    cout << "Reorganizing..." << endl;
    films = reverse( films, size );
    cout << "Complete" << endl << endl;
    
    printFilms( films, size );
    
    /*
     Using dynamic memory allocation, write a function resize that conforms to
     the following signature
     Film * resize (Film *films, int currentSize, int newSize)
     This function should
     Allocate new memory in the indicated amount (newSize)
     Copy the elements in films into the newly allocated memory
     Delete the old films array memory
     Return the newly created array pointer memory
     */
    
    cout << "Adding a new movie." << endl;
    newSize = newSize + 1;
    
    films = resize( films, size, newSize );
    
    films[4].id = 4;
    films[4].name = "Doctor Strange";
    films[4].description = "The story of world-famous neurosurgeon Dr. Stephen "
                           "Strange";
    films[4].runningTime = 116;
    films[4].rating = PG_13;
    
    cout << "Complete" << endl << endl;
    
    size = newSize;
    printFilms( films, size );
    
    cout << "Adding 2 new movies." << endl;
    newSize = newSize + 2;
    
    films = resize( films, size, newSize );
    
    films[5].id = 5;
    films[5].name = "Ghost in the Shell";
    films[5].description = "An Action-packed adventure set in a future world "
                           "where people are enhanced.";
    films[5].runningTime = 108;
    films[5].rating = PG_13;

    films[6].id = 6;
    films[6].name = "Interstellar";
    films[6].description = "A story of a team of pioneers undertaking the most "
                           "important mission in human history.";
    films[6].runningTime = 170;
    films[6].rating = PG_13;
    
    cout << "Complete" << endl << endl;
    
    size = newSize;
    printFilms( films, size);
    
    /*
     Perform a resize on the Film pointer array, setting the size to 2. Print
     the films. Label the output accordingly.
     */
    
    cout << "Setting array size to 2" << endl;
    
    size = 2;
    newSize = size;
    
    films = resize( films, size, newSize );
    cout << "Complete" << endl << endl;
    
    printFilms( films, size );
    
    system("PAUSE>NUL");
    
    return 0;
}

/*
 Function: printResults
 
 The function, printResults, is called print all the values in the vector
 films. It will print the title, discription, run time, and rating
 respectively.
 
 Film title          : Bambi
 Film description    : A young deer grows up
 Film running time   : 70 minutes
 Film rating         : G
 
 Recieves: Film *films, int newSize
 Constants: None
 Returns: Nothing, prints to screen.
 */

void printFilms( Film *films, int newSize )
{
    string rating;
    
    cout << "Printing Films ..." << endl << endl;
    for( int i = 0; i < newSize; i++)
        printFilm ( films[i] );
    
    cout << "Complete" << endl << endl;
}

/*
 Function: resize
 
 The function, resize, Allocates new memory in the indicated amount (newSize)
 next copies the elements in films into the newly allocated memory and Deletes
 the old films array memory then return the newly created array pointer memory
 
 Receives: Film *films, int currentSize, int newSize
 Constants: None
 Returns: arrayNew
 */

Film *resize( Film *films, int currentSize, int newSize )
{
    Film * arrayNew = new Film[newSize];
    
    for( int i = 0; i < currentSize; i++ )
        arrayNew[i] = films[i];
    
    delete [] films;
    
    return arrayNew;
}

/*
 Function: reverse
 
 The function, reverse, Allocate new memory in the indicated amount currentSize
 Copy the elements in films into the newly allocated memory in reverse order
 
 Receives: Film *films, int currentSize
 Constants: None
 Returns: arrayNew
 */

Film *reverse( Film *films, int currentSize )
{
    Film * arrayNew = new Film[currentSize];
    
    int temporary1 = currentSize - 1;
    
    for( int i = 0; i < currentSize; i++ )
        arrayNew[i] = films[ temporary1 - i ];
    
    delete [] films;
    
    return arrayNew;
}

/*
 Function: filmRatingToString
 
 The function, filmRatingToString, Returns a readable version of the
 rating constant, e.g., with an input of G returns the string “G”
 
 Receives: FilmRating rating
 Constants: enum FilmRating
 Returns: result
 */

string filmRatingToString( FilmRating rating )
{
    string result;
    
    if( rating == 0 )
        result = "G";
    else if( rating == 1 )
        result = "PG";
    else if( rating == 2 )
        result = "PG_13";
    else if( rating == 3 )
        result = "NC_17";
    else if( rating == 4 )
        result = "R";
    else if( rating == 5 )
        result = "Unrated";
    
    return result;
}

/*
 Function: printFilm
 
 The function, printFilm, Prints the struct film to the console in a readable
 format,
 
 Receives: Film film
 Constants: None
 Returns: Nothing, Prints to screen
 */

void printFilm( Film film )
{
    string rating;
    
    rating = filmRatingToString( film.rating );
    
    cout << "Film title" << right << setw(10) << ": " << film.name
         << endl
         << "Film description" << right << setw(4) << ": "
         << film.description << endl
         << "Film running time" << right << setw(3) << ": "
         << film.runningTime << " mins" << endl
         << "Film rating" << right << setw(9) << ": " << rating << endl
         << endl;
}
