/*
 * Main.cpp
 *
 *  Created on: Oct 2, 2017
 *      Author: two
 */

#include <iostream>
#include <string>
#include "Film.h"
#include "Inventory.h"
using namespace std;


int main () {
	  cout << "Films in the Inventory" << endl;

	  Inventory inventory;


	  Film film = inventory.getFilm(0);
	  film.print();

	  film = inventory.getFilm(4);
	  film.print();

	  film = inventory.getFilm(2);
	  film.print();

	  film = inventory.getFilm(3);
	  film.print();

	  Film newFilm;
	  newFilm.setName ("Cinderalla");
	  newFilm.setDescription("Girl Likes Slippers, Princes");
	  newFilm.setRunningTime (90);

	  inventory.addFilm(newFilm);
	  film = inventory.getFilm(5);
	  film.print();

}




