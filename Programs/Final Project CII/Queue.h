//
//  Queue.hpp
//  Assignment 8
//
//  Created by zane saul on 12/9/17.
//  Copyright © 2017 zane saul. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include "LinkedList.h"

class Queue
{
private:
    LinkedList *queue;
public:
    Queue();
    void enqueue( int );
    int dequeue();
    bool isEmpty();
    void clear();
    //virtual~queue();
};

#endif /* Queue_h */
