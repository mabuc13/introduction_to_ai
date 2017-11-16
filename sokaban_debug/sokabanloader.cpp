#include "sokobanloader.h"

SokobanLoader::SokobanLoader()
{
    currentState = 0;
}

int SokobanLoader::loaderFSM(string location, bool forceState,int stateToForce)
{
    currentState = nextState;
    if (forceState)
        currentState = stateToForce;
    switch (currentState) {
        case 1: //Use this state to check for validation of the input string!
            if (!location.empty())
                nextState = 2;
            return currentState;
            break;
        case 2: //Use this state to load map
            loadMap(location);
            nextState = 3;
            return currentState;
            break;
        case 3: //Standby state
            nextState = currentState;
            return currentState;
            break;
         default:
            break;
    }
}

void SokobanLoader::loadMap(string location)
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
                height = (int)(line[3]-48)*10 + (int)(line[4]-48);
                noDiamonds = (int)line[6]*10 +(int)line[7];
                firstLine = false;
                intMap = initMap(width, height);
                cout << "width: " << width << " height: " << height << endl;
            }
            else
            {
                for(int i = 0; i < line.size(); i++)
                {
                    switch(line[i]){
                        case '.': // Moveable Position
                            intMap[i][heightIterator] = 1;
                            break;
                        case 'G': // Goal Position
                            intMap[i][heightIterator] = 2;
                            break;
                        case 'J': // Diamond Position
                            intMap[i][heightIterator] = 3;
                            break;
                        case 'M': // Robot Position
                            intMap[i][heightIterator] = 4;
                            break;
                        case 'X': // Walls
                            intMap[i][heightIterator] = 5;
                            break;
                        default: // Undefined area of map
                            intMap[i][heightIterator] = 5;
                            break;
                    }
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


void SokobanLoader::printMap()
{
    for (int y = 0; y < height; y++ )
    {
        for (int x = 0; x < width; x++ )
        {
            cout << intMap[x][y] << " ";
        }
        cout << " Row " << y << endl;
    }
    cout << "Map has been printed." << endl;
}

vector<vector<int>> SokobanLoader::initMap(int width, int height)
//This functions sole purpose is to create an empty map, where we can load into
{
    vector<vector<int>>map(width, vector<int>(height)); //Credits to user Dukeling at: https://stackoverflow.com/questions/14959393/pointer-to-a-multidimensional-vector
    return map;
}

void SokobanLoader::generateTree(vector<vector<int>> map)
{

    for (int y = 0; y < height; y++ )
    {
        for (int x = 0; x < width; x++ )
        {
            if(map[x][y] == 4){ // Robot position will be root.
                // Create tree
                // ExpandTree(map, x, y) - Find children and populate tree, recursive function

            }
        }

    }
}

void SokobanLoader::expandTree(vector<vector<int>> map, int x, int y) // Function should be recursive
{
// X Component
    if(x == 0){
        if(map[x+1][y] <= 4){ // Point to the right
            // Add child to node
            // Run ExpandTree(map, x, y);
        }

    }

    if(x == width-1){
        if(map[x-1][y] <= 4){ // Point to the left
            // Add child to node
            // Run ExpandTree(map, x, y);
        }

    }

    else {
        if(map[x+1][y] <= 4){ // Point to the right
            // Add child to node
            // Run ExpandTree(map, x, y);
        }

        if(map[x-1][y] <= 4){ // Point to the left
            // Add child to node
            // Run ExpandTree(map, x, y);
        }

    }

// Y Component
    if(y == 0){
        if(map[x][y+1] <= 4){ // Point below
            // Add child to node
            // Run ExpandTree(map, x, y);
        }

    }

    if(y == height-1){
        if(map[x-1][y-1] <= 4){ // Point above
            // Add child to node
            // Run ExpandTree(map, x, y);
        }

    }

    else {
        if(map[x][y+1] <= 4){ // Point below
            // Add child to node
            // Run ExpandTree(map, x, y);
        }

        if(map[x][y-1] <= 4){ // Point above
            // Add child to node
            // Run ExpandTree(map, x, y);
        }

    }
}
