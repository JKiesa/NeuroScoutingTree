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
		Node * parentRightNeighbor = getRightNeighbor();
		data = parent->data;
		if(parentRightNeighbor != nullptr)
		{
			data += parentRightNeighbor->data;
		}
	}
	else//Is left child
	{
		Node * parentLeftNeighbor = getLeftNeighbor();
		data = parent->data;
		if(parentLeftNeighbor != nullptr)
		{
			data += parentLeftNeighbor->data;
		}
	}
}

//Returns the Left Neighbor of the Node that called it
Node* Node::getLeftNeighbor()
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
}
