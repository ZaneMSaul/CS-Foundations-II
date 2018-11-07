/*
 * Main.cpp
 *
 *  Created on: Sep 20, 2017
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

const int COUNT = 4;

string filmRatingToString(FilmRating rating);
void printFilm(Film film);
void printFilms(vector<Film *> films);


int main() {

    vector<Film *> films(COUNT);

	for (int i = 0; i < COUNT; i++) {
		films[i] = new Film();
	}


	films[0]->id = 0;
	films[0]->name = "Under World";
	films[0]->description = "Vampires vs-> Werewolves";
	films[0]->runningTime = 134;
	films[0]->rating = R;

	films[1]->id = 1;
	films[1]->name = "Bambi";
	films[1]->description = "A young deer grows up";
	films[1]->runningTime = 70;
	films[1]->rating = G;

	films[2]->id = 2;
	films[2]->name = "Blade Runner";
	films[2]->description =
			"A Blade Runner must pursue and try to terminate four replicants";
	films[2]->runningTime = 117;
	films[2]->rating = R;

	films[3]->id = 3;
	films[3]->name = "Limitless";
	films[3]->description =
			"A mysterious pill helps a man use 100% of his brain";
	films[3]->runningTime = 105;
	films[3]->rating = PG_13;

	printFilms (films);



}

vector<Film> findFilmsByRating(int rating, vector<Film> films) {
	int size = films.size();
	vector<Film> foundFilms;
	for (int i = 0; i < size; i++) {
		if (films[i].rating <= rating) {
			foundFilms.push_back(films[i]);
		}
	}
	return foundFilms;
}

void printFilm(Film film);

vector<Film> findFilmsByRatingandRunningTime(int rating, int runningTime,
		vector<Film> films) {
	int size = films.size();
	vector<Film> foundFilms;
	for (int i = 0; i < size; i++) {
//		printFilm (films[i]);
		if ((films[i].rating <= rating)
				&& (films[i].runningTime <= runningTime)) {
			foundFilms.push_back(films[i]);
		}
	}
	return foundFilms;
}

void printFilm(Film *film) {
	cout << "Film title                : " << film->name << endl;
	cout << "Film description    : " << film->description << endl;
	cout << "Film running time : " << film->runningTime << " minutes" << endl;
	cout << "Film rating            : " << filmRatingToString(film->rating)
			<< endl << endl;
}

void printFilms(vector<Film *> films) {
	int size = films.size();
	for (int i = 0; i < size; i++) {
		printFilm(films[i]);
	}
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

