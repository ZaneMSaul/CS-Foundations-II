//
//  Stack.hpp
//  Assignment 8
//
//  Created by zane saul on 12/9/17.
//  Copyright © 2017 zane saul. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include "LinkedList.h"

class Stack
{
private:
    LinkedList* stack;
public:
    Stack();
    void push( int );
    int pop( );
    int peek();
    bool empty();
    virtual ~Stack();
};

#endif /* Stack_hpp */
