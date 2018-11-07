//
//  LinkedList.hpp
//  Assignment 8
//
//  Created by zane saul on 12/9/17.
//  Copyright © 2017 zane saul. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include "IntegerListNode.h"

class LinkedList: public ListNode
{
private:
    ListNode *head;
    ListNode *tail;
public:
    LinkedList();
    ListNode *getFirst();
    ListNode *getLast();
    bool isempty();
    void append( ListNode * );
    void prepend( ListNode * );
    void traverse ();
    virtual ~LinkedList();
};

#endif /* LinkedList_h */
