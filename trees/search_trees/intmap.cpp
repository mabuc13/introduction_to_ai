#include "intmap.h"

intMap::intMap()
{
}

intMap::intMap(vector<vector<int> > inputMap, int w, int h, int xPos, int yPos)
{
    map = inputMap;
    width = w;
    height = h;
    x = xPos;
    y = yPos;
    solved = false;
}

intMap::~intMap()
{

}

bool intMap::legalUp()
{
    //Check if there's a wall above
    if (map[x][y-1] == 5)
        return false;
    //Check if there's a box above AND that the box can move to next spot
    if (map[x][y-1] == 3)
    {
        if (map[x][y-2] == 5)
            return false;
    }
    return true;
}

bool intMap::legalRight()
{
    //Check if there's a wall to the right
    if (map[x+1][y] == 5)
        return false;
    //Check if there's a box to the right AND that the box can move to next spot
    if (map[x+1][y] == 3)
    {
        if (map[x+2][y] == 5)
            return false;
    }
    return true;
}

bool intMap::legalDown()
{
    //Check if there's a wall below
    if (map[x][y+1] == 5)
        return false;
    //Check if there's a box below AND that the box can move to next spot
    if (map[x][y+1] == 3)
    {
        if (map[x][y+2] == 5)
            return false;
    }
    return true;
}

bool intMap::legalLeft()
{
    //Check if there's a wall to the left
    if (map[x-1][y] == 5)
        return false;
    //Check if there's a box to the right AND that the box can move to next spot
    if (map[x-1][y] == 3)
    {
        if (map[x-2][y] == 5)
            return false;
    }
    return true;
}

void intMap::moveUp()
{
    //We know it's a legal move, so in all cases the current xy is free
    map[x][y] = 1;

    //If there's a box above, move it upwards
    if (map[x][y-1] == 3)
        map[x][y-2] = 3;

    //The new position of the man
    map[x][y-1] = 4;
    y = y-1;

    bool dummy = puzzleSolved();
    //return map;
}

void intMap::moveRight()
{
    //We know it's a legal move, so in all cases the current xy is free
    map[x][y] = 1;

    //If there's a box above, move it to the right
    if (map[x+1][y] == 3)
        map[x+2][y] = 3;

    //The new position of the man
    map[x+1][y] = 4;
    x = x +1;

    bool dummy = puzzleSolved();
    //return map;
}

void intMap::moveDown()
{
    //We know it's a legal move, so in all cases the current xy is free
    map[x][y] = 1;

    //If there's a box above, move it down
    if (map[x][y+1] == 3)
        map[x][y+2] = 3;

    //The new position of the man
    map[x][y+1] = 4;
    y = y+1;

    bool dummy = puzzleSolved();
    //return map;
}

void intMap::moveLeft()
{
    //We know it's a legal move, so in all cases the current xy is free
    map[x][y] = 1;

    //If there's a box above, move it to the left
    if (map[x-1][y] == 3)
        map[x-2][y] = 3;

    //The new position of the man
    map[x-1][y] = 4;
    x = x -1;
    bool dummy = puzzleSolved();
    //return map;
}

bool intMap::puzzleSolved()
{
    int goalCounter = 0;
    for (int x = 0; x < width; x++)
        for(int y = 0; y < height; y++)
        {
            if(map[x][y] == 2)
                goalCounter++;
        }
    if (goalCounter == 0)
    {
        solved = true;
        return true;
    }

    else
    {
        solved = false;
        return false;
    }
}

void intMap::printMap()
{
    for (int y = 0; y< height; y++ )
    {
        for (int x = 0; x< width; x++ )
        {
            cout << map[x][y] << " ";
        }
        cout << endl;
    }
}
