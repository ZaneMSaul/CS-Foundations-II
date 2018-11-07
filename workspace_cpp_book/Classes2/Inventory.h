/*
 * Inventory.h
 *
 *  Created on: Oct 2, 2017
 *      Author: two
 */

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <vector>
#include "Film.h"

class Inventory {
private:
	vector<Film> films;


public:
	void addFilm(Film film);
	Film getFilm(int index);
	int size();
	void initialize();
};

#endif /* INVENTORY_H_ */
