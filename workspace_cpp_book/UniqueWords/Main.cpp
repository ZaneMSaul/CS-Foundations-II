#include <iostream>
#include "UniqueWords1.h"

std::string niceBool (bool);

int main () {

	UniqueWords1 *unique1 = new UniqueWords1();
	unique1->add("when");
	unique1->add("in");
	unique1->add("the");
	unique1->add("course");
	unique1->add("of");
	unique1->add("human");
	unique1->add("events");
	unique1->add("it");
	unique1->add("becomes");
	unique1->add("necessary");
	unique1->add("for");
	unique1->add("one");
	unique1->add("people");
	unique1->add("to");
	unique1->add("to");
	unique1->add("to");

	std::cout<< "'Whoa?' is a member of words " << niceBool(unique1->isMember("whoa?")) << std::endl;
	std::cout<< "'to' is a member of words " << niceBool(unique1->isMember("to"))<< std::endl;
	std::cout<< "'people' is a member of words " << niceBool(unique1->isMember("people")) << std::endl;

	unique1->print();
}

std::string niceBool (bool value) {
	if (value) return "true";
	return "false";
}


