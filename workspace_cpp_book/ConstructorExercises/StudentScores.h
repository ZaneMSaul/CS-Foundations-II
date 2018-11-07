/*
 * StudentScores.h
 *
 *  Created on: Oct 29, 2017
 *      Author: two
 */

#ifndef STUDENTSCORES_H_
#define STUDENTSCORES_H_

#include <string>
#include<vector>

class StudentScores {
	std::string name;
	std::vector <int> scores;

public:
	StudentScores ();
	StudentScores(std::string name, std::vector<int> scores);
	StudentScores (const StudentScores &studentScores);
	StudentScores  operator=(const StudentScores &right);
	StudentScores & operator=(StudentScores &&temp);

	void setName (std::string );
	void print () const;
	virtual ~StudentScores();
};

#endif /* STUDENTSCORES_H_ */
