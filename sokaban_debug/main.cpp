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
    //freopen("solver_output1.txt","a",stdout);
    cout << "d-m-y_H:M:S " << oss.str() << endl;

    //UP
    //DOWN OR LEFT  OR

    //Få den moveup down etc til at returnere et char, stort når der er blevet skubbet

    //Repitations bevægelser skal laves om til 15'ere

    SokabanLoader loader;

    loader.loadMap("exampleMap.txt");

    intMap sokobanMap(loader.getIntMap(), loader.getWidth(), loader.getHeight(), loader.xPos, loader.yPos, loader.getGoals());
    tree dummy;
    tree * root = NULL;
    //dummy.startClock();

    //cout << "Legalleft?:" << sokobanMap.legalLeft() << endl;
//   for (int i = 0; i < 10; i++)
//   {
//       if (sokobanMap.legalDown())
//           sokobanMap.moveDown();
//       sokobanMap.printMap();
//       cout << endl;
//       cout << sokobanMap.deadMap << " << is map dead?" << endl;
//   }

    sokobanMap.printMap();
    cout << endl << "Map printed" << endl;
    root = root->insert(root, 20, 0, sokobanMap, 0, NULL, 0);
    cout << "Created root of tree, expanding until solution found." << endl;

    for(int i = 1; i <  20; i++)
    {
         if (root->flag)
         {

            root = root->insert(root, 21, 0, sokobanMap, 21, NULL, i); // 2 noder -- 15*2+ -- bekræfte med print tree
            //cout << "After insert 21" << endl;
            //root->printTree(root, 0);
            //cout << endl;

            root = root->insert(root, 22, 0, sokobanMap, 22, NULL, i); // 4 noder -- 30*2 +1
            //cout << "After insert 22" << endl;
            //root->printTree(root, 0);
            //cout << endl;

            root = root->insert(root, 23, 0, sokobanMap, 23, NULL, i);// 8 noder -- 60 *2 +1
            //cout << "After insert 23" << endl;
//            root->printTree(root, 0);
//            cout << endl;

            root = root->insert(root, 24, 0, sokobanMap, 24, NULL, i); // 16 noder -- 120* 2 +1
//            cout << "After insert 24" << endl;
//            root->printTree(root, 0);
//            cout << endl;

        //root->printTree(root,0);
        }
        cout<< "i: " << i << endl;
    }
    //dummy.stopClock();
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

