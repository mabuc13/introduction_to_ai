#ifndef INTMAP_H
#define INTMAP_H
#include <vector>
#include <iostream>
#include "intmap.h"

using namespace std;
class intMap
{
public:
    intMap();
    intMap(vector<vector<int> > inputMap, int w, int h, int xPos, int yPos, int noGoals);
    ~intMap();

    bool legalUp();
    bool legalRight();
    bool legalDown();
    bool legalLeft();

    char moveUp();
    char moveRight();
    char moveDown();
    char moveLeft();

    bool puzzleSolved(); //This is is simplified method, only good for small scale testing with one box
    bool badMap();
    void printMap();
public:
    bool solved;
    int x; //Robots x position
    int y; //Robots y position
    vector<vector<int> > map;
    vector<vector<int> > origMap;
    int height;
    int width;
    int freeGoals;
    bool deadMap;

};

#endif // INTMAP_H
