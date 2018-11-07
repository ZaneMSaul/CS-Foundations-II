/*
 * Actor.cpp
 *
 *  Created on: Oct 7, 2017
 *      Author: two
 */

#include "Actor.h"
#include "Utils.h"

#include <iostream>

/*
 *  "Normal" constructor for Actor
 */
Actor::Actor(int id, std::string firstName, std::string lastName) {
   this->id = id;
   this->firstName = firstName;
   this->lastName = lastName;
}

/*
 * Convenience constructor for Actor for reading values from a file. Actor id
 * will be read as a string; this constructor will convert it for storage into
 * Actor object
 */
Actor::Actor(std::string id, std::string firstName, std::string lastName) {
   this->id = Utils::stringToInt(id);
   this->firstName = firstName;
   this->lastName = lastName;
}

std::string Actor::getFirstName() const {
	return firstName;
}

int Actor::getId() const {
	return id;
}

std::string Actor::getLastName() const {
	return lastName;
}

void Actor::print () const {
	std::cout << "Actor id     : " << id << std::endl;
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl << std::endl;
}

Actor::~Actor () {

}
