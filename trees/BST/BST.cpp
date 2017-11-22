#include "BST.h"

BST::BST()
{
}

BST::BST(int dat, BST * lf, BST * rt, int h)
{
	data = dat;
	left = lf;
	right = rt;
	height = h;
}

BST::~BST()
{
}

BST * BST::insert(BST * root, int data, int depth)
{
	if (root == NULL)
	{
		root = getNewNode(data, root);
		root->depth = depth;
	}
	else if (data <= root->data)
	{
		depth++;
		root->left = insert(root->left, data, depth);
		
	}
	else
	{
		depth++;
		root->right = insert(root->right, data, depth);
		
	}
	return root;
}

BST * BST::getNewNode(int data, BST * root)
{
	BST * newNode = new BST();
	newNode->data = data;
	newNode->right = newNode->left = NULL;
	return newNode;
}

int BST::getNodesAmount( BST * root)
{
	int totalAmount = 0;
	if (root != NULL)
		totalAmount++;
	if (root == NULL)
		return totalAmount;
	totalAmount +=getNodesAmount(root->right);
	totalAmount +=getNodesAmount(root->left);
}

int BST::getLeavesAmount(BST * root)
{
	int amountOfLeaves = 0;
	if (root == NULL)
		return amountOfLeaves;
	if ((root->left == NULL) && (root->right == NULL) )
		amountOfLeaves++;
	amountOfLeaves += getLeavesAmount(root->right);
	amountOfLeaves += getLeavesAmount(root->left);
}

int BST::getFullNodesAmount(BST * root)
{
	int amountOfFN = 0;
	if (root == NULL)
		return amountOfFN;
	if ((root->left != NULL) && (root->right != NULL))
		amountOfFN++;
	amountOfFN += getFullNodesAmount(root->right);
	amountOfFN += getFullNodesAmount(root->left);
}

void BST::startClock()
{
	t1 = high_resolution_clock::now();
}

void BST::stopClock()
{
	t2 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(t2 - t1).count();
	cout << "The methods execution time was: " << duration << " miliseconds." << endl;
}

void BST::inOrderTraversal(BST * root)
{
	if (root == NULL)
		return;
	inOrderTraversal(root->left);
	cout << root->data << endl;
	inOrderTraversal(root->right);
}

void BST::postOrderTraversal(BST * root)
{
	if (root == NULL)
		return;
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout << root->data << endl;
}

void BST::preOrderTraversal(BST * root)
{
	if (root == NULL)
		return;
	cout << root->data << endl;
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
	
}

void BST::levelOrderTraversal(BST * root)
{
	
	for (int i = 0; i <= assignHeight(root); i++)
	{
		printGivenDepth(root, i);
	}

}


int BST::assignHeight(BST * root)
{
	if (root == NULL)
		return -1;
	else
		return 1 + max(assignHeight(root->left), assignHeight(root->right));

}

void BST::printGivenDepth(BST * root, int i)
{
	if (root == NULL)
		return;
	if (root->depth == i)
		cout << root->data << endl;
	else
	{
		printGivenDepth(root->left, i );
		printGivenDepth(root->right, i );
	}
}



void BST::printTree(BST * root, int h)
{
	if (root == NULL)
	return;
	for (int i = 0; i < h; i++)
	{
		cout << "....";
	}
	printTree(root->left, h+1);
	cout << root->data << endl;
	printTree(root->right,h+1);
}

