/*
 * Main.cpp
 *
 *  Created on: Oct 5, 2017
 *      Author: two
 */

#include <iostream>

#include "Actor.h"
#include "ActorInventory.h"
#include "Film.h"
#include "FilmCatalog.h"

int main() {

	ActorInventory actorInventory("actors.dat");
	int size = actorInventory.size();
	std::cout << "ActorInventory now contains " << size << "  elements"
			<< std::endl;

	for (int i = 1; i <= size; i++) {
		Actor *actor = actorInventory.get(i);
		actor->print();
	}

	actorInventory.clear();
	size = actorInventory.size();
	std::cout << "ActorInventory now contains " << size << "  elements"
			<< std::endl;

	FilmCatalog filmCatalog("films.dat");
	size = filmCatalog.size();
	std::cout << "FilmCatalog now contains " << size << "  elements"
			<< std::endl;

	for (int i = 1; i < size; i++) {
		Film *film = filmCatalog.get(i);
		film->print();
	}

	filmCatalog.clear();
	size = filmCatalog.size();
	std::cout << "FilmCatalog now contains " << size << "  elements"
			<< std::endl;
}
