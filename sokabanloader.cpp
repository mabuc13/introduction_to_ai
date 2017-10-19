#include "sokabanloader.h"

SokabanLoader::SokabanLoader()
{
    currentState = 0;
}

int SokabanLoader::loaderFSM(string location, bool forceState,int stateToForce)
{
    currentState = nextState;
    if (forceState)
        currentState = stateToForce;
    switch (currentState) {
    case 1: //Use this state to check for validation of the input string!
                if (!location.empty())
                    nextState = 2;
                    return currentState;
    case 2: //Use this state to load map
            loadMap(location);
               nextState = 3;
                return currentState;
    case 3: //Standby state
                nextState = currentState;
                return currentState;
        break;
    default:
        break;
    }
}

void SokabanLoader::loadMap(string location)
{
    string line; //The input we're iterating over
    cout << location.c_str() << endl;
    ifstream txtMap(location.c_str()); //CHANGE ASAP
    bool firstLine = true;
    int heightIterator = 0;
    if (txtMap.is_open())
    {
        while (getline (txtMap, line))
        {
            if (firstLine == true)
            {
                width = ((int)line[0]-48)*10 + (int)line[1]-48; //-48 is the offset between ascii table start index and ints start index
                cout << "line: " << line << endl;
                height = (int)(line[3]-48)*10 + (int)(line[4]-48);
                noDiamonds = (int)line[6]*10 +(int)line[7];
                firstLine = false;
                charMap = initMap(width, height);
                cout << "width: " << width << " height: " << height << endl;
            }
            else
            {
                for(int i = 0; i< line.size(); i++)
                {
                    charMap[i][heightIterator] = line[i];
                   // cout << line[i] << " ";
                }
                heightIterator++;
            }
        }
        txtMap.close();
        printMap();
    }
    else
        cout << "Could not open file..." << endl;
}


void SokabanLoader::printMap()
{
    for (int y = 0; y< height; y++ )
    {
        for (int x = 0; x< width; x++ )
        {
            cout << charMap[x][y] << " ";
        }
        cout << endl;
    }
}

vector<vector<char> > SokabanLoader::initMap(int width, int height)
//This functions sole purpose is to create an empty map, where we can load into
{
    vector<vector<char> > map(width, vector<char>(height)); //Credits to user Dukeling at: https://stackoverflow.com/questions/14959393/pointer-to-a-multidimensional-vector
    return map;
}
