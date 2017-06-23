/*
Created By: Jose Hernandez Naranjo
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

template <class T>
class Queue : protected LinkedList<T>
{
private:

public:
	/*
	  Pre:		item any type
	  Post:		adds an item to the front of list
	  Return:	true on added; else false
	*/
	bool enQueue(T item);

	/*
	  Pre:		
	  Post:		remove item from the end
	  Return:	true if removed; else false
	*/
	bool deQueue();

	/*
	  Pre:		rear pointer
	  Post:		dereference rear pointer
	  Return:	returns data from the back
	*/
	T peek() const;
	/*
	Pre:	rear pointer
	Post:	store last node address to tempAddress
	Return:	returns address from last node
	*/
	Node<T>* peekAddress() const;


	/*
	 Pre:		
	 Post:		check current size > 0
	 Return:	true if empty; else false
	*/
	bool is_Empty() { return this->isEmpty(); }

	/*
	 Pre:		
	 Post:		delete all items in queue
	 Return:	true if empty; else false
	*/
	bool Empty() { return this->clear(); }

	/*
	  Pre:		
	  Post:		
	  Return:	itemCount
	*/
	int getSize() const;

	/*
	Pre:
	Post:
	Return:	itemCount
	*/
	Node<T>* peekFrontAddress() const;
};

/*
O(1)
*/
template <class T>
bool Queue<T>::enQueue(T item)
{
	return this->add(item, 0);
}

/*
O(n)
*/
template <class T>
bool Queue<T>::deQueue()
{
	int size;
	size = this->getCurrentSize();

	return this->remove(size);
}

/*
O(1)
*/
template <class T>
T Queue<T>::peek() const
{
	if (this->getCurrentSize() > 0)
	{
		Node<T>* tail = this->getTail();
		return tail->getData();
	}
}

/*
O(1)
*/
template <class T>
int Queue<T>::getSize() const
{
	return this->getCurrentSize();
}

/*
O(1)
*/
template <class T>
Node<T>* Queue<T>::peekAddress() const
{
	if (this->getCurrentSize() > 0)
	{
		Node<T>* tempAddress;
		tempAddress = this->getTail();
		return tempAddress;

	}
}

template <class T>
Node<T>* Queue<T>::peekFrontAddress() const
{
	
	if (this->getCurrentSize() > 0)
	{
		Node<T>* tempAddress;
		tempAddress = this->getHead();
		return tempAddress;

	}
}


#endif