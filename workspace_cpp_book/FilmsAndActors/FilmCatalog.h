/*
 * FilmCatalog.h
 *
 *  Created on: Oct 21, 2017
 *      Author: two
 */

#ifndef FILMCATALOG_H_
#define FILMCATALOG_H_

#include <string>
#include <vector>

#include "Film.h"

class FilmCatalog {
private:
	std::string inputFile;
	std::vector <Film *> films;
	bool isInitialized = false;

	void initialize ();
	int stringToInt (std::string aString);

public:
	FilmCatalog(const std::string theInputFile);

	void    add ( Film *);
	void    clear ();
	Film *  get (int);
	int       size ();

	virtual ~FilmCatalog();
};

#endif /* FILMCATALOG_H_ */
