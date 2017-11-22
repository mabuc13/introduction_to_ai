#include "tree.h"

tree::tree()
{
}

tree::tree(int dat, tree * lf, tree * rt, tree * dw, tree * u, int h)
{
	data = dat;
	left = lf;
	right = rt;
    down = dw;
    up = u;
	height = h;
}

tree::~tree()
{
}

tree * tree::insert(tree * root, int data, int depth, vector<vector<int>> intMap)
{
	if (root == NULL)
	{
		root = getNewNode(data, root);
		root->depth = depth;
	}


    switch (data)
    {

        case 21:                                            //Up
            depth++;
            root->up = insert(root->up, 21, depth, intMap);
            break;

        case 22:                                            //Right
            root->right = insert(root->right, 22, depth, intMap);
            break;

        case 23:                                            //Down
            root->down = insert(root->down, 23, depth, intMap);
            break;

        case 24:                                            //Left
            root->left = insert(root->left, 24, depth, intMap);
            break;

        default:
            break;
    }


//	else if (data <= root->data)
//	{
//		depth++;
//		root->left = insert(root->left, data, depth);
		
//	}
//	else
//	{
//		depth++;
//		root->right = insert(root->right, data, depth);
		
//	}
	return root;
}

tree * tree::getNewNode(int data, tree * root)
{
    tree * newNode = new tree();
	newNode->data = data;
    newNode->right = newNode->left = newNode->up = newNode->down = NULL;
	return newNode;
}

int tree::getNodesAmount( tree * root)
{
	int totalAmount = 0;
	if (root != NULL)
		totalAmount++;
	if (root == NULL)
		return totalAmount;
	totalAmount +=getNodesAmount(root->right);
	totalAmount +=getNodesAmount(root->left);
}

int tree::getLeavesAmount(tree * root)
{
	int amountOfLeaves = 0;
	if (root == NULL)
		return amountOfLeaves;
	if ((root->left == NULL) && (root->right == NULL) )
		amountOfLeaves++;
	amountOfLeaves += getLeavesAmount(root->right);
	amountOfLeaves += getLeavesAmount(root->left);
}

int tree::getFullNodesAmount(tree * root)
{
	int amountOfFN = 0;
	if (root == NULL)
		return amountOfFN;
	if ((root->left != NULL) && (root->right != NULL))
		amountOfFN++;
	amountOfFN += getFullNodesAmount(root->right);
	amountOfFN += getFullNodesAmount(root->left);
}

void tree::startClock()
{
	t1 = high_resolution_clock::now();
}

void tree::stopClock()
{
	t2 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(t2 - t1).count();
	cout << "The methods execution time was: " << duration << " miliseconds." << endl;
}

void tree::inOrderTraversal(tree * root)
{
	if (root == NULL)
		return;
	inOrderTraversal(root->left);
	cout << root->data << endl;
	inOrderTraversal(root->right);
}

void tree::postOrderTraversal(tree * root)
{
	if (root == NULL)
		return;
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout << root->data << endl;
}

void tree::preOrderTraversal(tree * root)
{
	if (root == NULL)
		return;
	cout << root->data << endl;
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
	
}

void tree::levelOrderTraversal(tree * root)
{
	
	for (int i = 0; i <= assignHeight(root); i++)
	{
		printGivenDepth(root, i);
	}

}


int tree::assignHeight(tree * root)
{
	if (root == NULL)
		return -1;
	else
		return 1 + max(assignHeight(root->left), assignHeight(root->right));

}

void tree::printGivenDepth(tree * root, int i)
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



void tree::printTree(tree * root, int h)
{
	if (root == NULL)
	return;
	for (int i = 0; i < h; i++)
	{
		cout << "....";
	}
    printTree(root->up, h+1);
    printTree(root->right,h+1);
    printTree(root-> down, h+1);
	cout << root->data << endl;
    printTree(root->left, h+1);

}

