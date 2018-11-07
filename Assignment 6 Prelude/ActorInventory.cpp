/*
 * ActorInventory.cpp
 *
 *  The manager object for Actor
 */
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>

#include "Actor.h"
#include "ActorInventory.h"

ActorInventory::ActorInventory(const std::string theInputFile) {
	inputFile = theInputFile;
}

// adds an actor object to the inventory
void ActorInventory::add(Actor *actor) {
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
	return actors.at(index - 1);
}

// deletes the contents of the vector holding actor pointers
void ActorInventory::clear() {
	for (auto actor : actors) {
		delete actor;
	}
	actors.clear();
}

// returns the number of elements; uses vector actors method
int ActorInventory::size() {
	initialize();
	return actors.size();
}

/*
 * The initialize method performs "just in time" initialization and may be
 *    called directly or from ActorInventory::add or ActorInventory::size
 * Check for already initialized by checking boolean isInitialized
 */

void ActorInventory::initialize() {
// if we've already read the actor file, return
	if (isInitialized)
		return;

	std::ifstream actorFile;   // file for reading acor data
	actorFile.open(inputFile.c_str(), std::ios::in);

	std::string idAsString;  // id read as a string
	int id;                            // id converted to int
	std::string firstName;   // actor first name
	std::string lastName;   // actor last name

	std::getline(actorFile, idAsString, ',');
	while (actorFile) {
		std::getline(actorFile, firstName, ',');
		std::getline(actorFile, lastName, ',');

		id = stringToInt(idAsString);
		Actor *actor = new Actor(id, firstName, lastName);
		actor->print();

		actors.push_back(actor);

		std::getline(actorFile, idAsString, ',');
	}
	isInitialized = true;
}

int ActorInventory::stringToInt(std::string aString) {
	std::stringstream geek(aString);
	int intValue;
	geek >> intValue;
	return intValue;
}

ActorInventory::~ActorInventory() {
	for (auto actor : actors) {
		delete actor;
	}
	actors.clear();
}

