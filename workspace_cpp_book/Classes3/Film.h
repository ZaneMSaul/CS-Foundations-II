/*
 * Film.h
 *
 *  Created on: Oct 2, 2017
 *      Author: two
 */

#ifndef FILM_H_
#define FILM_H_

#include <string>
using namespace std;

class Film {
private:
	int id;
	string name;
	string description;
	int runningTime;

public:
	string getName() const;
	string getDescription() const;
	int      getRunningTime() const;

	void print() const;
	void setName(string name);
	void setDescription(string description);
	void setRunningTime(int runningTime);

};

#endif /* FILM_H_ */
