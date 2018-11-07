/*
 * UniqueWords3.h
 *
 *  Created on: Nov 15, 2017
 *      Author: two
 */

#ifndef UNIQUEWORDS3_H_
#define UNIQUEWORDS3_H_

#include <set>
#include <string>

class UniqueWords3 {
private:
	std::set<std::string>words;

public:
	UniqueWords3();
	void add (std::string);
	bool isMember (std::string);
	void print();
	virtual ~UniqueWords3();
};

#endif /* UNIQUEWORDS3_H_ */
