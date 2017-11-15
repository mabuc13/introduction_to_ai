#include "sokabanloader.h"
//#include "../Graph/Graph.hpp"

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
                    //Going through all characters in the text file one at a time.
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

Graph* SokabanLoader::vectorToGraph()
{
    Graph* map = new Graph;
    vector<vector<Vertex*> > pointerMatrix(width, vector<Vertex*>(height));
    int center;
    /*int left;
    int right;
    int up;
    int down; */
    for (int y = 0; y < height; y++)
        for (int x = 0; x< width; x++)
        {
            if ( char2int(charMap[x][y]) < 6 ) //Going through all of the map
            {
                center = char2int(charMap[x][y]);
                //left = char2int(charMap[x-1][y]);
                //right = char2int(charMap[x+1][y]);
                //down = char2int(charMap[x][y+1]);
                //up = char2int(charMap[x][y-1]);
                //Creating the vertex
                Vertex* tmpVertex = new Vertex(center);
                map->addVertex(tmpVertex);
                pointerMatrix[x][y] = tmpVertex;
            }
        }

    for (int y = 1; y < height-1; y++)
        for (int x = 1; x< width-1; x++)
        {
            if (pointerMatrix[x-1][y] != 0) //Left edge
            {
                Edge* tmpEdge = new Edge(1,pointerMatrix[x][y]);
                pointerMatrix[x-1][y]->addEdge(tmpEdge);
            }
            if (pointerMatrix[x][y-1] != 0)
            {
                Edge* tmpEdge = new Edge(1,pointerMatrix[x][y]);
                pointerMatrix[x][y-1]->addEdge(tmpEdge);
            }
        }


return map;
}

int SokabanLoader::char2int(char oneChar)

{
    if (oneChar == '.')
        return 1;
    else if ( oneChar== 'J')
        return 4;
    else if ( oneChar == 'G')
        return 3;
    else if ( oneChar == 'M')
        return 5;

    return 255; //Not a part of our graph
}
