#include <vector>
#include <string>
#include <iostream>

#include "StudentScores.h"
#include "Dog.h"

std::string boolToString (bool value);

int main () {

	std::vector <int> scoreValues1;
	scoreValues1.push_back(100);
	scoreValues1.push_back(99);
	scoreValues1.push_back(77);

	std::vector <int> emptyVector;

	std::cout << "StudentScores allocation for student Max" << std::endl;
	StudentScores max =  StudentScores ("Max", scoreValues1);
	max.print();

	std::cout << "StudentScores copying Max to MaxCopy " << std::endl;
	StudentScores maxCopy = max;
	std::cout << "Change Max copy name to MaxCopy" << std::endl;
	maxCopy.setName("MaxCopy");
	std::cout << "Printing values for MaxCopy" << std::endl;
	maxCopy.print();
	std::cout << std::endl << std::endl;

	std::cout << "StudentScores assigning Max to Maxine" << std::endl;

	StudentScores maxine;
	maxine = max;
	std::cout << "Setting Maxine's name" << std::endl;
	maxine.setName("Maxine");
	maxine.print();


	// Dog stuff

	std:: cout << std:: endl << std:: endl << std:: endl;

	std::cout << "Allocating Dog class " << std::endl;
	Dog aDog;

	std::cout << "Dog: has hair              :" << boolToString(aDog.hasHair())       << std::endl;
	std::cout << "Dog: drinks milk         :" << boolToString(aDog.drinksMilk()) << std::endl;
	std::cout << "Dog: born alive           :" << boolToString(aDog.bornAlive())  << std::endl;
	std::cout << "Dog: isDomesticated  :" << boolToString(aDog.isDomesticated())  << std::endl;
	std::cout << "Dog: barks                   :" << boolToString(aDog.barks())        << std::endl;
	std::cout << "Dog: hasFourLegs       :" << boolToString(aDog.hasFourLegs())  << std::endl;

	return 0;
}


std::string boolToString (bool value) {
	if (value) return "true";
	return "false";
}

