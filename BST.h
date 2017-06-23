/*
Created By: Jose Hernandez Naranjo
*/

#ifndef BST_H
#define BST_H

#include <iomanip>
#include "TreeNode.h"
#include "Queue.h"

template<class T>
class BST
{
private:
	TreeNode<T>* root;
	int count; // items in binary tree

protected:
	TreeNode<T>* regAdd(TreeNode<T>*, TreeNode<T>*);

	void preorder(void visit(T&), TreeNode<T>*) const;
	void inorder(void visit(T&), TreeNode<T>*) const;
	void postorder(void visit(T&), TreeNode<T>*) const;

	/*
	   functions to recursively remove items from a tree
	*/
	TreeNode<T>* removeNode(TreeNode<T>*, const T&, bool&); // finds item then calls on deleteNode
	TreeNode<T>* deleteNode(TreeNode<T>*, bool&); // all cases; leaf, one child, and two children.
	TreeNode<T>* findSuccessor(TreeNode<T>*, T&, bool&); // finds the item that should replace data being deleted

	int  getHeightHelper(TreeNode<T>*) const;
	TreeNode<T>* deleteTree(TreeNode<T>*);
	bool searchHelper(TreeNode<T>*, const T&);

public:
	bool add(const T);
	void removeTree();

	bool remove(const T);
	bool modify(const T, const T);
	bool search(const T&);

	bool isEmpty() const;
	int getHeight() const;
	int getNumberOfNodes() const;

	//------------------------------------------------------------
	// Public Traversals Section.
	//------------------------------------------------------------

	void preorderTraverse(void visit(T&)) const;
	void inorderTraverse(void visit(T&)) const;
	void postorderTraverse(void visit(T&)) const;
	void breadthFirstTraverse(void visit(T&)) const;
	
	
	//------------------------------------------------------------
	// constructor
	//------------------------------------------------------------
	BST();
	virtual ~BST();
};



#include "BST.cpp"


#endif
