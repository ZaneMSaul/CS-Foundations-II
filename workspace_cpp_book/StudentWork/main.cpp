//============================================================================
// Name        : Searching and Sorting Red Box
// Author      : J. Alejandro Carrillo
// Completed   : Sep 17, 2017
// Copyright   : Your copyright notice
// Description : This program will display a set of film's information. It
// will sort them by the film's running time. Then will do a search by the
// film's rating and another search by the films rating and running time together
//============================================================================
#include <iostream>
#include <iomanip>																// Needed to use stream manipulators or to output formatting
#include <cctype>																// Needed to use tolower or touper functions
#include <string>																// Needed to use string objects
#include <vector>																// Needed to use vectors
using namespace std;

struct Film
{
	int id;               														// the unique id of the film
	string name;          														// the film's name
    string description;   														// the film's description
    int runningTime;      														// the film's running time in minutes <= 180
    int rating;           														// the film's rating, from the constant declarations
};

// Declare global constant
const int NUM= 10;
const int FILM_RATING_G       = 0;
const int FILM_RATING_PG      = 1;
const int FILM_RATING_PG_13   = 2;
const int FILM_RATING_R       = 3;
const int FILM_RATING_NC_17   = 4;
const int FILM_RATING_UNRATED = 5;

// Function Prototype
vector <Film> selectionSort(vector <Film> );
void display(vector <Film> );
int displayMenu();
vector <Film> findFilmsByRating(int, vector <Film> );
vector <Film> findFilmsByRatingAndRunningTime(int, int, vector <Film> );

int main()
{
	// Variable declaration
	char choice= 'y';
	int filmRate,																// Will hold the film's rating chosen by the user
		runTime;																// Will hold the film's running time chosen by the user
	vector <Film> info(NUM);

	// Film's information
	info[0].id= 0;
	info[0].name= "Hotel Rwanda";
	info[0].description= "Paul Rusesabagina a Hutu man must protect his family "
						 "and Tutsi people from the Rwandan genocide";
	info[0].runningTime= 122;
	info[0].rating= FILM_RATING_PG_13;

	info[1].id= 1;
	info[1].name= "Saving Private Ryan";
	info[1].description= "Captain John Miller takes his men behind enemy lines "
						 "to find Private James Ryan";
	info[1].runningTime= 169;
	info[1].rating= FILM_RATING_R;

	info[2].id= 2;
	info[2].name= "The God Father";
	info[2].description= "Mob drama, based on a Mario Puzo's novel, focuses\n"
			"****************** on the powerful Italian-American crime family of "
								"Don Vito Corleone";
	info[2].runningTime= 178;
	info[2].rating= FILM_RATING_R;

	info[3].id= 3;
	info[3].name= "Pulp Fiction";
	info[3].description= "(John Travolta) and (Samuel L. Jackson) are hitmen"
						 " with a penchant for philosophical discussions";
	info[3].runningTime= 178;
	info[3].rating= FILM_RATING_R;

	info[4].id= 4;
	info[4].name= "Taxi Driver";
	info[4].description= "A New York City cabbie is increasingly drawn\n********"
			"********** from reality as he dreams of cleaning up the filthy city";
	info[4].runningTime= 114;
	info[4].rating= FILM_RATING_R;

	info[5].id= 5;
	info[5].name= "Notebook";
	info[5].description= "In 1940s South Carolina, mill worker (Ryan Gosling)\n"
			"****************** and rich girl (Rachel McAdams) are desperately "
								"in love. But her parents don't approve";
	info[5].runningTime= 124;
	info[5].rating= FILM_RATING_PG_13;

	info[6].id= 6;
	info[6].name= "Citizen Kane";
	info[6].description= "A reporter is assigned to decipher newspaper magnate "
						 "Charles Foster Kane's dying words";
	info[6].runningTime= 119;
	info[6].rating= FILM_RATING_PG;

	info[7].id= 7;
	info[7].name= "The Shawshank Redemption";
	info[7].description= "A man is wrongly sentenced to a life term in prison,\n"
			"****************** where he experiences brutality of prison life, "
								"adapts, helps the warden, etc.";
	info[7].runningTime= 142;
	info[7].rating= FILM_RATING_R;

	info[8].id= 8;
	info[8].name= "The Lion King";
	info[8].description= "The adventures of the young lion Simba, the heir "
						 "of his father, The Jungle's King Mufasa";
	info[8].runningTime= 89;
	info[8].rating= FILM_RATING_G;

	info[9].id= 9;
	info[9].name= "Killer Joe";
	info[9].description= "A totally twisted deep-fried Texas redneck, "
						 "Trailer Park murder story";
	info[9].runningTime= 103;
	info[9].rating= FILM_RATING_NC_17;

	// Sort and display films by running time
	cout <<"*****************************Films in sorted order by running time*****************************\n";

	display(selectionSort(info));

	// Find and display films by rating
	display(findFilmsByRating(displayMenu(), info));

	// Let the user know we'll be doing now a more narrow search
	while(tolower(choice) == 'y')
	{
		cout <<"For a more narrow search you can also search films by their rating and running time\n";
		cout <<"Would you like to do a more narrow search? Press (Y) for yes or (N) for no: ";
		cin>> choice;

		if (tolower(choice) == 'y')
		{
			// Get running time input
			cout <<"Let's narrow your search by running time...\n";
			cout <<"**Up to what running time are the films you are looking for?**\n";
			cout <<"(Type it in minutes here): ";
			cin>> runTime;

			// Display menu's choice and get user's film rating
			filmRate= displayMenu();

			cout <<" with running time less than " <<runTime <<" minutes********************\n";

			// Find and display films by rating and running time
			display(findFilmsByRatingAndRunningTime(filmRate, runTime, info));

			choice= 'x';

		}//End If

		else if (tolower(choice) != 'n' && tolower(choice) != 'y')
		{
			cout <<"\nThe only correct options are (Y) or (N). Please try again\n\n";

			choice= 'y';

		}//End Else If

	}//End While Loop

	// Display a good bye message
	cout <<"\nThanks. Come back soon again, bye bye :)";

	return 0;

}//End Main=====================================================================

