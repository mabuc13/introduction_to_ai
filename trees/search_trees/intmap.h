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
    intMap(vector<vector<int> > inputMap, int w, int h, int xPos, int yPos);
    ~intMap();

    bool legalUp();
    bool legalRight();
    bool legalDown();
    bool legalLeft();

    void moveUp();
    void moveRight();
    void moveDown();
    void moveLeft();

    bool puzzleSolved(); //This is is simplified method, only good for small scale testing with one box
    void printMap();
public:
    bool solved;
    int x; //Robots x position
    int y; //Robots y position
    vector<vector<int> > map;
    int height;
    int width;

};

#endif // INTMAP_H
