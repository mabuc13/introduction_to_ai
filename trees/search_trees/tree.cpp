#include "tree.h"

tree::tree()
{
    Verbose = true;
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

tree * tree::insert(tree * root, int data, int depth, intMap map, int direction, tree * oneParent)
{
    map.printMap();
    cout << endl;
    if (map.solved)
    {
        //cout << "Root: " << root << endl;
        if (flag)
        {
            root = getNewNode(data, root, map, oneParent);
            map.printMap();
            printPath(root);
            cout << endl;
            cout << endl;
            flag = false;
        }
        //printPath(root);
        return root;
    }
    //cout << "Entering insert" << endl;
    //OBS istedet for at passere mappen i metoden, skal du bruge den map der ligger i et træ
    //Tror ikke den måde jeg navigere rundt i træet på passer
    //cout << "Data: " << data << endl;
    //map.printMap();
    //cout << endl;
    //cout << "root init: " << root->init << endl;
    //printInit(root);
    intMap upMap = map;
    intMap rightMap = map;
    intMap downMap = map;
    intMap leftMap = map;
    //cout << "Is the puzzle solved: " << map.solved << endl;
    //map.printMap();
    //if (root != NULL)
    //    cout << "The init: " << root->init << endl;
    if (root == NULL)
    {
        if (data == 20)
        {
            root = getNewNode(data, root, map, oneParent);
            root->depth = depth;
            root->init = true;
        }
        else
        {
            switch(data)
            {
            case 21:
                if (direction == 21)
                {
                    if (map.legalUp())
                    {
                        upMap.moveUp();
                        root = getNewNode(data, root, upMap, oneParent);
                        root->depth = depth;
                        root->init = true;

                    }
                    else
                        break;
                }
                break;

            case 22:
                if (direction == 22)
                {
                    if (map.legalRight())
                    {
                        rightMap.moveRight();
                        root = getNewNode(data, root, rightMap, oneParent);
                        root->depth = depth;
                    }
                    else
                        break;
                }
                break;

            case 23:
                if (direction == 23)
                {
                    if (map.legalDown())
                    {
                        downMap.moveDown();
                        root = getNewNode(data, root, downMap, oneParent);
                        root->depth = depth;
                    }
                    else
                        break;
                }
                break;

            case 24:
                if (direction == 24)
                {
                    if (map.legalLeft())
                    {
                        leftMap.moveLeft();
                        root = getNewNode(data, root, leftMap, oneParent);
                        root->depth = depth;
                    }
                    else
                        break;
                }
                break;

            default:
                break;

            }

        }
    }
    else
    {
        if (!(map.solved))
        {
            depth++;
        //Traversing the tree until we're in the leaves, where we in the leaves expand the trees

            root->up = insert(root->up, data, depth, root->map, 21, root);

            root->right = insert(root->right, data, depth, root->map, 22, root);

            root->down = insert(root->down, data, depth, root->map, 23, root);

            root->left = insert(root->left, data, depth, root->map, 24, root);

        }
    }
return root;
}

tree * tree::getNewNode(int data, tree * root, intMap oneMap, tree * oneParent)
{
 //   cout << "Called getNewNode" << endl;
    tree * newNode = new tree();
	newNode->data = data;
    newNode->right = newNode->left = newNode->up = newNode->down = NULL;
    newNode->map = oneMap;
    newNode->init = false;
    newNode->parent = oneParent;
   // newNode->map.printMap();
   // cout << endl;
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
        cout << "..";
	}
    cout << root->data << endl;
    printTree(root->up, h+1);
    printTree(root->right,h+1);
    printTree(root-> down, h+1);
    printTree(root->left, h+1);


}

void tree::setVerbose(bool ver)
{

    Verbose = ver;

}

void tree::printInit(tree *root)
{
    cout << root->init << endl;
}

void tree::printPath(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    printPath(root->parent);
    cout << root->data << "->";
    if (root->parent== NULL)
        cout << endl;
    return;

}

//bool tree::legalUp(intMap map) //Left and up is minus, down and right is plus
//{
//    bool allow = true;


//    return allow;
//}

//bool tree::legalRight(intMap map)
//{

//    return allow;
//}

//bool tree::legalDown(intMap map)
//{

//    return allow;
//}

//bool tree::legalLeft(intMap map)
//{

//    return allow;
//}



