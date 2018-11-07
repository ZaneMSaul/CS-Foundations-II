/*
 * StudentScores.cpp
 *
 *  Created on: Oct 29, 2017
 *      Author: two
 */

#include "StudentScores.h"

#include <iostream>

StudentScores::StudentScores () {
	std::cout << "@@@StudentScores zero arg constructor " << std::endl;
	this->name = "";
}

StudentScores::StudentScores(std::string name, std::vector<int> scores) {
	std::cout << "@@@StudentScores constructor for " << name << std::endl;
	this->name =  name;
	int size = scores.size();
	for (int i=0; i<size; i++) {
		this->scores.push_back(scores[i]);
	}
}


StudentScores::StudentScores (const StudentScores &studentScores) {
	std::cout << "@@@StudentScores copy constructor, copy from " <<
			studentScores.name  << std::endl;
	name     = studentScores.name;
	int size  = studentScores.scores.size();
	for (int i=0; i<size; i++) {
		scores.push_back(studentScores.scores[i]);
	}
}

//StudentScores::StudentScores (const StudentScores &studentScores) {
//	name = studentScores.name;
//	int size = studentScores.scores.size();
//	scores = studentScores.scores;
//}

StudentScores &StudentScores::operator=(StudentScores &&temp) {
	std::cout << "@@@StudentScores move operator = assign from " <<
			temp.name <<std::endl;
	name = temp.name;
	scores = temp.scores;
	return *this;
}

StudentScores StudentScores::operator=(const StudentScores &right) {
	std::cout << "@@@StudentScores operator = assign from " <<
			right.name << std::endl;
	if (this != &right) {
		name = right.name;
		// scores.clear();
		scores = right.scores;
	}
	return *this;
}


void StudentScores::setName (std::string name) {
	this->name = name;
}

void StudentScores::print () const {
	int size = scores.size();
	std::cout << "StudentScores::print: " << name << std::endl;
	for (int i=0; i<size; i++) {
		std::cout << "Score [ " << i << "] = " << scores[i] << std::endl;
	}
	std::cout << std::endl;
}

StudentScores::~StudentScores() {
	std::cout << "@@@StudentScores::destructor:: " << name << std::endl;
}

