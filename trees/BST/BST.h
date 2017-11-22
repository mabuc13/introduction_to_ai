#pragma once
#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
using namespace std;
using namespace std::chrono;
class BST
{
public:
	BST();
	BST(int dat, BST * lf, BST * rt, int h);
	~BST();
	BST * insert(BST * root, int data, int depth);
	BST * getNewNode(int data, BST * root);
	int getNodesAmount(BST * root);
	int getLeavesAmount(BST * root);
	void printTree(BST * root, int h);
	int getFullNodesAmount(BST * root);
	void startClock();
	void stopClock();
	void inOrderTraversal(BST * root);
	void postOrderTraversal(BST * root);
	void preOrderTraversal(BST * root);
	void levelOrderTraversal(BST * root);
	int  assignHeight(BST * root);
	void printGivenDepth(BST * root, int i);
public:
	int data;
	BST * left;
	BST * right;
	int height;
	int depth;
	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2;
};

