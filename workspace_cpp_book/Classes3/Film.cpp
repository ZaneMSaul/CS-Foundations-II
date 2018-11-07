/*
 * Film.cpp
 *
 *  Created on: Oct 2, 2017
 *      Author: two
 */

#include "Film.h"

#include <iostream>

using namespace std;

string Film::getDescription() const {
	return description;
}

string Film::getName() const {
	return name;
}
int Film::getRunningTime() const {
	return runningTime;
}

void Film::print () const {
	  cout << "Film name            : " <<  name << endl;
	  cout << "Film description   : " <<  description << endl;
	  cout << "Film running time: " << runningTime << endl;
}

void Film::setRunningTime(int filmRunningTime) {
	runningTime = filmRunningTime;
}

void Film::setName(string theName) {
	name = theName;
}

void Film::setDescription(string theDescription) {
	description = theDescription;
}

