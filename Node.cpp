/*
Created By: Jose Hernandez Naranjo
*/

// Node.cpp
template <class T>
Node<T>::Node() : next(nullptr)
{
}

template <class T>
T Node<T>::getData() const
{
	return data;
}

template <class T>
Node<T>* Node<T>::getNext() const
{
	return next;
}

template <class T>
bool Node<T>::setData(T item)
{
	data = item;
	return true;
}

template <class T>
bool Node<T>::setNext(Node<T>* nextNode)
{
	next = nextNode;
	return true;
}