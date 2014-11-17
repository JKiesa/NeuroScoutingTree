#include "Node.h"


Node::Node(void)
{
}


Node::~Node(void)
{
}

void Node::calculateData()
{
	if(isRightChild)
	{
		data = parent->data;
		if(parent->rightNeighbor != nullptr)
		{
			data += parent->rightNeighbor->data;
		}
	}
	else//Is left child
	{
		data = parent->data;
		if(parent->leftNeighbor != nullptr)
		{
			data += parent->leftNeighbor->data;
		}
	}
}

//Returns the Left Neighbor of the Node that called it
/*Node* Node::getLeftNeighbor()
{
	Node * current;
	if(isRightChild)
	{
		return parent->leftChild;
	}

	if(parent->isRoot)
	{
		//Will end up not having a left neighbor
		return nullptr;
	}
	else
	{
		current = parent->getLeftNeighbor();
	}
	
	if(current != nullptr)
	{
		//Get the right child of the parent's left neighbor
		return current->rightChild;
	}
	return nullptr;//No left neighbor
}

//Returns the Right neighbor of the Node that called it
Node* Node::getRightNeighbor()
{
	Node * current;
	if(isLeftChild)
	{
		return parent->rightChild;
	}

	if(parent->isRoot)
	{
		//Will end up not having a right neighbor
		return nullptr;
	}
	else
	{
		current = parent->getRightNeighbor();
	}

	if(current != nullptr)
	{
		//Get the left child of the parent's right neighbor
		return current->leftChild;
	}
	return nullptr;//No right neighbor
}*/

/*Node* Node::getLeftNeighbor2(vector<Node*> nodeList)
{
	for(Node* n: nodeList)
	{
		if(n->level == level && n->column == column-1)
		{
			return n;
		}
	}
	return nullptr;
}

Node* Node::getRightNeighbor2(vector<Node*> nodeList)
{
	for(Node* n: nodeList)
	{
		if(n->level == level && n->column == column+1)
		{
			return n;
		}
	}
}*/

void Node::makeRoot()
{
	isRoot = true;
	data = 1;
	level = 1;
	column = 1;
}

void Node::makeLeftChild()
{
	leftChild->isRoot = false;
	leftChild->isLeftChild = true;
	leftChild->isRightChild = false;
	leftChild->parent = this;
	leftChild->level = this->level + 1;
	leftChild->column = (this->column)*2 - 1;
}

void Node::makeRightChild()
{
	rightChild->isRoot = false;
	rightChild->isLeftChild = false;
	rightChild->isRightChild = true;
	rightChild->parent = this;
	rightChild->level = this->level + 1;
	rightChild->column = (this->column)*2;
}
