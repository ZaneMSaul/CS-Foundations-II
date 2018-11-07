/*
 * filmDoer.cpp
 *
 *  Created on: Sep 14, 2017
 *      Author: Quinn O'Connell
 */
#include "filmDoer.h"


/* FORWARD DECLARATIONS AND INCLUDES FROM .H JUST IN CASE
 *
 *
 * 	#include <string>
	#include <vector>
	#include <iostream>
	struct Film;

	vector <Film> selectionSort(vector <Film> films);
	vector <Film> findFilmsByRating(int rating,vector <Film> films);
	vector <Film> findFilmsByRatingAndRuningTime(int rating,int runningTime,vector <Film> films);
	void printFilm(Film toPrint);
	void printFilmList(vector <Film> listOfFilms);
	string convertRating(int numRate); */


using namespace std;



const int FILM_RATING_G       = 0;
const int FILM_RATING_PG      = 1;
const int FILM_RATING_PG_13   = 2;
const int FILM_RATING_R       = 3;
const int FILM_RATING_NC_17   = 4;
const int FILM_RATING_UNRATED = 5;


struct Film
	{
		int id;
		string name;
		string description;
		int runningTime;
		int rating;

	};




int main()
{

	// creates vector and calls on functions

	vector <Film> films ;
	films.push_back(Film());
    films[0].id = 0;
    films[0].name = "Under World";
    films[0].description = "Vampires vs. Werewolves";
    films[0].runningTime = 134;
    films[0].rating = FILM_RATING_R;

    films.push_back(Film());
    films[1].id = 1;
    films[1].name = "Bambi";
    films[1].description = "A young deer grows up";
    films[1].runningTime = 70;
    films[1].rating = FILM_RATING_G;



    films.push_back(Film());
    films[2].id = 2;
    films[2].name = "Blade Runner";
    films[2].description =
               "A Blade Runner must pursue and try to terminate four replicants";
    films[2].runningTime = 117;
    films[2].rating = FILM_RATING_R;



    films.push_back(Film());
    films[3].id = 3;
    films[3].name = "Limitless";
    films[3].description =
               "A mysterious pill helps a man use 100% of his brain";
   films[3].runningTime = 105;
   films[3].rating = FILM_RATING_PG_13;


   films.push_back(Film());
   films[4].id = 4;
   films[4].name = "Spirited Away";
   films[4].description= "A girl must find herself after being cast into a mysterious world.";
   films[4].runningTime=140;
   films[4].rating=FILM_RATING_PG;

   films.push_back(Film());
   films[5].id = 5;
   films[5].name = "Forest Gump";
   films[5].description= "The exceptional life story of a man from alabama named Forest";
   films[5].runningTime=142;
   films[5].rating=FILM_RATING_PG_13;


   films.push_back(Film());
   films[6].id = 6;
   films[6].name = "Die Hard";
   films[6].description= "A man must save the world from cyberterrorists (also christmas)";
   films[6].runningTime=132;
   films[6].rating=FILM_RATING_R;

   films.push_back(Film());
   films[7].id = 7;
   films[7].name = "The Imitation Game";
   films[7].description= "The story behind the process of cracking enigma";
   films[7].runningTime=114;
   films[7].rating=FILM_RATING_PG_13;

   films.push_back(Film());
   films[8].id = 8;
   films[8].name = "The Shining";
   films[8].description= "A man goes insane after he moves into a hotel with his family";
   films[8].runningTime=160;
   films[8].rating=FILM_RATING_R;

   films.push_back(Film());
   films[9].id = 9;
   films[9].name = "Yeah Right!";
   films[9].description=
		   "Considered the best Skateboarding footage/worst skits of all time, directed by Spike Jonze";
   films[9].runningTime=74;
   films[9].rating=FILM_RATING_UNRATED;

 cout<<"******Films in sorted order by running time *****\n";
   printFilmList(selectionSort(films));
   cout<<"\n******Films rated PG 13 or less *****";
  printFilmList(findFilmsByRating(2,films));
   cout<<"\n******Films rated PG 13 or less and runnning time <90*****";
   printFilmList(findFilmsByRatingAndRuningTime(2,90,films));
};

void printFilm(Film toPrint)
{
	//Helper function to condense film printing to one call
	cout<< "\nFilm title :: "<<toPrint.name<<"\n";
	cout<< "Film description :: "<<toPrint.description<<"\n";
	cout<<"Film running time :: "<<toPrint.runningTime<<"\n";
	cout<<"Film rating :: "<<convertRating(toPrint.rating);

	cout<<"\n";

}

string convertRating(int numRate)
{
	//Helper function to convert rating numbers to strings
		if(numRate==0)
			return "G";
		else if (numRate == 1)
			return "PG";
		else if(numRate == 2)
			return "PG-13";
		else if(numRate == 3)
			return "R";
		else if(numRate==4)
			return "NC-17";
		else if(numRate==5)
			return "Not Rated";
		else
		{
			return"Error getting rating";
		}
}

void printFilmList(vector <Film> listOfFilms)
{
	//prints out entire vector of films
	int size = listOfFilms.size();
	for(int x = 0;x<size;x++)
	{
		printFilm(listOfFilms[x]);
	}
}


vector <Film> selectionSort(vector <Film> films)
{
	//sorts by run time
	int a,b,c;
	Film temp;
	vector<Film> sorted;

	sorted=films;
	for(a = 0; a<sorted.size();a++)
	{
		c=a;
		for(b=a+1;b<sorted.size();b++)
		{
			if(sorted[b].runningTime<sorted[c].runningTime)
			{
				c=b;
			}
		}

	temp = sorted[a];
	sorted[a] = sorted[c];
	sorted[c] = temp;


	}
return sorted;

}

vector <Film> findFilmsByRating(int rating,vector <Film> films)
{
	//searches based off of rating
	vector <Film> meetsCrit;
	int count = 0;
	for(int loc = 0;loc<films.size();loc++)
	{
		if(films[loc].rating<=rating)
		{
			meetsCrit.push_back(Film());
			meetsCrit[count]=films[loc];
			count++;
		}
	}
	return meetsCrit;

}
vector <Film> findFilmsByRatingAndRuningTime(int rating,int runningTime,vector <Film> films)
{
	//searches based off rating and runtime
	vector <Film> meetsCrit;
		int count = 0;
		for(int loc = 0;loc<films.size();loc++)
		{
			if(films[loc].rating<=rating&&films[loc].runningTime<runningTime)
			{
				meetsCrit.push_back(Film());
				meetsCrit[count]=films[loc];
				count++;
			}
		}
		return meetsCrit;

}






















