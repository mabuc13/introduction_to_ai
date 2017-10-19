#ifndef SOKABANLOADER_H
#define SOKABANLOADER_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
class SokabanLoader
{
public:
    SokabanLoader();
    int loaderFSM(string location, bool forcestate, int statetoForce); //Returning current state
    void loadMap(string location);
    vector<vector<char> > initMap(int width, int height);
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
