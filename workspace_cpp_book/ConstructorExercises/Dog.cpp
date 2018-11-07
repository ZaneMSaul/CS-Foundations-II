#include <iostream>
#include "Dog.h"

Dog::Dog() {
	std::cout << "******Constructing Dog " << std::endl;
}

bool Dog::isDomesticated () {
	return true;
}

bool Dog::barks(){
	return true;
}
bool Dog::hasFourLegs(){
	return true;
}

Dog::~Dog() {
	std::cout << "******Deallocating Dog " << std::endl;
}

