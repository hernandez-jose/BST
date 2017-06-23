/*
Created By: Jose Hernandez Naranjo
*/

// BST.cpp
// constructors
template<class T>
BST<T>::BST() : root(nullptr)
{
}

template<class T>
BST<T>::~BST()
{
	root = deleteTree(root); // deletes allocated memory
}

template <class T>
void BST<T>::removeTree()
{
	root = deleteTree(root); // deletes allocated memory
}

template <class T>
TreeNode<T>* BST<T>::deleteTree(TreeNode<T>* subTree)
{
	if (subTree != nullptr)
	{
		deleteTree(subTree->getLeft());
		deleteTree(subTree->getRight());
		delete subTree;
		count--;
		return nullptr;
	}
}

//------------------------------------------------------------
// Modifying functions
//------------------------------------------------------------

template <class T>
bool BST<T>::add(const T data)
{
	TreeNode<T>* newNode = new TreeNode<T>();
	newNode->setItem(data);
	count++;

	root = regAdd(root, newNode);
	
	return true;
}

template <class T>
TreeNode<T>* BST<T>::regAdd(TreeNode<T>* subTree, TreeNode<T>* newNode)
{
	if (subTree == nullptr) // base case
	{
		return newNode; // found a loaction
	}
	else if (subTree->getItem() > newNode->getItem()) // goto left child
	{
		auto tempPtr = regAdd(subTree->getLeft(), newNode);
		subTree->setLeft(tempPtr);
	}
	else // goto right child item root->getItem() <= newNode->getItem()
	{
		auto tempPtr = regAdd(subTree->getRight(), newNode);
		subTree->setRight(tempPtr);
	}
	return subTree;
}


/*
	Remove node from a binary search tree, keeping properties of the tree.
	Three cases: It is a leaf; has one child; has two children.
*/
template <class T>
bool BST<T>::remove(const T data)
{
	bool check = false;
	root = removeNode(root, data, check);
	return check;
}

template <class T>
TreeNode<T>* BST<T>::removeNode(TreeNode<T>* subTree, const T& target, bool& status)
{
	if (subTree == nullptr) // base case
		return subTree;
	else if (subTree->getItem() == target) // match found
		return deleteNode(subTree, status);
	else if (subTree->getItem() > target) // search left
	{
		auto temp = removeNode(subTree->getLeft(), target, status); // keep searching
		subTree->setLeft(temp);
		return subTree; // reconnect tree
	}
	else // search right
	{
		auto temp = removeNode(subTree->getRight(), target, status); // keep searching
		subTree->setRight(temp);
		return subTree; // reconnect tree
	}
}

template <class T>
TreeNode<T>* BST<T>::deleteNode(TreeNode<T>* subTree, bool& status)
{
	if (subTree->isLeaf()) // case 1
	{
		delete subTree;
		count--;
		status = true;
		return nullptr;
	}
	else if (subTree->hasTwoChildren()) // case 2
	{
		T successor; // temp store successor
		auto temp = findSuccessor(subTree->getRight(), successor, status); // modify successor and return right branch nodes
		subTree->setItem(successor); // copy successor to current node
		subTree->setRight(temp); // connect right branch
		return subTree;
	}
	else // case 3 has one child
	{
		if (subTree->getLeft() != nullptr) // connect left nodes
		{
			auto connect = subTree->getLeft(); // get left branch
			delete subTree;
			status = true;
			count--;
			subTree = nullptr;
			return connect;
		}
		else // connect right nodes
		{
			auto connect = subTree->getRight(); // get right branch
			delete subTree;
			status = true;
			count--;
			subTree = nullptr;
			return connect;
		}
	}
}

// finds and modify successor to be copied to item being deleted
// returns a tree node branch
template <class T>
TreeNode<T>* BST<T>::findSuccessor(TreeNode<T>* subTree, T& successor, bool& status)
{
	if (subTree->getLeft() == nullptr) // base case: cannot go left anymore
	{
		successor = subTree->getItem();
		return deleteNode(subTree, status);
	}
	else
	{
		auto temp = findSuccessor(subTree->getLeft(), successor, status);
		subTree->setLeft(temp);
		return subTree;
	}
}


