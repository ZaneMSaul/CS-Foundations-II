
#include <iostream>
#include "UniqueWords1.h"

UniqueWords1::UniqueWords1() {

}

void UniqueWords1::add (std::string word) {
	if (!isMember(word)) words.push_back (word);
}

bool UniqueWords1::isMember(std::string word) {
  int size = words.size();
  for (int i=0; i<size; i++) {
	  if (word == words[i]) return true;
  }
  return false;
}

void UniqueWords1::print () {
	  int size = words.size();
	 for (int i=0; i<size; i++) {
		  std::cout << words[i] << std::endl;
	  }
}

UniqueWords1::~UniqueWords1() {
	// TODO Auto-generated destructor stub
}

