#pragma once
#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include "intmap.h"
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
    tree * insert(tree * root, int data, int depth, intMap map, int direction);
    tree * getNewNode(int data, tree * root, intMap oneMap);
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
    void setVerbose(bool ver);
    void printInit(tree * root);
    //Methods to move the robot in the map according to sokoban rules
//    bool legalUp(intMap map);
//    bool legalRight(intMap map);
//    bool legalDown(intMap map);
//    bool legalLeft(intMap map);

//    intMap moveUp(intMap map);
//    intMap moveRight(intMap map);
//    intMap moveDown(intMap map);
//    intMap moveLeft(intMap map);

public:
	int data;
    tree * left;    //the four directions the robot can move
    tree * right;
    tree * up;
    tree * down;
    tree * parent;

	int height;
	int depth;
	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2;
    intMap  map;
    bool Verbose;
private:
    bool init;


};

