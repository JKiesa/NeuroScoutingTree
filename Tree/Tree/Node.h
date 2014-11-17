#pragma once

class Node
{
public:
	Node(void);
	~Node(void);

	int data;
	int level;
	int column;
	bool isRoot;
	bool isRightChild;
	bool isLeftChild;

	Node * parent;
	Node * leftChild;
	Node * rightChild;
	Node * leftNeighbor;
	Node * rightNeighbor;

	void calculateData();
	void makeRoot();
	void makeLeftChild();
	void makeRightChild();
};
