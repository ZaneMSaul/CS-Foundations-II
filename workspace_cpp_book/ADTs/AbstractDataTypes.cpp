/*
 * Stoltenberg_Assignment3.cpp
 *
 *  Created on: Sep 17, 2017
 *      Author: Daniel Stoltenberg
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

struct Film {
	int id;
	string name;
	string description;
	int runningTime;
	int rating;
};

//constant global film ratings
const int FILM_RATING_G              = 0;
const int FILM_RATING_PG            = 1;
const int FILM_RATING_PG_13      = 2;
const int FILM_RATING_R              = 3;
const int FILM_RATING_NC_17      = 4;
const int FILM_RATING_UNRATED = 5;

//Function Prototypes
vector<Film> selectionSort(vector<Film>);
vector<Film> findFilmsByRating(int, vector<Film>);
vector<Film> findFilmsByRatingAndRunningTime(int, int, vector<Film>);
string              filmRatingToString(int);
void               printFilm(Film);
void               printFilms(vector<Film>);

int main() {
	vector<Film> films(10);

	//populating my empty vector with film structs

	films[0].id = 0;
	films[0].name = "Dr. Strangelove";
	films[0].description = "How I learned to Stop Worrying and Love the Bomb";
	films[0].runningTime = 95;
	films[0].rating = FILM_RATING_PG;

	films[1].id = 1;
	films[1].name = "The Princess Bride";
	films[1].description = "Will farm boy Wesley win the girl?";
	films[1].runningTime = 98;
	films[1].rating = FILM_RATING_PG;

	films[2].id = 2;
	films[2].name = "Ichi the Killer";
	films[2].description = "The tale of Ichi, a repressed and psychotic killer";
	films[2].runningTime = 129;
	films[2].rating = FILM_RATING_R;

	films[3].id = 3;
	films[3].name = "Kids";
	films[3].description = "A bunch of terrible kids doing stupid awful things";
	films[3].runningTime = 91;
	films[3].rating = FILM_RATING_UNRATED;

	films[4].id = 4;
	films[4].name = "Blue is the Warmest Color";
	films[4].description = "A coming of age tale with lots of nudity";
	films[4].runningTime = 180;
	films[4].rating = FILM_RATING_NC_17;

	films[5].id = 5;
	films[5].name = "Predator";
	films[5].description = "Arnold beats up an Alien.  Get to da choppa!!!!";
	films[5].runningTime = 107;
	films[5].rating = FILM_RATING_PG_13;

	films[6].id = 6;
	films[6].name = "Train to Busan";
	films[6].description =
			"A girl and her father are aboard a train during the Zombie Apocalypse!";
	films[6].runningTime = 118;
	films[6].rating = FILM_RATING_UNRATED;

	films[7].id = 7;
	films[7].name = "Oldboy";
	films[7].description =
			"After being imprisoned for fifteen years, Oh Dae-Su is released";
	films[7].runningTime = 120;
	films[7].rating = FILM_RATING_R;

	films[8].id = 8;
	films[8].name = "The Lord of the Rings: The Return of the King";
	films[8].description =
			"Hobbits drop the ring in Mt. Doom.  Eowyn kicks Nazgul ass.";
	films[8].runningTime = 201;
	films[8].rating = FILM_RATING_PG_13;

	films[9].id = 9;
	films[9].name = "Get Out";
	films[9].description =
			"A young african-american meets his white girlfriend's parents, and its spooky!!!";
	films[9].runningTime = 104;
	films[9].rating = FILM_RATING_R;

	//testing all the functions
	printFilm(films[0]);
	vector<Film> ascending;
	vector<Film> rating;
	vector<Film> ratingAndRunTime;
	ascending = selectionSort(films);
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "	Printing Films in Ascending Order by Run Time \n";
	printFilms(ascending);
	rating = findFilmsByRating(2, ascending);
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "	Printing Films by Rating, PG-13 or lower \n";
	printFilms(rating);
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "	Printing Films by Rating, R or lower and Run Time < 120 minutes \n";
	ratingAndRunTime = findFilmsByRatingAndRunningTime(3, 120, ascending);
	printFilms(ratingAndRunTime);

	return 0;
}
//sorts a vector of film structs in ascending order by run time.
vector<Film> selectionSort(vector<Film> films) {
	vector<Film> sortedFilms = films;
	unsigned startScan;
	int minIndex, minValue;
	Film temp;
	for (startScan = 0; startScan < (sortedFilms.size() - 1); startScan++) {
		minIndex = startScan;

		minValue = sortedFilms[startScan].runningTime;

		for (unsigned index = startScan + 1; index < sortedFilms.size();
				index++) {
			if (sortedFilms[index].runningTime < minValue) {
				minValue = sortedFilms[index].runningTime;
				minIndex = index;
				temp = sortedFilms[index];
			}
		}
		sortedFilms[minIndex] = sortedFilms[startScan];
		sortedFilms[startScan] = temp;

	}
	return sortedFilms;

}
//searches a vector of film structs for films of rating <= given rating
vector<Film> findFilmsByRating(int rating, vector<Film> films) {
	vector<Film> searchFilm; //vector to pass back

	unsigned index = 0;

	Film temp; //temporary struct to pushback onto new vector

	while (index < films.size()) {
		if (films[index].rating <= rating) {

			temp = films[index];

			searchFilm.push_back(temp);
		}
		index++;
	}

	return searchFilm;

}
//searches a vector of film structs for films of rating and runtime <= given rating and runtime
vector<Film> findFilmsByRatingAndRunningTime(int rating, int runningTime, vector<Film> films) {
		vector<Film> searchFilm; //vector to pass back

		unsigned index = 0;

		Film temp; //temporary struct to pushback onto new vector

		while (index < films.size()) {
			if ((films[index].rating <= rating) and (films[index].runningTime <= runningTime))
			{

				temp = films[index];

				searchFilm.push_back(temp);
			}
			index++;
		}

		return searchFilm;

}
//converts the globabl constant film ratings values to readable strings
string filmRatingToString(int rating) {

	string movieRating;

	if (rating == 0) {
		movieRating = "G";
	} else if (rating == 1) {
		movieRating = "PG";
	} else if (rating == 2) {
		movieRating = "PG 13";
	} else if (rating == 3) {
		movieRating = "R";
	} else if (rating == 4) {
		movieRating = "NC-17";
	} else if (rating == 5) {
		movieRating = "Unrated";
	}
	return movieRating;

}
//prints out a film struct from a vector of film structs
void printFilm(Film film) {
	string rating;

	rating = filmRatingToString(film.rating);

	cout << "\nFilm ID: " << film.id;
	cout << "\nFilm Name: " << film.name;
	cout << "\nFilm Description: " << film.description;
	cout << "\nFilm Run Time: " << film.runningTime << " minutes";
	cout << "\nFilm Rating: " << rating << "\n";

}
//prints out all of the film structs from a vector of film structs
void printFilms(vector<Film> films) {
	for (unsigned index = 0; index < films.size(); index++) {
		printFilm(films[index]);
	}

}
