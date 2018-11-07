//
//  Stack.cpp
//  Assignment 8
//
//  Created by zane saul on 12/9/17.
//  Copyright © 2017 zane saul. All rights reserved.
//

#include "ListNode.h"
#include "Stack.h"
#include "LinkedList.h"
#include "Queue.h"
#include <iostream>
#include "IntegerListNode.h"

Stack::Stack(){
	stack = new LinkedList();
}
void Stack::push(int num){
	stack->prepend(new IntegerListNode(num));
}

int Stack::pop( ){
	if( empty() ){
		std::cout << "The stack is empty.\n";
		return -1;
	}else{
		return dynamic_cast<IntegerListNode *>( stack -> getFirst() )->getValue();
		}
}
int Stack::peek(){
	ListNode *temp;
	int val;

	temp = stack->getFirst();
	val = dynamic_cast<IntegerListNode *>(temp)->getValue();

	stack->prepend(temp);

    return val;
}
bool Stack::empty(){
    return stack->isempty();
}
Stack::~Stack(){}

