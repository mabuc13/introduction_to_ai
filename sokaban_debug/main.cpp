#include <iostream>
#include "sokobanloader.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    SokobanLoader test;
    while (true)
    {

        int temp = test.loaderFSM("exampleMap.txt", 0, 0);
        //cout << temp << endl; // Print FSM Status
        if (temp == 3)
            break;
    }
    //test.printMap();

    //test.initMap(10, 10);
    //Graph* map = new Graph;

    //map = test.vectorToGraph();
    //map->printGraph();
    return 0;
}

