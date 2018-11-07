/*
 Instructions
 In Class Exercise and Assignment

 Our book has an example of how to create a class that manages a linked list.
 We’ll extend that example in class and then use the example as the basis for
 our last assignment

 ListNode

 ListNode is a class that is provides some of the capabilities required of a
 linked list item. ListNode is not meant to stand on its own, but to be used as
 a base class for a real linked list node.  ListNode has the following
 attributes and methods:

 Attributes
 ListNode * next: a pointer to the next node in the list
 Methods

 ListNode * getNext() : returns the value of next
 void setNext(ListNode *) : sets the value of next
 int compare (ListNode *): a virtual function to compare two list elements; if
 the argument is equal to the ListNode object, result is 0; if the argument is
 less than the ListNode the result is -1, otherwise 1.

 IntegerListNode

 IntegerListNode is a subclass of ListNode. It has the following
 characteristics:

 Attributes
 int value: the data part of the node – an integer value
 Methods

 int * getValue() : returns the value of value
 void setValue (int) : sets the value of value
 int compare (ListNode *): compares the value in the IntegerListNode with
 another IntegerListNode, example below

 int IntegerListNode::compare(ListNode  *node) {

 IntegerListNode *compareTo =

 dynamic_cast<IntegerListNode *>(node);

 int result = this->value – compareTo->value;

 if (result <  0) return -1;

 if (result == 0) return  0;

 return 1;

 }

 LinkedList

 LinkedList is a class that will manage the list elements. It has the following
 characteristics:

 Attributes
 ListNode  *head: the head of the list;
 ListNode *tail: the last element in the list;

 Methods

 ListNode *getFirst(): get the first element in the list and removes it
 ListNode *getLast(): gets the last element in the list and removes it
 void   append (ListNode *) : append a value to the end of the list
 void   prepend (ListNode *) : insert a value as the first element of the list
 void insert (ListNode *): inserts a value into the list
 void traverse (): traverse the list

 Stack

 Stack is a class that will use LinkedList as its backing store. Stack should
 have the following methods:

 Methods

 void push (int): push an integer onto the stack
 int pop (): pop an integer off the stack
 int peek(): get the top integer on the stack but don’t remove it.
 bool empty(): returns true if there are no elements on the stack

 In Class Exercise:

 Write the code for the Stack class methods using the LinkedList defined above
 and assuming the nodes will be IntegerListNodes.

 Queue

 Suppose we have a class Queue that has the following methods:

 void enqueue(int): adds an element to the rear of the quere
 int dequeue() : returns and removes an element at the front of the queue
 bool isEmpty(): indicates if the queue is empty
 void clear(): clears the queue

 Consider

 Should we use LinkedList as the backing store for Queue? Why or why not?
 What other data type might we use for implementing Queue?

 Assignment 8

 Implement the classes we have discussed:

 1.ListNode

 2. IntegerListNode

 3.LinkedList

 4.Stack

 5.Queue
 */
#include "ListNode.h"
#include "IntegerListNode.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>

int main(){

	 //jill seaman
	IntegerListNode Node;
	ListNode List;

	std::cout << "Merry Christmas!";

    return 0;
}

