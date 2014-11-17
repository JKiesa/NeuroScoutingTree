#include "Tree.h"
#include <iostream>
#include <cstring>
using namespace std;

void main()
{
	Tree tree;

	int numLevels;
	cout << "Enter number of levels: ";
	cin >> numLevels;
	while(numLevels < 1)
	{
		cout << "Enter number of levels (greater than 0): ";
		cin >> numLevels;
	}

	vector<Node*> nodeTree = tree.makeTree(numLevels);

	for(Node* n : nodeTree)
	{
		cout << n->leftChild->data << endl;
	}

}