//
//  ListNode.hpp
//  Assignment 8
//
//  Created by zane saul on 12/9/17.
//  Copyright © 2017 zane saul. All rights reserved.
//

#ifndef ListNode_h
#define ListNode_h

class ListNode{
private:
    ListNode * next;
public:
    ListNode();
    ListNode * getNext();
    void setNext(ListNode *);
    virtual int compare (ListNode *);
    virtual~ListNode();
};

#endif /* ListNode_h */
