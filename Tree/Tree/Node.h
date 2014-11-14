#pragma once
class Node
{
public:
	Node(void);
	~Node(void);

	int data;
	int level;
	bool hasChildren;
	bool isRightChild;
	bool isLeftChild;

	Node * parent;
	Node * leftChild;
	Node * rightChild;

	void calculateData();
	int getLeftNeighborData();
	int getRightNeightborData();
};
