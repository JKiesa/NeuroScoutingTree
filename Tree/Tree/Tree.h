#pragma once
#include "Node.h"
#include <iostream>
#include <vector>
using namespace std;

class Tree
{
public:
	Tree(void);
	~Tree(void);

	vector<Node> nodeList;
	Node currentNode;
	int currentList;

	void makeTree(int numLevels);
};


