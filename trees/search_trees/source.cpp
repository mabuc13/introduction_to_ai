#include <iostream>
#include "BST.h"
using namespace std;



int main()
{
	BST dummy;
	BST * root = NULL;

	root = root->insert(root, 15, 0);
	root = root->insert(root, 10, 0);
	root = root->insert(root, 20, 0);
	root = root->insert(root, 25, 0);
	root = root->insert(root, 8, 0);
	root = root->insert(root, 12, 0);
	root = root->insert(root, 18, 0);
	root = root->insert(root, 13, 0);
	root = root->insert(root, 11, 0);
	cout << "In order traversal" << endl;
	root->inOrderTraversal(root);
	cout << "Post order traversal" << endl;
	root->postOrderTraversal(root);
	cout << "Pre order traversal" << endl;
	root->preOrderTraversal(root);
	cout << "Level order traversal" << endl;
	root->levelOrderTraversal(root);
	dummy.startClock();
	cout << "Amount of nodes: " << root->getNodesAmount( root) << endl;
	dummy.stopClock();
	dummy.startClock();
	cout << "Amount of leaves: "<< root->getLeavesAmount(root) << endl;
	dummy.stopClock();
	dummy.startClock();
	cout << "Amount of full nodes: " << root->getFullNodesAmount(root) << endl;
	dummy.stopClock();
}