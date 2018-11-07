/*
 * Utils.cpp

 *
 *  Created on: Oct 21, 2017
 *      Author: two
 */
#include <iostream>
#include <sstream>
#include "Utils.h"


Utils::Utils() {
	// declared private; should never be instantiated

}

  int Utils::stringToInt(std::string aString) {
	    std::stringstream geek(aString);
	    int intValue;
	    geek >> intValue;
//	    std::cout << "Utils.stringToInt " << aString << " to int " << intValue
//	    		<< std::endl;
	    return intValue;
}
