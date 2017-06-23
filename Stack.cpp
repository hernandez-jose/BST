// Stack.cpp

template <class T>
bool Stack<T>::pop()
{
	int size;

	size = this->getCurrentSize();
	this->remove(size);
	return true;
}

template <class T>
bool Stack<T>::push(T item)
{
	int size;
	size = this->getCurrentSize();

	this->add(item, size);
	return true;
}

template <class T>
T Stack<T>::peek()
{
	Node<T>* tempTail;
	tempTail = this->getTail();

	if (tempTail != nullptr)
		return tempTail->getData();
}

template <class T>
Node<T>* Stack<T>::peekAddress()
{
	Node<T>* tempTail;
	tempTail = this->getTail();

	return tempTail;
}
