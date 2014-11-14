#include "Tree.h"


Tree::Tree(void)
{
}


Tree::~Tree(void)
{
}

void Tree::makeTree(int numLevels)
{
	for(int x=1; x<=numLevels; x++)
	{
		Node newNode;
		if(x==1)
		{
			newNode.isRoot = true;
			newNode.data = 1;
		}

		if(x==numLevels)
		{
			newNode.hasChildren = false;
		}

		newNode.level = x;
	}
}
