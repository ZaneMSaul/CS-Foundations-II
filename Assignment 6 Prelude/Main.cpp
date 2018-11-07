/*
 * Main.cpp
 *
 *  Created on: Oct 5, 2017
 *   Author: Patricia Carando
 *
 *   Actors program represents a common pattern in object-oriented programming:
 *   a set of objects (Actor) is managed by another object (ActorInventory). The
 *   manager of the set includes a vector where the Actor objects are stored. The
 *   ActorInventory exposes a small set of the methods of vector to allow any client
 *   of ActoryInventory to perform some operations on the collection, e.g., add, get
 *   elements of the collection.
 *
 *   Note: We will use the styles illustrated here for the rest of the course:
 *   1. No "using namespace std" any longer. When employing elements of namespace
 *      std, the elements will be scoped, e.g., std::cout
 *   2. We'll allocate objects on the heap, not on the stack Actor *actor = new Actor ...
 *        Not: Actor actor;
 *   3. We'll used const wherever feasible and appropriate
 *
 */

#include <iostream>

#include "Actor.h"
#include "ActorInventory.h"


int main () {
	ActorInventory actorInventory ("actors.dat");
	int size = actorInventory.size();
	std::cout << "ActorInventory now contains " << size << "  elements" << std::endl;

	for (int i=1; i<=size; i++) {
		Actor *actor = actorInventory.get(i);
		actor->print();
    }

	actorInventory.clear();
	size = actorInventory.size();
	std::cout << "ActorInventory now contains " << size << "  elements" << std::endl;
}
