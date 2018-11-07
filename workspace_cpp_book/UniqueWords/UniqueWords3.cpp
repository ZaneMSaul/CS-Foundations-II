#include <string>
#include <iostream>
#include "UniqueWords3.h"

UniqueWords3::UniqueWords3() {

}

void UniqueWords3::add (std::string word) {
	words.insert(word);
}

bool UniqueWords3::isMember(std::string word) {
   std::set<std::string>:: iterator it;
   it = words.end();
   if (words.find(word) == it) return false;
   return true;
}

void UniqueWords3::print () {
	   std::set<std::string>:: iterator it;
	   it = words.begin();
	   while (it != words.end()) {
		   std::cout << "Word: " << *it << std::endl;
		   it++;
	   }
}

UniqueWords3::~UniqueWords3() {
	// TODO Auto-generated destructor stub
}

