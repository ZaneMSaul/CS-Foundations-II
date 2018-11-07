//
//  LinkedList.cpp
//  Assignment 8
//
//  Created by zane saul on 12/9/17.
//  Copyright © 2017 zane saul. All rights reserved.
//

#include "LinkedList.h"
#include "IntegerListNode.h"
#include <iostream>

LinkedList::LinkedList(){
    head = nullptr;
    tail = nullptr;
}

ListNode *LinkedList::getFirst(){
    ListNode *temp = this->head;
    head = temp->getNext();
    return temp;
}
ListNode *LinkedList::getLast(){
    ListNode *temp = head;
    ListNode *holder;
    while(temp->getNext()){
        holder = temp;
        temp = temp->getNext();
    }
    tail = holder;
    std::cout << "Last Value: " << temp->getNext() << std::endl;
    tail->setNext(nullptr);

    return temp;
}
 //goes to bottom of stack
void LinkedList::append( ListNode * newnode ){
    ListNode *nodePtr;

    if( head == nullptr ){
        head = newnode;
        tail = newnode;
        return;
    }
    nodePtr = head;
    while( nodePtr->getNext() )
        nodePtr = nodePtr->getNext();

    nodePtr->setNext(newnode);

    tail = newnode;
}
//goes to top of stack
void LinkedList::prepend( ListNode * newnode){
    if( !head ){
        head = newnode;
    } else{
        newnode->setNext(head);
        head=newnode;
    }
}

void LinkedList::traverse (){
    ListNode *tempnode = head;
    while(tempnode -> getNext() ){
    	std::cout << dynamic_cast<IntegerListNode*>(tempnode)->getNext()
    			  << std::endl;
    	tempnode = tempnode->getNext();
    }
}
bool LinkedList::isempty(){
    if( head == nullptr )
        return true;
    else
        return false;
}
LinkedList::~LinkedList(){
}
