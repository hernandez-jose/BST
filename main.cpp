/*
   Created By: Jose Hernandez Naranjo
*/

#include<iostream>
#include "BST.h"

using namespace std;

void visit(int& info)
{
	cout << info << endl;
}

int main()
{
	BST<int> data;

	data.add(100);
	data.add(50);
	data.add(150);
	data.add(60);
	data.add(65);
	data.add(55);
	data.add(155);
	data.add(125);
	data.add(135);

	data.postorderTraverse(visit);
	data.removeTree();

	system("PAUSE");
	return 0;
}