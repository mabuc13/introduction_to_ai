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

    tree dummy;
    tree * root = NULL;

    cout << "Initialized root of tree" << endl;
    intMap testMap(test.getIntMap(), test.getWidth(), test.getHeight(), test.xPos, test.yPos);
    cout << "Do we get to the tree part?" << endl;

    cout << "Did we init the tree??" << endl;
//    root = root->insert(root, 21, 0, test.getIntMap());
//    root = root->insert(root, 22, 0, test.getIntMap());
//    root = root->insert(root, 23, 0, test.getIntMap());
//    root = root->insert(root, 24, 0, test.getIntMap());

//    root = root->insert(root, 21, 0, test.getIntMap());
//    root = root->insert(root, 22, 0, test.getIntMap());
//    root = root->insert(root, 23, 0, test.getIntMap());
//    root = root->insert(root, 24, 0, test.getIntMap());

//    root = root->insert(root, 21, 0, test.getIntMap());
//    root = root->insert(root, 22, 0, test.getIntMap());
//    root = root->insert(root, 23, 0, test.getIntMap());
//    root = root->insert(root, 24, 0, test.getIntMap());

//    root = root->insert(root, 21, 0, test.getIntMap());
//    root = root->insert(root, 22, 0, test.getIntMap());
//    root = root->insert(root, 23, 0, test.getIntMap());
//    root = root->insert(root, 24, 0, test.getIntMap());





   // Testing on the map
    //intMap testMap(test.getIntMap(), test.getWidth(), test.getHeight(), test.xPos, test.yPos);
    cout << "Do we get to the while loop?" << endl;
//    while (!(testMap.puzzleSolved()))
//    {
//        tmpMap = testMap.moveRight();
//        root = root->insert(root, 22, 0, testMap);
//        testMap.printMap();
//        cout << " ... working ..." << endl;
//    }
    root = root->insert(root, 20, 0, testMap, 0);
    for(int i = 0; i < 5; i++)
    {
        root = root->insert(root, 22, 0, testMap, 0);
        root = root->insert(root, 22, 0, testMap, 0);
        root = root->insert(root, 23, 0, testMap, 0);
        root = root->insert(root, 24, 0, testMap, 0);

    }
    cout << "End of program" << endl;
    //root->printTree(root, 0);

    return 0;
}

