#ifndef UNIQUEWORDS2_H_
#define UNIQUEWORDS2_H_

#include <vector>
#include <string>

class UniqueWords2 {
private:

	std::vector<std::string> words;
	std::vector<int> wordCounts;
	int location (std::string);

public:
	UniqueWords2();
	void add(std::string);
	bool isMember(std::string);
	int    wordCount (std::string);
	void print();
	virtual ~UniqueWords2();
};

#endif /* UNIQUEWORDS2_H_ */
