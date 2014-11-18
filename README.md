NeuroScoutingTree
=================

I wrote the program in Visual Studio 2012. Use CTRL+F5 to compile.

I made use of two classes, Tree and Node. 
Node: Has variables regarding its place in the tree, its parent node, and child and neighbor nodes.
Methods: 
calculateData() takes the parent's data and adds it too the current node. It checks if it needs the parent's left or right neighbor data and adds that accordingly if there is a neighbor.

makeRoot() simply gives the first node the properties it should have. I used to just put the code in the makeTree method but made a separate method just so makeTree looked neater.

make(Left/Right)Child() gives the current node's children the correct properties

Tree:Contains the vector of nodes in the tree as well as makeTree() and methods to acces neighbor nodes.
Methods:
get(Left/Right)Neighbor() returns the node to the left or right of the current node. Each node has a level and column. The leftNeighbor will be the node with the same level and column-1 of the current node. The rightNeighbor will also be on the same level but column+1 from the current node. I had these in the Node class at first but moved them to Tree because I had to acces the nodeList which is in Tree

makeTree() is the main method of the program. The nodeList is not a 2d array but I organized the nodes into levels and columns.
It makes the rootNode and it's children nodes the frist time through. Every iteration, it goes through the last level in the tree and sets the neighborNodes of each node then makes the left and right children in left to right order. It basically creates children nodes of already created nodes instead of creating a node and giving it a parent.

Flow: After the user inputs a number, makeTree() is called to make that many of levels. It runs through a nested for loop to populate the nodeList one level at a time from left to right. After it is done, it returns a vector<Node*> with the nodes in order of level and column. They get printed out with each level on its own line.

