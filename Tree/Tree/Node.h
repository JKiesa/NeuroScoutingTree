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
	bool hasChildren;
	bool isRightChild;
	bool isLeftChild;

	Node * parent;
	Node * leftChild;
	Node * rightChild;
	Node * leftNeighbor;
	Node * rightNeighbor;

	void calculateData();
	//Node* getLeftNeighbor();
    //Node* getRightNeighbor();

	//Node* getLeftNeighbor2(vector<Node*> nodeList);
	//Node* getRightNeighbor2(vector<Node*> nodeList);

	void makeRoot();
	void makeLeftChild();
	void makeRightChild();
};
