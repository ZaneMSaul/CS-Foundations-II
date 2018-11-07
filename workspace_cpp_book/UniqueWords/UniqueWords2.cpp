#include <iostream>
#include "UniqueWords2.h"

UniqueWords2::UniqueWords2() {

}


void UniqueWords2::add (std::string word) {
	if (!isMember(word)) {
		words.push_back (word);
		wordCounts.push_back(1);
	} else {
		 int indexOfWord = location(word);
		 wordCounts [indexOfWord] = wordCounts [indexOfWord] + 1;
	}
}

bool UniqueWords2::isMember(std::string word) {
   int indexOfWord = location(word);
   if (indexOfWord != -1) return true;
   return false;
}

void UniqueWords2::print () {
	  int size = words.size();
	 for (int i=0; i<size; i++) {
		  std::cout << "Word: " << words[i] << " count " << wordCounts [i] << std::endl;
	  }
}

int UniqueWords2::wordCount (std::string word) {
	int indexOfWord = location(word);
	if (indexOfWord >= 0)  return wordCounts[indexOfWord];
	return 0;
}

int UniqueWords2::location(std::string word) {
  int size = words.size();
  for (int i=0; i<size; i++) {
	  if (word == words[i]) return i;
  }
  return -1;
}

UniqueWords2::~UniqueWords2() {

}

