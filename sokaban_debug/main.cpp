#include <iostream>
#include "sokabanloader.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <iomanip>
#include <ctime>
using namespace std;

int main()
{

    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y %H:%M:%S");
    auto str = oss.str();

    string filename = oss.str();
    //freopen("solver_output.txt","a",stdout);
    cout << "d-m-y_H:M:S " << oss.str() << endl;
    SokabanLoader loader;

    loader.loadMap("testMap.txt");

    intMap sokobanMap(loader.getIntMap(), loader.getWidth(), loader.getHeight(), loader.xPos, loader.yPos, loader.getGoals());
    tree dummy;
    tree * root = NULL;
    dummy.startClock();
    root = root->insert(root, 20, 0, sokobanMap, 0, NULL);
    cout << "Created root of tree, expanding until solution found." << endl;

    sokobanMap.moveRight();
    cout << endl;
    sokobanMap.printMap();
    cout << endl;

    sokobanMap.moveRight();
    cout << endl;
    sokobanMap.printMap();
    cout << endl;

    sokobanMap.moveRight();
    cout << endl;
    sokobanMap.printMap();
    cout << endl;


//    for(int i = 0; i < 8 ; i++)
//    {
//        if (root->flag)
//        {
//            root = root->insert(root, 21, 0, sokobanMap, 0, NULL);
//            root = root->insert(root, 22, 0, sokobanMap, 0, NULL);
//            root = root->insert(root, 23, 0, sokobanMap, 0, NULL);
//            root = root->insert(root, 24, 0, sokobanMap, 0, NULL);
//        }
//        cout<< "i: " << i << endl;
//    }
    dummy.stopClock();
    cout << "End of program" << endl << endl;
    //root->printTree(root, 0);

    //Update legal move to check for two boxes next to each other
    /*
     * freepath = 1
     * goal = 2
     * box = 3
     * man = 4
     * wall = 5
     * goalman = 6
     * goalbox = 7
     *
     * */

    return 0;
}

