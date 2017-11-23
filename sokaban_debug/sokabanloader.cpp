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
        intMap = charToIntMap(charMap);
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
            cout << intMap[x][y] << " ";
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
    Vertex* current;
    Vertex* left;
    Vertex* right;
    Vertex* down;
    Vertex* up;
    /*int left;
    int right;
    int up;
    int down; */
    for (int y = 0; y < height; y++)
        for (int x = 0; x< width; x++)
        {
            if ( char2int(charMap[x][y]) < 6 ) //Going through all of the map making vertexes
            {
                center = char2int(charMap[x][y]);
                //left = char2int(charMap[x-1][y]);
                //right = char2int(charMap[x+1][y]);
                //down = char2int(charMap[x][y+1]);
                //up = char2int(charMap[x][y-1]);
                //Creating the vertex
                Vertex* tmpVertex = new Vertex(center, x, y);

                map->addVertex(tmpVertex);

            }
        }

    //Making edges
    for (int y = 0; y < height; y++)
        for (int x = 0; x< width; x++)
        {
            if ( char2int(charMap[x][y]) < 6 ) //Going through all of the map making vertexes
            {
                //Get current vertex
                current = map->xyFind(x, y);
                //If there's a valid location to the left, add an edge
                if ( char2int(charMap[x-1][y] < 6))
                {
                    left = map->xyFind(x-1, y);
                    map->addEdge(current, left, 1);
                }
                //Same for right
                if ( char2int(charMap[x+1][y] < 6))
                {
                    right = map->xyFind(x+1, y);
                    map->addEdge(current, right, 1);
                }
                //Same for down
                if ( char2int(charMap[x][y+1] < 6))
                {
                    down = map->xyFind(x, y+1);
                    map->addEdge(current, down, 1);
                }
                //And at last the same for up
                if ( char2int(charMap[x][y-1] < 6))
                {
                    up = map->xyFind(x, y);
                    map->addEdge(current, up, 1);
                }
            }
        }

return map;
}

int SokabanLoader::char2int(char oneChar)

{
    if (oneChar == '.')
        return 1;
    else if ( oneChar== 'J')
        return 3;
    else if ( oneChar == 'G')
        return 2;
    else if ( oneChar == 'M')
        return 4;
    else if ( oneChar == 'X')
        return 5;

    return 9; //Not a part of our graph
}

vector<vector<int> > SokabanLoader::getIntMap()
{
    return intMap;
}

vector<vector<int> > SokabanLoader::charToIntMap(vector<vector<char> > input)
{
    vector<vector<int> > tmpMap(width, vector<int>(height));
    for (int x = 0; x < width; x++)
        for (int y = 0; y < width; y++)
        {

            tmpMap[x][y] = char2int(input[x][y]);
            if (tmpMap[x][y] == 4)
            {
                xPos = x;
                yPos = y;
            }

        }

    return tmpMap;
}

int SokabanLoader::getHeight()
{
    return height;
}

int SokabanLoader::getWidth()
{
    return width;
}
