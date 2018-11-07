/*
 * Main.cpp
 *
 *  Created on: Oct 2, 2017
 *      Author: two
 */

#include <iostream>
#include <string>
#include "Film.h"
using namespace std;


int main () {
	  Film aFilm;
	  aFilm.setName ("Rambo");
	  aFilm.setRunningTime (180);
	  aFilm.setDescription ("Sly Stone over acts");

	  aFilm.print();

}




