/*
 * Main.cpp
 *
 *  Created on: Sep 20, 2017
 *      Author: two
 */
#include <string>
#include <iostream>
#include <fstream>

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

const int COUNT1 = 4;
const int COUNT2 = 5;
const int COUNT3 = 7;
const int COUNT4 = 2;

string filmRatingToString(FilmRating rating);
void printFilm(Film film);
void printFilms(Film *films, int size);
Film * resize(Film *films, int currentSize, int newSize);

int main() {

	Film *films = new Film[COUNT1];

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
	films[3].description =
			"A mysterious pill helps a man use 100% of his brain";
	films[3].runningTime = 105;
	films[3].rating = PG_13;

    cout << "*******Films in original order*****" << endl;
	printFilms(films, COUNT1);


	films = resize(films, COUNT1, COUNT2);

	films[4].id = 4;
	films[4].name = "The Shining";
	films[4].description = "Jack Nicholson wacks out";
	films[4].runningTime = 144;
	films[4].rating = R;

    cout << "*******Films with one added*****" << endl;
	printFilms(films, COUNT2);

	films = resize(films, COUNT2, COUNT3);

	films[5].id = 5;
	films[5].name = "The Other Boleyn Girl";
	films[5].description = "Henry 8 Takes an Axe";
	films[5].runningTime = 144;
	films[5].rating = R;

	films[6].id = 6;
	films[6].name = "Mr Deeds";
	films[6].description = "Simple Man Goes to Town";
	films[6].runningTime = 144;
	films[6].rating = R;

    cout << "*******Films with two added*****" << endl;
	printFilms(films, COUNT3);

	films = resize (films, COUNT3, COUNT4);
    cout << "*******Films with only two*****" << endl;
	printFilms(films, COUNT4);



}

string filmRatingToString(FilmRating rating) {

	switch (rating) {
	case G:
		return "G";

	case PG:
		return "PG 13";

	case PG_13:
		return "PG 13";

	case R:
		return "R";

	case NC_17:
		return "NC_17";

	case UNRATED:
		return "U";

	default:
		return "U";
	}

	return "U";
}

void printFilms(Film *films, int size) {
	for (int i = 0; i < size; i++) {
		printFilm(films[i]);
	}
}
void printFilm(Film film) {
	cout << "Film title                : " << film.name << endl;
	cout << "Film description    : " << film.description << endl;
	cout << "Film running time : " << film.runningTime << " minutes" << endl;
	cout << "Film rating            : " << filmRatingToString(film.rating)
			<< endl << endl;
}

Film * resize(Film *films, int currentSize, int newSize) {
	Film *newFilms = new Film[newSize];
	int size  = currentSize;
	if (newSize < currentSize ) size = newSize;
	for (int i = 0; i < size; i++) {
		newFilms[i] = films[i];
	}

	delete[] films;
	return newFilms;
}

Film * reverse(Film *films, int size) {
	Film * reverseFilms = new Film[size];
	int fromTheEnd = size - 1;
	for (int i = 0; i < size; i++) {
		reverseFilms[fromTheEnd] = films[i];
		fromTheEnd--;
	}
	return reverseFilms;
}
