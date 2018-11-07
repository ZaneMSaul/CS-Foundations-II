/*
 * Mammal.h
 *
 *  Created on: Oct 29, 2017
 *      Author: two
 */

#ifndef MAMMAL_H_
#define MAMMAL_H_

class Mammal {
public:
	Mammal();

	bool hasHair();
	bool drinksMilk();
	bool bornAlive ();
	bool hasTeeth();

	virtual ~Mammal();
};

#endif /* MAMMAL_H_ */
