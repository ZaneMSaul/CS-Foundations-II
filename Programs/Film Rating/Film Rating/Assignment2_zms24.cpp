/*
 File: Assignment2_zms24.cpp
 
 Author: Zane Saul
 C.S.2308.004
 Program: #2
 09/13/17
 
 Programming  Assignment  2

 Write a C++ program that will perform operations on a vector of structs.
 The struct is named Film and is defined as follows:



 struct Film {
    
    int id;               // the unique id of the film
    
    string name;          // the film's name
    
    string description;   // the film's description
    
    int runningTime;      // the film's running time in minutes <= 180
    
    int rating;           // the film's rating, from the const decls
    
 };



 Where runningTime is a value between 10 and 180 and rating is a value within 
 the range of the following constants:



 const int FILM_RATING_G       = 0;

 const int FILM_RATING_PG      = 1;

 const int FILM_RATING_PG_13   = 2;

 const int FILM_RATING_R       = 3;

 const int FILM_RATING_NC_17   = 4;

 const int FILM_RATING_UNRATED = 5;



 Both the struct and the constants are in the global scope.

 Your program should perform the following operations:

 Initialize a vector of Film with at least 10 elements; use any film names, 
 ratings, running times, and descriptions you like, real or imagined. Print the 
 results from your original definition. See an example at the end of this 
 document.
 
 Using a selection sort, sort the film elements into ascending order according 
 to their running time. Print the results, properly labeled.
 The signature of your selection sort function should be
 vector <Film> selectionSort (vector <Film> films)

 Using a linear search function, findFilmsByRating, return the set of films that 
 have a rating of the specified rating or less. Print the result, properly 
 labeled.
 For example, a call to findFilmsByRating  with a parameter of FILM_RATING_PG_13 
 should return all films with rating PG 13, PG, and G.
 The signature for your function should be
 vector <Film> findFilmsByRating ( int rating, vector <Film> films)

 Using a linear search function,  findFilmsByRatingAndRunningTime, return the 
 set of films that have a rating of the specified rating or less and the 
 specified running time or less.  Print the result, properly labeled.
 For example, a call to findFilmsByRatingAndRunning time with parameters of 
 FILM_RATING_PG_13 and 90 should return all films with rating PG 13, PG, and G 
 and a running time of 90 minutes or less.
 The signature for your function should be
 vector <Film> findFilmsByRatingAndRunningTime ( int rating, int runningTime, 
 vector <Film> films)


 Define and use the following “helper” functions in your program
 1.

 2.

 3.



 Questions and Issues Regarding This Assignment

 You will have until the end of the week (Friday 9/15 at 5pm) to raise any 
 questions or issues that you have with this assignment. These are best raised 
 on Slack. Responses will be posted on TRACS and Slack.


 Following the question period, I will assume you have sufficient information to 
 implement the program solution. At that point, you should refer to the 
 assignment instructions.

 Example: Assignment for Vector of 4 films



 films[0].id = 0;

 films[0].name = "Under World";

 films[0].description = "Vampires vs. Werewolves";

 films[0].runningTime = 134;

 films[0].rating = FILM_RATING_R;



 films[1].id = 1;

 films[1].name = "Bambi";

 films[1].description = "A young deer grows up";

 films[1].runningTime = 70;

 films[1].rating = FILM_RATING_G;



 films[2].id = 2;

 films[2].name = "Blade Runner";

 films[2].description =

 "A Blade Runner must pursue and try to terminate four replicants";

 films[2].runningTime = 117;

 films[2].rating = FILM_RATING_R;



 films[3].id = 3;

 films[3].name = "Limitless";

 films[3].description =

 "A mysterious pill helps a man use 100% of his brain";

 films[3].runningTime = 105;

 films[3].rating = FILM_RATING_PG_13;



 Example 2: Results from Invocations of sort and search functions



 ******Films in sorted order by running time *****

 Film title          : Bambi

 Film description    : A young deer grows up

 Film running time   : 70 minutes

 Film rating         : G



 Film title          : Limitless

 Film description    : A mysterious pill helps a man use 100% of his brain

 Film running time   : 105 minutes

 Film rating         : PG 13



 Film title          : Blade Runner

 Film description    : A Blade Runner must pursue and try to terminate four 
                       replicants

 Film running time   : 117 minutes

 Film rating         : R



 Film title          : Under World

 Film description    : Vampires vs. Werewolves

 Film running time : 134 minutes

 Film rating       : R



 ******Films rated PG 13 or less *****

 Film title          : Bambi

 Film description    : A young deer grows up

 Film running time   : 70 minutes

 Film rating         : G



 Film title          : Limitless

 Film description    : A mysterious pill helps a man use 100% of his brain

 Film running time   : 105 minutes

 Film rating         : PG 13



 ******Films rated PG 13 or less with running time < 90 *****

 Film title          : Bambi

 Film description    : A young deer grows up

 Film running time   : 70 minutes

 Film rating         : G
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <iomanip>

using namespace std;

const int FILM_RATING_G = 0,
          FILM_RATING_PG = 1,
          FILM_RATING_PG_13 = 2,
          FILM_RATING_R = 3,
          FILM_RATING_NC_17 = 4,
          FILM_RATING_UNRATED = 5,
          SIZE = 10;

struct Film
{
    int id;               // the unique id of the film
    
    string name;          // the film's name
    
    string description;   // the film's description
    
    int runningTime;      // the film's running time in minutes <= 180
    
    int rating;           // the film's rating, from the const decls
    
};

vector <Film> selectionSort ( vector <Film> films );
vector <Film> findFilmsByRating ( int rating, vector <Film> films );
vector <Film> findFilmsByRatingAndRunningTime ( int rating, int runningTime,
                                                vector <Film> films );
void printResults( vector <Film> films, int i );
string determineRating( int i );

int main( )
{
    int rating,
        runningTime;
    
    string srating; // string version of rating
    
    /*
     Initialize a vector of Film with at least 10 elements; use any film names,
     ratings, running times, and descriptions you like, real or imagined.
     */
    
    vector<Film> films( SIZE );
    vector<Film> temporary;
    
    films[0].id = 0;
    films[0].name = "Transformers";
    films[0].description = "The Last Knight";
    films[0].runningTime = 154;
    films[0].rating = FILM_RATING_PG_13;
    
    films[1].id = 1;
    films[1].name = "Wonder Woman";
    films[1].description = "Wonder Woman";
    films[1].runningTime = 141;
    films[1].rating = FILM_RATING_PG_13;
    
    films[2].id = 2;
    films[2].name = "The Mummy";
    films[2].description = "The Mummy";
    films[2].runningTime = 110;
    films[2].rating = FILM_RATING_PG_13;
    
    films[3].id = 3;
    films[3].name = "The Last Witch Hunter";
    films[3].description = "Live Forever Hunt Forever";
    films[3].runningTime = 106;
    films[3].rating = FILM_RATING_PG_13;
    
    films[4].id = 4;
    films[4].name = "Dracula Untold";
    films[4].description = "Dracul Untold";
    films[4].runningTime = 92;
    films[4].rating = FILM_RATING_PG_13;
    
    films[5].id = 5;
    films[5].name = "Guadians of the Galaxy";
    films[5].description = "Vol. 2";
    films[5].runningTime = 136;
    films[5].rating = FILM_RATING_PG_13;
    
    films[6].id = 6;
    films[6].name = "The Purger: Election Year";
    films[6].description = "Election year";
    films[6].runningTime = 98;
    films[6].rating = FILM_RATING_R;
    
    films[7].id = 7;
    films[7].name = "Prometheus";
    films[7].description = "Promethius";
    films[7].runningTime = 124;
    films[7].rating = FILM_RATING_R;
    
    films[8].id = 8;
    films[8].name = "Looper";
    films[8].description = "Looper";
    films[8].runningTime = 118;
    films[8].rating = FILM_RATING_R;
    
    films[9].id = 9;
    films[9].name = "Resident Evil";
    films[9].description = "Resident Evil";
    films[9].runningTime = 90;
    films[9].rating = FILM_RATING_R;
    
    /*
     Print the results from your original definition. See an example at the end
     of this document.
     */
    
    for( int i = 0; i < SIZE; i++)
        printResults( films, i );
    
    /*
     Using a selection sort, sort the film elements into ascending order 
     according to their running time. Print the results, properly labeled.
     The signature of your selection sort function should be
     vector <Film> selectionSort (vector <Film> films)
     */
    
    cout << "Sorting films by run time in ascending order:" << endl << endl;
    
    films = selectionSort( films );
    
    for( int i = 0; i < SIZE; i++ )
        printResults( films, i );

    cout << "Sort complete." << endl << endl << endl;
    
    /*
     Using a linear search function, findFilmsByRating, return the set of films 
     that have a rating of the specified rating or less. Print the result, 
     properly labeled. For example, a call to findFilmsByRating  with a 
     parameter of FILM_RATING_PG_13 should return all films with rating PG 13, 
     PG, and G. The signature for your function should be:
     vector <Film> findFilmsByRating ( int rating, vector <Film> films)
     */
    
    cout << "Searching for films with a rating of at most PG-13:" << endl
         << endl << endl;
    rating = FILM_RATING_PG_13;
    
    temporary = findFilmsByRating( rating, films );
    
    for( int i = 0; i < temporary.size(); i++ )
        printResults( temporary, i);
    
    cout << "Search complete." << endl << endl << endl;
    
    /*
     Using a linear search function,  findFilmsByRatingAndRunningTime, return
     the set of films that have a rating of the specified rating or less and the
     specified running time or less.  Print the result, properly labeled.
     For example, a call to findFilmsByRatingAndRunning time with parameters of
     FILM_RATING_PG_13 and 90 should return all films with rating PG 13, PG, and 
     G and a running time of 90 minutes or less.
     The signature for your function should be
     vector <Film> findFilmsByRatingAndRunningTime ( int rating, 
     int runningTime,  vector <Film> films)
     */
    
    srating = determineRating( 2 );
    runningTime = 90;
    rating = FILM_RATING_PG_13;
    
    cout << "Searching for Films with a rating of at most " << srating
         << " and a running time of " << runningTime << " mins or less:"<< endl
         << endl;
    
    temporary = findFilmsByRatingAndRunningTime( 2, 90, films );
    
    for( int i = 0; i < temporary.size(); i++ )
        printResults( temporary, i );

    cout << "Search Complete." << endl << endl << endl;
    
    system("PAUSE>NUL");
    
    return 0;
}

