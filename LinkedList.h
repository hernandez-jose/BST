/*
Created By: Jose Hernandez Naranjo
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

template <class T>
class LinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
	Node<T>* current;
	Node<T>* previous;
	int itemCount;

public:
	/*
	  Pre:		item is an object of anytype; 1 <= index <= itemCount.
	  Post:		adds a node by index
	  Return:	true on successfully added; false on add unsuccessfully added.
	*/
	bool add(T item, int index);

	/*
	  Pre:		a parameter index for values -- 1 <= index <= itemCount
	  Post:		remove a node by index -- 1 <= index <= itemCount
	  Return:	true on successfully removed; false on add unsuccessfully removed.
	*/
	bool remove(int index);

	/*
	  Pre:		
	  Post:		gets the current number of nodes in list.
	  Returns:	interger of the value
	*/
	int getCurrentSize() const;

	/*
	  Pre:		
	  Post:		check if current size of nodes is greater than zero
	  Return:	true when there is no nodes; false when there exist nodes. 
	*/
	bool isEmpty();

	/*
	  Pre:		item of any data type
	  Post:		matches the first occurance of the item.
	  Return:	true when item exists; false when item does not exists.
	*/
	bool find(const T item) const;

	/*
	  Pre:		
	  Post:		Deletes all nodes one by one, starting from the head.
	  Return:	true when finished deleting; false if somthing unexpected happend.
	*/
	bool clear(); // deletes all

	/*
	  Pre:		
	  Post:		traverses the list starting from the head and outputs the values,
				in the order that they are stored.
	  Return:	
	*/
	void show();

	/*
	  Pre:		
	  Post:		gets the tail pointer(last item) from the list.
	  Return:	pointer to a node type
	*/
	Node<T>* getTail() const;

	/*
	Pre:
	Post:		gets the head pointer(first item) from the list.
	Return:		pointer to a node type
	*/
	Node<T>* getHead() const;

	LinkedList();

	/*
	  Pre:
	  Post:		releases memory blocks from nodes
	  Return:	
	*/
	virtual ~LinkedList();
};

#include "LinkedList.cpp"


#endif