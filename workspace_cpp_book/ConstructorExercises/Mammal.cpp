#include <iostream>

#include "Mammal.h"

Mammal::Mammal() {
	std::cout << "***Constructing Mammal " << std::endl;
}

bool Mammal::hasHair() {
	return true;
}

bool Mammal::drinksMilk(){
	return true;
}

bool Mammal::bornAlive (){
	return true;
}

bool Mammal::hasTeeth(){
	return true;
}

Mammal::~Mammal() {
	std::cout << "***Deallocating Mammal " << std::endl;
}

