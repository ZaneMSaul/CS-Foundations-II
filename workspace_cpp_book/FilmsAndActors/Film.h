/*
 * Film.h
 *
 *  Created on: Oct 2, 2017
 *      Author: two
 */

#ifndef FILM_H_
#define FILM_H_

#include <string>

enum FilmRating {
	G, PG, PG_13, NC_17, R, UNRATED
};

class Film {
private:
	int id;
	std::string name;
	std::string description;
	FilmRating rating;
	int runningTime;

    FilmRating stringToFilmRating (std::string);
    std::string filmRatingToString (FilmRating rating) const;

public:
    Film  (std::string id, std::string name, std::string description, std::string rating, std::string runningTime);
	Film (int id, std::string name, std::string description, FilmRating rating, int runningTime);

	std::string         getName() const;
	std::string         getDescription() const;
	FilmRating        getRating () const;
	int                     getRunningTime() const;

	void                  print() const;

};

#endif /* FILM_H_ */
