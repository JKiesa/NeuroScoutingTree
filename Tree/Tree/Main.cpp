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

	//Make the tree
	vector<Node*> nodeTree = tree.makeTree(numLevels);

	//Print out the data
	for(int x=1; x<=numLevels; x++)
	{
		for(Node* node : nodeTree)
		{
			if(node->level == x)
			{
				cout << node->data << " ";
				delete node;
			}
		}
		cout << endl;
	}

}