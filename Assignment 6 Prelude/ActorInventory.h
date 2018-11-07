/*
 * ActorInventory.h
 *
 *  Created on: Oct 7, 2017
 *      Author: two
 */

#ifndef ACTORINVENTORY_H_
#define ACTORINVENTORY_H_

#include <vector>
#include <string>
#include "Actor.h"

class ActorInventory {
private:
	std::string inputFile;
	std::vector <Actor *> actors;
	bool isInitialized = false;

	void initialize ();
	int stringToInt (std::string aString);

public:
	ActorInventory(const std::string inputFile);

	void    add (Actor *);
	void    clear ();
	Actor * get (int);
	int       size ();

  ~ActorInventory();
};

#endif /* ACTORINVENTORY_H_ */
