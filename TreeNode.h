/*
Created By: Jose Hernandez Naranjo
*/

#ifndef TREENODE_H
#define TREENODE_H

template<class ItemType>
class TreeNode
{
private:
	ItemType					item;        // Data portion
	TreeNode<ItemType>*			leftChild;   // Index to left child
	TreeNode<ItemType>*			rightChild;  // Index to right child

public:
	TreeNode();
	TreeNode(const ItemType&, TreeNode<ItemType>*, TreeNode<ItemType>*);
	
	void setLeft(TreeNode<ItemType>*);
	void setRight(TreeNode<ItemType>*);
	void setItem(const ItemType&);

	bool isLeaf();
	bool hasTwoChildren();

	TreeNode<ItemType>* getLeft() const;
	TreeNode<ItemType>* getRight() const;
	ItemType getItem() const;

	// Declarations of the methods setItem, getItem, setLeft, getLeft,
	// setRight, and getRight are here.
}; // end TreeNode

template<class ItemType>
TreeNode<ItemType>::TreeNode(const ItemType& data, TreeNode<ItemType>* left, TreeNode<ItemType>* right)
{
	item = data;
	leftChild = left;
	rightChild = right;
}

template<class ItemType>
TreeNode<ItemType>::TreeNode() : leftChild(nullptr), rightChild(nullptr)
{

}

template<class ItemType>
void TreeNode<ItemType>::setLeft(TreeNode<ItemType>* left)
{
	leftChild = left;
}

template<class ItemType>
void TreeNode<ItemType>::setRight(TreeNode<ItemType>* right)
{
	rightChild = right;
}

template<class ItemType>
void TreeNode<ItemType>::setItem(const ItemType& data)
{
	item = data;
}

template<class ItemType>
TreeNode<ItemType>* TreeNode<ItemType>::getLeft() const
{
	return leftChild;
}

template<class ItemType>
TreeNode<ItemType>* TreeNode<ItemType>::getRight() const
{
	return rightChild;
}

template<class ItemType>
ItemType TreeNode<ItemType>::getItem() const
{
	return item;
}

template<class ItemType>
bool TreeNode<ItemType>::isLeaf()
{
	if ((leftChild == nullptr) && (rightChild == nullptr))
		return true;
	else
		return false;
}

template<class ItemType>
bool TreeNode<ItemType>::hasTwoChildren()
{
	if ((leftChild != nullptr) && (rightChild != nullptr))
		return true;
	else
		return false;
}

#endif