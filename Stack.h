#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

template <class T>
class Stack : protected LinkedList<T>
{
private:

public:
	/*
	  Pre: 	
	  Post:		Delete the last node
	  Return:	Return true if pop was successful or false if unsuccessful
	*/
	bool pop();

	/*
	  Pre:		item of any data type.
	  Post:		Pushes a node on top of the stack.
	  Return:	true if push was successful or false if unsuccessful
	*/
	bool push(T item);

	/*
	  Pre:		
	  Post:		displays the top node in a stack if it is not a nullptr.
	  Return:	Return the data inside the node.
	*/
	T peek();
	
	/*
	  Pre:
	  Post:		checks if itemCount is greater than 0.
	  Return:	true if empty; false when items exists.
	*/
	bool isEmpty() { return this->isEmpty; };


	/*
	  Pre:
	  Post:		get variable itemCount
	  Return:	integer number >= 0
	*/
	int getSize() const { return this->getCurrentSize(); };

	/*
	  Pre:
	  Post:		display the top node in a stack if it is not a nullptr.
	  Return:	Return the address of the node.
	*/
	Node<T>* peekAddress();
};

#include "Stack.cpp"

#endif