// This function execute a selection sort sorting the films by their running
// time in an ascending order.
vector <Film> selectionSort(vector <Film> films)
{
	// Declare local constant
	const int HOW_MANY= films.size();

	// Declare local variables
	int	minValue,																// Keeps track of the smaller number found in the vector in each loop iteration
		minValIn,																//Keeps track of the position that holds the smaller number in the vector as it search along
		i= 0;																	// Loop counter
	vector <Film> temp(HOW_MANY);												// Vector that will temporary hold a film's information when swapping of position with the
																				// one film with the smaller running time
	for (i; i < HOW_MANY-1; i++)
	{
		minValue= films[i].runningTime;
		minValIn= i;
		int j= i + 1;

		for (j; j < HOW_MANY; j++)
		{
			if (films[j].runningTime < minValue)
			{
				minValue= films[j].runningTime;
				minValIn= j;

			}//End If

		}//End inner For Loop

		temp[i]= films[i];
		films[i]= films[minValIn];
		films[minValIn]= temp[i];

	}//End outer For Loop

	return films;

}//End selectionSort function***************************************************

// This function will display the films information properly labeled of any
// vector of the Film structure.
void display(vector <Film> films)
{
	// Declare local constant
	const int HOW_MANY= films.size();											// Constant that will hold the size of the vector passed to the function

	// Declare local variables
	int i= 0;																	// Loop counter

	cout <<"\n";

	for (i; i < HOW_MANY; i++)
	{
		cout <<"Film title:        " <<films[i].name <<endl;
		cout <<"Film description:  " <<films[i].description <<endl;
		cout <<"Film running time: " <<films[i].runningTime <<endl;
		cout <<"Film rating: ";

		switch (films[i].rating)
		{
			case 0: cout <<"      G\n\n";
					break;
			case 1: cout <<"      PG\n\n";
					break;
			case 2: cout <<"      PG-13\n\n";
					break;
			case 3: cout <<"      R\n\n";
					break;
			case 4: cout <<"      NC-17\n\n";
					break;
			default: cout <<"     Unrated\n\n";

		}//End Switch

	}//End For Loop

}//End display function*********************************************************

