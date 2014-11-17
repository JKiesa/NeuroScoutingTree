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

	vector<Node*> nodeList;

	vector<Node*> makeTree(int numLevels);
	Node* getLeftNeighbor(Node* n);
	Node* getRightNeighbor(Node* n);
};


