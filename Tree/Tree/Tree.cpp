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

				//newNode->leftChild = new Node;
				//newNode->rightChild = new Node;
				//newNode->makeLeftChild();
				//newNode->makeRightChild();
				//delete newNode;
			}
			
			if(x < numLevels)//There are more levels
			{
				int numNodes = nodeList.size();
				//Makes the children nodes of the nodes in the latest level of the tree
				for(int i=0; i<numNodes; i++)
				{
					if(nodeList[i]->column == y && nodeList[i]->level == x)
					{
						nodeList[i]->leftNeighbor = getLeftNeighbor(nodeList[i]);
						nodeList[i]->rightNeighbor = getRightNeighbor(nodeList[i]);

						nodeList[i]->leftChild = new Node;
						nodeList[i]->makeLeftChild();
						nodeList[i]->leftChild->calculateData();
						nodeList.push_back(nodeList[i]->leftChild);

						nodeList[i]->rightChild = new Node;
						nodeList[i]->makeRightChild();
						nodeList[i]->rightChild->calculateData();
						nodeList.push_back(nodeList[i]->rightChild);
					}//end if nodeList
				}//end for i
			}//end if x<numLevels
		}//end for y
	}//end for x

	return nodeList;
}//end makeTree
