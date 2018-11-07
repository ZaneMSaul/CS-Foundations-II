/*
 * Inventory.cpp
 *
 *  Created on: Oct 2, 2017
 *      Author: two
 */

#include "Inventory.h"
#include <vector>
#include <iostream>

using namespace std;

Inventory::Inventory () {
	initialize();
}

Film Inventory:: getFilm (int index) {
	if (index < Inventory::size()) return films[index];
	return films[0];
}

void Inventory:: addFilm (Film film) {
	films.push_back (film);

}

int Inventory::size () {
	return films.size();
}

void Inventory:: initialize () {
    films.resize(5);

	films[0].setName ("Rambo");
	films[0].setRunningTime (180);
	films[0].setDescription ("Sly Stone over acts");

	films[1].setName ("The Old Man and the Sea");
	films[1].setRunningTime (72);
	films[1].setDescription ("Bad Day Fishing");

	films[2].setName ("Dracula");
	films[2].setRunningTime (156);
	films[2].setDescription ("Dude Wakes at Night to Big Thirst");

	films[3].setName ("Fight Club");
	films[3].setRunningTime (172);
	films[3].setDescription ("The First Rule of Fight Club ...");

	films[4].setName ("Thunderhead");
	films[4].setRunningTime (180);
	films[4].setDescription ("Cool horse movie");
}
