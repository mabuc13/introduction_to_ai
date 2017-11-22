#include <iostream>
#include "sokabanloader.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    SokabanLoader test;
    test.loadMap("testMap.txt");


    //test.printMap();

    //test.initMap(10, 10);
   // Graph* map = new Graph;

    //map = test.vectorToGraph();
    //map->printGraph();
    return 0;
}

