/*
 * ActorInventory.cpp
 *
 *  Created on: Oct 7, 2017
 *      Author: two
 */
#include <fstream>

#include "ActorInventory.h"
#include "Utils.h"

ActorInventory::ActorInventory(const std::string theInputFile) {
	inputFile = theInputFile;
}

// adds an actor object to the inventory
void ActorInventory::add( Actor *actor) {
	initialize();
	actors.push_back(actor);
}

/*
 * The get function returns the object at the specified index-1!!
 * The index is the id of the object which is numbered 1 ... n
 * However, the vector counts 0 ... n-1. We do a little recalculation
 * to make it all work out.
 *
 * If index is out of range, nullptr is returned.
 */
Actor * ActorInventory::get(int index) {
	int size = actors.size();
	if (index < 1)
		return nullptr;
	if (index > size)
		return nullptr;
	return actors.at(index-1);
}

// deletes the contents of the vector holding actor pointers
void ActorInventory::clear() {
	for (auto actor : actors) {
		delete actor;
	}
	actors.clear();
}

int ActorInventory::size() {
	initialize();
	return actors.size();
}

void ActorInventory::initialize() {
	std::string id;                // id read as a string
	std::string firstName;   // actor first name
	std::string lastName;   // actor last name

	std::ifstream actorFile;   // file for reading acor data

// if we've already read the actor file, return
	if (isInitialized)
		return;

	actorFile.open(inputFile.c_str(), std::ios::in);
	std::getline(actorFile, id, ',');
	while (actorFile) {
		std::getline(actorFile, firstName, ',');
		std::getline(actorFile, lastName, ',');

		Actor *actor = new Actor(id, firstName, lastName);

		actors.push_back(actor);
		std::getline(actorFile, id, ',');
	}
	isInitialized = true;
}


ActorInventory::~ActorInventory() {
	for (auto actor : actors) {
		delete actor;
	}
	actors.clear();
}

