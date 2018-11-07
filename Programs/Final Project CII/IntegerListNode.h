//
//  IntegerListNode.hpp
//  Assignment 8
//
//  Created by zane saul on 12/9/17.
//  Copyright © 2017 zane saul. All rights reserved.
//

#ifndef IntegerListNode_h
#define IntegerListNode_h

#include "ListNode.h"

class IntegerListNode: public ListNode {
private:
    int value;
public:
    IntegerListNode( int );
    int getValue( );
    void setValue( int );
    virtual int compare( ListNode * );

    virtual ~IntegerListNode();
};

#endif /* IntegerListNode_h */
