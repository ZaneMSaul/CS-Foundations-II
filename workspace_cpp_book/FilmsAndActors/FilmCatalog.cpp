/*
 * FilmCatalog.cpp
 *
 *  Created on: Oct 21, 2017
 *      Author: two
 */

#include "FilmCatalog.h"

#include <fstream>


FilmCatalog::FilmCatalog(const std::string theInputFIle) {
	inputFile = theInputFIle;
}

// adds an Film object to the Catalog
void FilmCatalog::add(Film *Film) {
	initialize();
	films.push_back(Film);
}

// returns an Film object at the specified index or nullptr
Film * FilmCatalog::get(int index) {
	if (index < 0)
		return nullptr;
	if (index > films.size())
		return nullptr;
	return films.at(index);
}

// deletes the contents of the vector holding Film pointers
void FilmCatalog::clear() {
	for (auto Film : films) {
		delete Film;
	}
	films.clear();
}

int FilmCatalog::size() {
	initialize();
	return films.size();
}

void FilmCatalog::initialize() {
	std::string id;                  // id converted to int
	std::string name;           // Film  name
	std::string description;  // description
	std::string rating;          //  rating
	std::string runningTime;

	std::ifstream filmFile;   // file for reading acor data

// if we've already read the Film file, return
	if (isInitialized)
		return;

	filmFile.open(inputFile.c_str(), std::ios::in);
	std::getline(filmFile, id, ',');
	while (filmFile) {
		std::getline(filmFile, name, ',');
		std::getline(filmFile, description, ',');
		std::getline(filmFile, runningTime, ',');
		std::getline(filmFile, rating, ',');

		Film *film = new Film(id, name, description, rating, runningTime);
//		film->print();

		films.push_back(film);

		std::getline(filmFile, id, ',');
	}
	isInitialized = true;
}

FilmCatalog::~FilmCatalog() {
	for (auto film : films) {
		delete film;
	}
	films.clear();
}