template <class T>
bool BST<T>::modify(const T data, const T replacement)
{
	bool checkNode = false, checkAdd = false;
	root = removeNode(root, data, checkNode);
	
	if (checkNode) // create new node and add
	{
		TreeNode<T>* newNode = new TreeNode<T>();
		newNode->setItem(replacement);
		count++;

		root = regAdd(root, newNode);
	}

	// post status
	if ( (checkNode == true) && (checkAdd == true) )
		return true;
	else
		return false;
}

template <class T>
bool BST<T>::isEmpty() const
{
	if (root == nullptr)
		return true;
	else
		return false;
}

template <class T>
int BST<T>::getHeight() const
{
	return getHeightHelper(root);
}

template <class T>
int BST<T>::getHeightHelper(TreeNode<T>* subTree) const
{
	if (subTree == nullptr)
		return 0;
	else
	{
		int right = getHeightHelper(subTree->getRight());
		int left = getHeightHelper(subTree->getLeft());
		int max = 0;

		if (right > left)
			max = right;
		else
			max = left;

		return 1 + max;
	}
}


template <class T>
int BST<T>::getNumberOfNodes() const
{
	return count;
}

/*
	Traversal functions
*/
template <class T>
void BST<T>::preorder(void visit(T&), TreeNode<T>* subTree) const
{
	if (subTree != nullptr)
	{
		auto temp = subTree->getItem();
		visit(temp);
		preorder(visit, subTree->getLeft());
		preorder(visit, subTree->getRight());
	}
}

template <class T>
void BST<T>::inorder(void visit(T&), TreeNode<T>* subTree) const
{
	if (subTree != nullptr)
	{
		inorder(visit, subTree->getLeft());
		auto temp = subTree->getItem();
		visit(temp);
		inorder(visit, subTree->getRight());
	}
}

template <class T>
void BST<T>::postorder(void visit(T&), TreeNode<T>* subTree) const
{
	if (subTree != nullptr)
	{
		postorder(visit, subTree->getLeft());
		postorder(visit, subTree->getRight());
		auto temp = subTree->getItem();
		visit(temp);
	}
}

template <class T>
void BST<T>::preorderTraverse(void visit(T&)) const
{
	preorder(visit, root);
}

template <class T>
void BST<T>::inorderTraverse(void visit(T&)) const
{
	inorder(visit, root);
}

template <class T>
void BST<T>::postorderTraverse(void visit(T&)) const
{
	postorder(visit, root);
}

template <class T>
void BST<T>::breadthFirstTraverse(void visit(T&)) const
{
	Queue< TreeNode<T>* > list;
	TreeNode<T>* temp;
	T tempItem;

	list.enQueue(root);

	while (list.getSize() > 0) // while something in the queue
	{
		temp = list.peek();
		tempItem = temp->getItem();

		visit(tempItem);

		// add both child to a queue for later processing
		if (temp->hasTwoChildren())
		{
			list.enQueue(temp->getLeft());
			list.enQueue(temp->getRight());
		}
		else if (!temp->isLeaf())
		{
			if (temp->getLeft() != nullptr) // check which node has data
				list.enQueue(temp->getLeft());
			else
				list.enQueue(temp->getRight());
		}

		list.deQueue();
	}
}


template <class T>
bool BST<T>::search(const T& data)
{
	return searchHelper(root, data);
}

template <class T>
bool BST<T>::searchHelper(TreeNode<T>* subTree, const T& data)
{
	if (subTree == nullptr) // not found
		return false;
	else if (subTree->getItem() == data) // item found
		return true;
	else if (subTree->getItem() > data) // go left
		searchHelper(subTree->getLeft(), data);
	else  // go right
		searchHelper(subTree->getRight(), data);
	
}

