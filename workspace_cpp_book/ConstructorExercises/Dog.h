/*
 * Dog.h
 *
 *  Created on: Oct 29, 2017
 *      Author: two
 */

#ifndef DOG_H_
#define DOG_H_

#include "Mammal.h"

class Dog: public Mammal {
public:
	Dog();
	bool isDomesticated ();
	bool barks();
	bool hasFourLegs();
	virtual ~Dog();
};

#endif /* DOG_H_ */
