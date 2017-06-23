/*
Created By: Jose Hernandez Naranjo
*/

// LinkedList.cpp

#include<iostream>

template <class T>
LinkedList<T>::LinkedList() : itemCount(0), head(nullptr), tail(nullptr), current(nullptr), previous(nullptr)
{
}

template <class T>
LinkedList<T>::~LinkedList()
{
	current = head;
	while (current != nullptr)
	{
		previous = current;
		current = current->getNext();
		delete previous;
		previous = nullptr;
	}
	tail = nullptr;
	head = nullptr;
	itemCount = 0;
}

template <class T>
bool LinkedList<T>::add(T item, int index)
{
	// out of bound indexes return false
	if ((index < 0) || (index > itemCount))
		return false;

	Node<T>* newNode = new Node<T>();

	// if list is empty
	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
		newNode->setData(item);
		newNode->setNext(nullptr);
		itemCount++;
		return true;
	}
	else
	{
		current = head; // start from the beginning
		int x = 1;
		do
		{
			if (index == 0) // insert at beginning of chain
			{
				newNode->setNext(current);
				newNode->setData(item);
				head = newNode;
				itemCount++;
				return true;
			}
			if (index == x) // inserts anywhere else
			{
				if (current->getNext() != nullptr) // somewhere in the middle
				{
					newNode->setNext(current->getNext());
					newNode->setData(item);
					current->setNext(newNode);
					itemCount++;
					return true;
				}
				else // at the end
				{
					newNode->setNext(nullptr);
					newNode->setData(item);
					current->setNext(newNode);
					tail = newNode;
					itemCount++;
					return true;
				}
			}

			current = current->getNext(); // move to next item
			x++;
		} while (current != nullptr);
	}

	return false;
}

template <class T>
bool LinkedList<T>::remove(int index)
{
	// out of bound indexes return false
	if ((index < 0) || (index > itemCount))
		return false;

	if (head == nullptr)
		return false;
	else
	{
		current = head;
		int x = 1;
		do
		{
			if ((index == 0) || (index == 1)) // at the beginning
			{
				head = current->getNext();
				if (current->getNext() == nullptr)
					tail = nullptr;
				delete current;
				current = nullptr;
				itemCount--;
				return true;
			}
			if (index == x)
			{
				previous->setNext(current->getNext());
				if (current->getNext() == nullptr)
					tail = previous;
				delete current;
				current = nullptr;
				itemCount--;
				return true;
			}
			previous = current;
			current = current->getNext(); // move to next item
			x++;
		} while (current != nullptr);
	}
	return false;
}

template <class T>
int LinkedList<T>::getCurrentSize() const
{
	return itemCount;
}

template <class T>
bool LinkedList<T>::isEmpty()
{
	if (itemCount == 0)
		return true;
	else
		return false;
}

template <class T>
bool LinkedList<T>::find(const T item) const
{
	current = head;
	while (current != nullptr)
	{
		if (current->getData() == item)
			return true;
		current = current->getNext(); // move to next item
	}
	return false;
}

template <class T>
bool LinkedList<T>::clear()
{
	current = head;
	while (current != nullptr)
	{
		previous = current;
		current = current->getNext();
		delete previous;
		previous = nullptr;
	}
	tail = nullptr;
	head = nullptr;
	itemCount = 0;
	return true;
}

template <class T>
void LinkedList<T>::show()
{
	current = head;

	while (current != nullptr)
	{
		std::cout << current->getData() << std::endl;
		current = current->getNext();
	}
}

template <class T>
Node<T>* LinkedList<T>::getTail() const
{
	return tail;
}

template <class T>
Node<T>* LinkedList<T>::getHead() const
{
	return head;
}