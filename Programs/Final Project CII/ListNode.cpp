//
//  ListNode.cpp
//  Assignment 8
//
//  Created by zane saul on 12/9/17.
//  Copyright © 2017 zane saul. All rights reserved.
//

#include "ListNode.h"

ListNode::ListNode( ) { next= nullptr; }
ListNode *ListNode::getNext( ){
    return next;
}
void ListNode::setNext( ListNode *newnode ){
    next = newnode;
}
int ListNode::compare( ListNode *newnode ){
    return 0;
}
ListNode::~ListNode(){
    delete next;
}