/*
 Function: selectionSort
 
 The funtion, selectionSort, rearranges the vector films into acsending order 
 based on the running time of the movie. Then returns the correctly arranged 
 vector to main.
 
 Receives: vector <Film> films
 Constants: Global Const SIZE
 Returns: vector <Film> films
 */

vector <Film> selectionSort( vector <Film> films )
{
        for( int i = 0; i < SIZE; i++ )
        {
            for( int z = i; z < SIZE; z++ )
            {
                Film temp;
                
                if( films[i].runningTime > films[z].runningTime )
                {
                    temp = films[i];
                    films[i] = films[z];
                    films[z] = temp;
                }
            }
        }
    
    return films;
}

/*
 Function: findFilmsByRating
 
 The function, findFilmsByRating, is called to locate films with specific rating
 or less. It will then print to screen the films located.
 
 Receives: vector <Film> films
 Constants: Global Const int SIZE
 Returns: films?(useless and no usefull way to return a smaller vector without
                 having garbage in extra index locations. Fuction should be 
                 void.)
 */

vector <Film> findFilmsByRating ( int rating, vector <Film> films )
{
    bool check = false;
    
    vector<Film> temporary;
    
    for( int i = 0; i < SIZE; i++ )
        if( films[i].rating <= rating )
        {
            temporary.push_back(films[i]);
            check = true;
        }
    
    if( check == false )
        cout << "Could not find a film matching your discription." << endl
        << endl;
    
    return temporary;
}

