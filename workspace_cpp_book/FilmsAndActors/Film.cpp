
#include <iostream>
#include <string>

#include "Film.h"
#include "Utils.h"


Film::Film  (std::string id, std::string name, std::string description, std::string rating, std::string runningTime) {
	this->id                  = Utils::stringToInt(id);
    this->name            = name;
    this->description   = description;
    this->rating            = stringToFilmRating (rating);
    this->runningTime = Utils::stringToInt (runningTime);
}


Film::Film(int id, std::string name, std::string description, FilmRating rating,
		int theRunningTime) {
	this->id                  = id;
	this->name            = name;
	this->description   = description;
	this->rating            = rating;
	this->runningTime = runningTime;
}
;

std::string Film::getDescription() const {
	return description;
}

std::string Film::getName() const {
	return name;
}
int Film::getRunningTime() const {
	return runningTime;
}

void Film::print() const {
	std::cout << "Film id                  : "  << id << std::endl;
	std::cout << "Film name            : " << name << std::endl;
	std::cout << "Film description   : " << description << std::endl;
	std::cout << "Film running time: " << runningTime << std::endl;
	std::cout << "Film rating            : " << filmRatingToString (rating) << std::endl << std::endl;
}



FilmRating Film::stringToFilmRating(std::string stringRating) {
	int const N_RATINGS = 6;
	std::string stringRatings[] = { "G", "PG", "PG-13", "NC-17", "R", "UNRATED" };
	FilmRating ratings[] = { G, PG, PG_13, NC_17, R, UNRATED };

	for (int i = 0; i < N_RATINGS; i++) {
		if (stringRating == stringRatings[i])
			return ratings[i];
	}
	return UNRATED;
}


std::string Film::filmRatingToString(FilmRating rating) const {
	int const N_RATINGS = 6;
	std::string stringRatings[] = { "G", "PG", "PG-13", "NC-17", "R", "UNRATED" };
	FilmRating ratings[] = { G, PG, PG_13, NC_17, R, UNRATED };

	for (int i = 0; i < N_RATINGS; i++) {
		if (rating == ratings[i])
			return stringRatings[i];
	}
	return "UNRATED";
}