// This function will display a menu of film's rating choice and get the user's
// film rating choice. It will also print the range of film's rating that will
// be displayed by the display function based on the user choice.
int displayMenu()
{
	// Declare local variables
	int filmRate;
	string rating;

	cout <<"Let's narrow your search by rating...\n";
	cout <<"**Up to which rating film are you looking for?**\n";
	cout <<"\t0 - Film rating (G)\n";
	cout <<"\t1 - Film rating (PG)\n";
	cout <<"\t2 - Film rating (PG-13)\n";
	cout <<"\t3 - Film rating (R)\n";
	cout <<"\t4 - Film rating (NC-17)\n";
	cout <<"\t5 - All available films regardless rating\n";
	cin>> filmRate;

	switch (filmRate)
	{
		case 0: cout <<"********************Films rated (G) or less****";
				break;
		case 1: cout <<"********************Films rated (PG) or less***";
				break;
		case 2: cout <<"******************Films rated (PG-13) or less**";
				break;
		case 3: cout <<"********************Films rated (R) or less****";
				break;
		case 4: cout <<"******************Films rated (NC-17) or less**";
				break;
		default: cout <<"*********All available films regardless ratingUnrated**";
	}//End Switch

	return filmRate;

}//End displayMenu function*****************************************************

// This function execute a linear search in a passed by value vector of a Film
// structure which search and return the set of films that have a rating of the
// specified rating, also passed by value, or less.
vector <Film> findFilmsByRating(int rating, vector <Film> films)
{
	// Declare local variables
	int	howMany= films.size(),													// Will hold the size of the vector passed to the function
		valInde= howMany - 1;													// Will hold the index of the last value of the vector

//This for loop will iterate once for each value, to see if each one fulfill with the conditions
	for (valInde; valInde >= 0; valInde--)
	{
		if (films[valInde].rating > rating)										// If the value doesn't fulfill with the conditions
		{
// Counter loop, will be equal to the index of the element that's being tested
			int i= valInde;

			for (i; i < howMany-1; i++)											// will be substituted by scrolling the values after it that do fulfill the requirements
				films[i]= films[i+1];

			films.pop_back();													// then the last element of the vector will be removed with the pop_back function and
			howMany--;															// the howMany variable will be subtracted by one since the vector now has one less element

		}//End If

	}//End outer For Loop

	return films;

}//End findFilmsByRating function***********************************************

// This function execute a linear search in a passed by value vector of a Film
// structure which return the set of films that have a rating of the specified
// rating or less and the specified running time or less, both also passed by value
vector <Film> findFilmsByRatingAndRunningTime(int rating, int runningTime, vector <Film> films)
{
	// Declare local variables;
		int	howMany= films.size(),												// Will hold the size of the vector passed to the function
			valInde= howMany - 1;												// Will hold the index of the last value of the vector

//This for loop will iterate once for each value, to see if each one fulfill with the conditions
		for (valInde; valInde >= 0; valInde--)
		{
			if ((films[valInde].rating > rating) || (films[valInde].runningTime > runningTime))// If the value doesn't fulfill with the conditions
			{
// Counter loop, will be equal to the index of the element that's being tested
				int i= valInde;

				for (i; i < howMany-1; i++)										// will be substituted by scrolling the values after it that do fulfill the requirements
					films[i]= films[i+1];

				films.pop_back();												// then the last element of the vector will be removed with the pop_back function and
				howMany--;														// the howMany variable will be subtracted by one since the vector now has one less element

			}//End If

		}//End outer For Loop

		return films;

}//End findFilmsByRatingAndRunningTime function




