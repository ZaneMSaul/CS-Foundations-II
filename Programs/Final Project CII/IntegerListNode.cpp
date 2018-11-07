//
//  IntegerListNode.cpp
//  Assignment 8
//
//  Created by zane saul on 12/9/17.
//  Copyright © 2017 zane saul. All rights reserved.
//

#include "IntegerListNode.h"
#include "ListNode.h"

IntegerListNode::IntegerListNode( int num ){ setValue( num ); }
int IntegerListNode::getValue( ){
    return value;
}
void IntegerListNode::setValue( int num ){
    value = num;
}
int IntegerListNode::compare( ListNode *node){

    IntegerListNode *compareTo =
        dynamic_cast<IntegerListNode *>( node );

    int result = this->value - compareTo->value;

    if( result < 0 ) return -1;

    if( result == 0 ) return 0;

    return 1;
}
IntegerListNode::~IntegerListNode(){}
