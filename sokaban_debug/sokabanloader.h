#ifndef SOKOBANLOADER_H
#define SOKOBANLOADER_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
class SokobanLoader
{
public:
    SokobanLoader();
    int loaderFSM(string location, bool forcestate, int statetoForce); //Returning current state
    void loadMap(string location);
    vector<vector<int>> initMap(int width, int height);
    void generateTree(vector<vector<int>> map); // Should return tree
    void expandTree(vector<vector<int>> map, int x, int y); // Void, only adds nodes to tree
    //General debugging methods
    void printMap();

private:
    vector<vector<int> >  intMap; //Storing in vector vector gives the implicit x, y value

    //FSM variables
    int currentState;
    int nextState;

    //Map variables
    int width;
    int height;
    int noDiamonds;
};

#endif // SOKOBANLOADER_H
