/*
 * Actor.h
 *
 *  Created on: Oct 7, 2017
 *      Author: two
 */

#ifndef ACTOR_H_
#define ACTOR_H_

#include <string>
class Actor {
private:
	int id;
	std::string firstName;
	std::string lastName;

public:
	Actor(int id, std::string firstName, std::string lastname);
	Actor(std::string id, std::string firstName, std::string lastname);

	int getId() const;
	std::string getFirstName() const ;
	std::string getLastName() const;
	void print () const;

	~Actor ();

};

#endif /* ACTOR_H_ */
