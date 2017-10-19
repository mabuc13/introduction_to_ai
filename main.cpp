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
    while (true)
    {

        int temp = test.loaderFSM("exampleMap.txt", 0, 0);
        cout << temp << endl;
        if (temp == 3)
            break;
    }
    //test.printMap();
    //test.initMap(10, 10);
    cout << "Hello World!" << endl;
    return 0;
}

