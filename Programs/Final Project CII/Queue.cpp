//
//  Queue.cpp
//  Assignment 8
//
//  Created by zane saul on 12/9/17.
//  Copyright © 2017 zane saul. All rights reserved.
//

#include "Queue.h"

Queue::Queue(){
	queue = new LinkedList();
}
void Queue::enqueue( int num ){
	queue->append(new IntegerListNode(num));
}
int Queue::dequeue(){
	return dynamic_cast<IntegerListNode *>( queue->getFirst())->getValue();
}
bool Queue::isEmpty(){
    return queue->isempty();
}
void Queue::clear(){
	while(queue->isempty()) {
		queue->getFirst();
	}
}
/*Queue::~Queue(){
}*/

