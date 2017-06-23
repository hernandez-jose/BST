/*
Created By: Jose Hernandez Naranjo
*/

#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
private:
	T data;
	Node<T>* next;

public:
	/*
	  Pre:		item of any type
	  Post:		adds an item of any type to the nodes data
	  Return:	true if item was added; false on unsuccessfully
	*/
	bool		setData(T item);

	/*
	  Pre:		a node of any type pointer
	  Post:		sets the next address from node
	  Return:	true if successfully; false on unsuccessfully
	*/
	bool		setNext(Node<T>* nextNode);

	/*
	  Pre:		
	  Post:		retrieves item from nodes data
	  Return:	item requested of any type
	*/
	T			getData() const;

	/*
	Pre:
	Post:		retrieves next item in chain from node
	Return:		address of next node
	*/
	Node<T>*	getNext() const;

	Node();
};

#include "Node.cpp"

#endif