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

void Node::makeRoot()
{
	isRoot = true;
	isLeftChild = false;
	isRightChild = false;
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
