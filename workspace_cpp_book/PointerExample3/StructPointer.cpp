/*
 * StructPointer.cpp
 *
 *  Created on: Sep 21, 2017
 *      Author: two
 */

#include <string>
#include <iostream>
#include <fstream>
#include<vector>

using namespace std;

enum FilmRating {
	G, PG, PG_13, NC_17, R, UNRATED
};
struct Film {
	int id;                        // the unique id of the film
	string name;             // the film's name
	string description;   // the film's description
	int runningTime;     // the film's running time in minutes <= 180
	FilmRating rating;   // the film's rating
};

void printFilm(Film *film);
string filmRatingToString(FilmRating rating);

int main () {

    Film *film1 = new Film();
   	film1->id = 0;
   	film1->name = "Under World";
   	film1->description = "Vampires vs. Werewolves";
   	film1->runningTime = 134;
   	film1->rating = R;

}

void printFilm(Film *film) {
	cout << "Film title                : " << film->name << endl;
	cout << "Film description    : " << film->description << endl;
	cout << "Film running time : " << film->runningTime << " minutes" << endl;
	cout << "Film rating            : " << filmRatingToString(film->rating)
			<< endl << endl;
}

string filmRatingToString(FilmRating rating) {
	switch (rating) {
	case G:
		return "G";

	case PG:
		return "PG 13";

	case PG_13:
		return "PG 13";

	case NC_17:
		return "NC_17";

	case R:
		return "R";

	case UNRATED:
		return "U";

	default:
		return "U";
	}

	return "U";
}
