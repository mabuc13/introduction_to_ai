#pragma once
#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
using namespace std;
using namespace std::chrono;
#define upD 21
#define righdD 22
#define downD 23
#define leftD 24
class tree
{
public:
    tree();
    tree(int dat, tree * lf, tree * rt, tree * dw, tree * u, int h); //Data is the direction
    ~tree();
    tree * insert(tree * root, int data, int depth, vector<vector<int>> intMap);
    tree * getNewNode(int data, tree * root);
    int getNodesAmount(tree * root);
    int getLeavesAmount(tree * root);
    void printTree(tree * root, int h);
    int getFullNodesAmount(tree * root);
	void startClock();
	void stopClock();
    void inOrderTraversal(tree * root);
    void postOrderTraversal(tree * root);
    void preOrderTraversal(tree * root);
    void levelOrderTraversal(tree * root);
    int  assignHeight(tree * root);
    void printGivenDepth(tree * root, int i);
public:
	int data;
    tree * left;    //the four directions the robot can move
    tree * right;
    tree * up;
    tree * down;
	int height;
	int depth;
	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2;
    vector<vector<int> >  intMap;

};

