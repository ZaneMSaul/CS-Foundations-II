

#ifndef UNIQUEWORDS1_H_
#define UNIQUEWORDS1_H_

#include <vector>
#include <string>

class UniqueWords1 {

private:
	std::vector <std::string> words;

public:
	UniqueWords1();

	void add (std::string);
	bool isMember (std::string);
	void print();

	virtual ~UniqueWords1();
};

#endif /* UNIQUEWORDS1_H_ */
