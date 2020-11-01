/************************************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/25/2018
**Description: Project 4 - Queue header file for the program.  Includes a struct for a QueueNode which contains a pointer
** to the next element in the list, a pointer to the previous element in the list and an integer value.  The Queue
** itself contains a pointer to the head of the list only.  Please see various function descriptions below for info
** about what each of them does.
*************************************************************************************************************************/

#include "Character.hpp"

#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue {

private:
	//struct for a QueueNode
	struct QueueNode {
		QueueNode* next;
		QueueNode* prev;
		Character* aCharacter;
	};
	//pointer to the head of the list
	QueueNode* head;

public:
	Queue();
	~Queue();
	//checks if the queue is empty. If so, returns true; otherwise, return false.
	bool isEmpty();
	//takes a user-inputted integer, creates a QueueNode with user-inputted integer, and appends it to the back of the list.
	void addBack(Character* aCharacter);
	//returns the value of the node at the front of the queue.
	Character* getFront();
	//removes the front QueueNode of the queue and free the memory.
	void removeFront();
	//traverses through the queue from head using next pointers, and prints the values of each QueueNode in the queue.
	void printQueue();
	//moves to the next fighter in the queue in a team fight
	void nextFighter();
	//clean up loser pile
	void cleanUpLoserPile();
};
#endif
