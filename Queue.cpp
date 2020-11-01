/*****************************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/25/2018
**Description: Lab 7 - Queue implementation file for the program.  Includes a destructor for the queue which cleans
**  up memory where necessary.  Includes a way to check to see if the queue is empty, a way to get the first value
**  in the list, a way to remove the first node in the list, a way to add a node to the back of the list, and a way
**  to print out all the values in the list separated by a space.
*******************************************************************************************************************/

#include "Queue.hpp"
#include <stdlib.h>
#include <iostream>
#include "Character.hpp"
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h> 

Queue::Queue() {
	//initialize head to NULL
	head = NULL;
}

//Destructor for the Queue
Queue::~Queue() {
	//if head is NULL, no memory to clean up
	if (head == NULL) {

	}
	//if head is not NULL, then clean up the memory
	else {
		//create a temporary value equal to the next value after head
		QueueNode* temp = head->next;
		//as long as temp and head aren't identical
		while (temp != head) {
			//create a garbage value for deletion equal to the temp value
			QueueNode* garbage = temp;
			//update the value of temp
			temp = temp->next;
			//delete the garbage memory
			delete garbage;
		}
		//delete the temp value (value at head)
		delete temp;
	}
	_CrtDumpMemoryLeaks();
}

//checks to see if the queue is empty.  If the queue is empty, returns true, otherwise returns false
bool Queue::isEmpty() {
	//if queue is empty (head is NULL)
	if (head == NULL) {
		//return true
		return true;
	}
	//if queue is not empty
	else {
		//return false
		return false;
	}
}

//returns the first value in the list
Character* Queue::getFront() {
	return head->aCharacter;
}

//removes the first value in the list
void Queue::removeFront() {
	//if the head of the list is the only value in the list
	if (head->next == head) {
		//delete head
		delete head->aCharacter;
		delete head;
		//set the value of head back to NULL
		head = NULL;
	}
	//if there is more than one item in the list
	else {
		//create a temporary copy of head
		QueueNode* temp = head;
		//set head equal to the next value in the list
		head = head->next;
		//make the last value in the list point to the new head value
		temp->prev->next = head;
		//make the new head's previous pointer point to the last value in the list
		head->prev = temp->prev;
		//delete the temporary copy of head
		delete temp->aCharacter;
		delete temp;
	}
}

//adds a value to the back of the list
void Queue::addBack(Character* aCharacter) {
	//if there is no value in the head of the list
	if (head == NULL) {
		//create a new node and assign it to the head
		head = new QueueNode;
		//head's next pointer points to itself
		head->next = head;
		//head's prev pointer points to itself
		head->prev = head;
		//set the value of head equal to the user entered value
		head->aCharacter = aCharacter;
	}
	//if there is already a head in the list
	else {
		//create a new node for the list
		QueueNode* node = new QueueNode;
		//if head is the only value in the list
		if (head->next == head) {
			//head's next pointer points to the new node
			head->next = node;
			//head's prev pointer points to the new node
			head->prev = node;
			//set node's value equal to the value the user entered
			node->aCharacter = aCharacter;
			//node's next pointer points to the head of the list
			node->next = head;
			//node's prev pointer points to the head of the list
			node->prev = head;
		}
		//if there is more than just the head in the list
		else {
			//create a temp value for traversing the list
			QueueNode* temp = head;
			//traverse the list and stop at the last value
			while (temp->next != head) {
				temp = temp->next;
			}
			//the last value's next pointer points to the new node
			temp->next = node;
			//head's previous value points to the new node
			head->prev = node;
			//set the new node's value based on user's input
			node->aCharacter = aCharacter;
			//set node's next pointer to the head of the list
			node->next = head;
			//set node's previous pointer to the last value in the list
			node->prev = temp;
		}
	}
}

//prints the values in the list
void Queue::printQueue() {
	//create a temp pointer for traversing the list
	QueueNode* temp = head->prev;
	//traverse the list until the last value and print out all the values separated by a space
	while (temp != head) {
		std::cout << temp->aCharacter->getName() << ", ";
		temp = temp->prev;
	}
	//print out the last value in the list
	std::cout << temp->aCharacter->getName() << std::endl;
}

//moves the head to the next value in the list
void Queue::nextFighter() {
	head = head->next;
	QueueNode* temp = head;
	while (head->aCharacter->getStrengthPoints() <= 0 && temp->next != head) {
		temp = temp->next;
		if (temp->aCharacter->getStrengthPoints() > 0) {
			head = temp;
		}
	}
}

//cleans up the loser pile
void Queue::cleanUpLoserPile() {
	//if the head of the list is the only value in the list
	if (head->next == head) {
		//set head to null
		delete head;
		head = NULL;
	}
	//if there is more than one item in the list
	else {
		//create a temporary copy of head
		QueueNode* temp = head;
		//set head equal to the next value in the list
		head = head->next;
		//make the last value in the list point to the new head value
		temp->prev->next = head;
		//make the new head's previous pointer point to the last value in the list
		head->prev = temp->prev;
		temp = NULL;
		delete temp;
	}
}