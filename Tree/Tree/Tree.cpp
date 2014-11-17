#include "Tree.h"


Tree::Tree(void)
{
}


Tree::~Tree(void)
{
}

Node* Tree::getLeftNeighbor(Node* n)
{	
	for(Node* node: nodeList)
	{
		if(node->level == n->level && node->column == n->column-1)
		{
			return node;
		}
	}
	return nullptr;
}

Node* Tree::getRightNeighbor(Node* n)
{
	for(Node* node: nodeList)
	{
		if(node->level == n->level && node->column == n->column+1)
		{
			return node;
		}
	}
	return nullptr;
}

vector<Node*> Tree::makeTree(int numLevels)
{
	for(int x=1; x<=numLevels; x++)
	{
		int numColumns = pow(2.0, x-1.0);//The number of nodes that are in this level
		for(int y=1; y<=numColumns; y++)
		{
			if(x==1)//Root node
			{
				Node * newNode = new Node;
				newNode->makeRoot();
				nodeList.push_back(newNode);
			}
			
			if(x < numLevels)//There are more levels
			{
				//Makes the children nodes of the nodes in the latest level of the tree
				for(Node* n : nodeList)
				{
					if(n->column == y && n->level == x && n->hasChildren == false)
					{
						n->leftNeighbor = getLeftNeighbor(n);
						n->rightNeighbor = getRightNeighbor(n);

						n->makeLeftChild();
						n->leftChild->calculateData();
						nodeList.push_back(n->leftChild);

						n->makeRightChild();
						n->rightChild->calculateData();
						nodeList.push_back(n->rightChild);

						n->hasChildren = true;
					}
				}//end for each
			}//end else
		}//end for y
	}//end for x

	return nodeList;
}//end makeTree
