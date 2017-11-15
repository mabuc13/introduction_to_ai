#ifndef SOKABANLOADER_H
#define SOKABANLOADER_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../Graph/Graph.hpp"

#define freespace = 1;
#define wall = 2;
#define goal = 3;
#define box = 4;
#define robot = 5;
using namespace std;
class SokabanLoader
{
public:
    SokabanLoader();
    int loaderFSM(string location, bool forcestate, int statetoForce); //Returning current state
    void loadMap(string location);
    vector<vector<char> > initMap(int width, int height);
    Graph* vectorToGraph();
    int char2int(char);

    //General debugging methods
    void printMap();
private:
    vector<vector<char> >  charMap; //Storing in vector vector gives the implicit x, y value
    //FSM variables
    int currentState;
    int nextState;

    //Map variables
    int width;
    int height;
    int noDiamonds;
};

#endif // SOKABANLOADER_H
