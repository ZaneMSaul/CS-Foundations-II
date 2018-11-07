//
//  Utils.cpp
//  Program6
//
//  Created by zane saul on 10/30/17.
//  Copyright © 2017 zane saul. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "Utils.h"

int Utils::stringToInt( std::string aString ){
    std::stringstream geek(aString);
    int intValue;
    geek >> intValue;
    return intValue;
}
