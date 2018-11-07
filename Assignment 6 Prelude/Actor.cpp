/*
 * Actor.cpp
 *
 *  Created on: Oct 7, 2017
 *      Author: two
 */

#include "Actor.h"
#include <iostream>

Actor::Actor(int theId, std::string theFirstName, std::string theLastName) {
   ID = theId;
   firstName = theFirstName;
   lastName = theLastName;
}

std::string Actor::getFirstName() const {
	return firstName;
}

int Actor::getId() const {
	return ID;
}

std::string Actor::getLastName() const {
	return lastName;
}

void Actor::print () const {
	std::cout << "Actor id     : " << ID << std::endl;
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl << std::endl;
}

Actor::~Actor () {

}