/*
 Function: findFilmsByRatingAndRunningTime
 
 The function, findFilmsByRatingAndRunningTime, is called to locate and print 
 films within a specified running time and rating.
 
 Receives: int rating, int runningTime, vector <Film> films
 Constants: Global Const SIZE
 Returns: films
 */

vector <Film> findFilmsByRatingAndRunningTime ( int rating, int runningTime,
                                               vector <Film> films )
{
    bool check = false;
    
    vector<Film> temporary;
    
    for( int i = 0; i < SIZE; i++ )
        if( films[i].rating <= rating && films[i].runningTime <= runningTime )
        {
            temporary.push_back(films[i]);
            check = true;
        }
    if( check == false )
        cout << "Could not find a film matching your discription." << endl
             << endl;
    
    return temporary;
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
 
 Recieves: vector <Film> films, int i
 Constants: None
 Returns: Nothing, prints to screen.
 */

void printResults( vector <Film> films, int i )
{
    string rating;
    
        rating = determineRating( films[i].rating );
    
        cout << "Film title" << right << setw(10) << ": " << films[i].name
             << endl
             << "Film description" << right << setw(4) << ": "
             << films[i].description << endl
             << "Film running time" << right << setw(3) << ": "
             << films[i].runningTime << " mins" << endl
             << "Film rating" << right << setw(9) << ": " << rating << endl
             << endl;
}

/*
 Function: determineRating
 
 The function, determinRating, is called to make a string value equal to the 
 Global Const ints for the different ratings. It will return the string value so
 that it may be printed.
 
 FILM_RATING_G = 0      rating = G
 
 Recieves: int i
 Constants: None
 Returns: string rating
 */

string determineRating( int i )
{
    string rating;
    
    if( i == 0 )
        rating = "G";
    else if( i == 1 )
        rating = "PG";
    else if( i == 2 )
        rating = "PG-13";
    else if( i == 3 )
        rating = "R";
    else if( i == 4 )
        rating = "NC-17";
    else if( i == 5 )
        rating = "Unrated";
    else
        rating = "Unkown";
    
    return rating;
}
