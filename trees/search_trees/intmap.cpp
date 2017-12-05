#include "intmap.h"

intMap::intMap()
{
}

intMap::intMap(vector<vector<int> > inputMap, int w, int h, int xPos, int yPos, int noGoals)
{
    map = inputMap;
    origMap = inputMap;
    freeGoals = noGoals;
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
        if (map[x][y-2] == 3)
            return false;
        if (map[x][y-2] == 7)
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
        if (map[x+2][y] == 3)
            return false;
        if (map[x+2][y] == 7)
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
        if (map[x][y+2] == 3)
            return false;
        if (map[x][y+2] == 7)
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
        if (map[x-2][y] == 3)
            return false;
        if (map[x-2][y] == 7)
            return false;
    }
    return true;
}

void intMap::moveUp()
{
    //We know it's a legal move, so in all cases the current xy is free
    if (map[x][y] == 6)
        map[x][y] = 2;
    else
        map[x][y] = 1;

    int temp = map[x][y-1];

    //If there's a box to the right, move it to the right
    if (map[x][y-1] == 3) // If there's a box, check behind the box
    {
        if (map[x][y-2] == 2){ // If there's a goal behind box, make goalbox
            map[x][y-2] = 7;
        }
        else
            map[x][y-2] = 3; // Else just box
    }

    else if (map[x][y-1] == 7) // If there's goalbox, check behind goalbox
    {
        if (map[x][y-2] == 2){ // If there's goal, make goalbox
            map[x][y-2] = 7;
        }
        else
            map[x][y-2] = 3; // Else just box
        map[x][y-1] = 6; // Move robot to goal
    }
    else if(map[x][y-1] == 2) // If goal
        map[x][y-1] = 6; // Make mangoal

    if (map[x][y-1] == temp)
        map[x][y-1] = 4;

    y = y - 1;

    bool dummy = puzzleSolved();

}


void intMap::moveRight()
{
    //We know it's a legal move, so in all cases the current xy is free
    if (map[x][y] == 6)
        map[x][y] = 2;
    else
        map[x][y] = 1;

    int temp = map[x+1][y];

    //If there's a box to the right, move it to the right
    if (map[x+1][y] == 3) // If there's a box, check behind the box
    {
        if (map[x+2][y] == 2){ // If there's a goal behind box, make goalbox
            map[x+2][y] = 7;
        }
        else
            map[x+2][y] = 3; // Else just box
    }

    else if (map[x+1][y] == 7) // If there's goalbox, check behind goalbox
    {
        if (map[x+2][y] == 2){ // If there's goal, make goalbox
            map[x+2][y] = 7;
        }
        else
            map[x+2][y] = 3; // Else just box
        map[x+1][y] = 6; // Move robot to goal
    }
    else if(map[x+1][y] == 2) // If goal
        map[x+1][y] = 6; // Make mangoal

    if (map[x+1][y] == temp)
        map[x+1][y] = 4;

    x = x +1;

    bool dummy = puzzleSolved();

}

void intMap::moveDown()
{
    //We know it's a legal move, so in all cases the current xy is free
    if (map[x][y] == 6)
        map[x][y] = 2;
    else
        map[x][y] = 1;

    int temp = map[x][y+1];

    //If there's a box to the right, move it to the right
    if (map[x][y+1] == 3) // If there's a box, check behind the box
    {
        if (map[x][y+2] == 2){ // If there's a goal behind box, make goalbox
            map[x][y+2] = 7;
        }
        else
            map[x][y+2] = 3; // Else just box
    }

    else if (map[x][y+1] == 7) // If there's goalbox, check behind goalbox
    {
        if (map[x][y+2] == 2){ // If there's goal, make goalbox
            map[x][y+2] = 7;
        }
        else
            map[x][y+2] = 3; // Else just box
        map[x][y+1] = 6; // Move robot to goal
    }
    else if(map[x][y+1] == 2) // If goal
        map[x][y+1] = 6; // Make mangoal

    if (map[x][y+1] == temp)
        map[x][y+1] = 4;

    y = y + 1;

    bool dummy = puzzleSolved();

}

void intMap::moveLeft()
{
    //We know it's a legal move, so in all cases the current xy is free
    if (map[x][y] == 6)
        map[x][y] = 2;
    else
        map[x][y] = 1;

    int temp = map[x-1][y];

    //If there's a box to the right, move it to the right
    if (map[x-1][y] == 3) // If there's a box, check behind the box
    {
        if (map[x-2][y] == 2){ // If there's a goal behind box, make goalbox
            map[x-2][y] = 7;
        }
        else
            map[x-2][y] = 3; // Else just box
    }

    else if (map[x-1][y] == 7) // If there's goalbox, check behind goalbox
    {
        if (map[x-2][y] == 2){ // If there's goal, make goalbox
            map[x-2][y] = 7;
        }
        else
            map[x-2][y] = 3; // Else just box
        map[x-1][y] = 6; // Move robot to goal
    }
    else if(map[x-1][y] == 2) // If goal
        map[x-1][y] = 6; // Make mangoal

    if (map[x-1][y] == temp)
        map[x-1][y] = 4;

    x = x - 1;

    bool dummy = puzzleSolved();
}

bool intMap::puzzleSolved()
{
    deadMap = goodMap();
    int goalCounter = freeGoals;
    //cout << "Goalcounter: " << goalCounter << endl;
    for (int x = 0; x < width; x++)
        for(int y = 0; y < height; y++)
        {
            if(origMap[x][y] == 2)
                if (map[x][y] == 7)
                    goalCounter--;
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

bool intMap::goodMap()
{

    for (int y = 0; y< height; y++ )
    {
        for (int x = 0; x< width; x++ )
        {
            if (map[x][y] == 3) //Box at current position
            {
                //Upper left corner
                if (map[x-1][y] == 5 && map[x][y-1] == 5)
                    return true;
                //Upper right corner
                if (map[x][y-1] == 5 && map[x+1][y] == 5)
                    return true;
                //Lower right corner
                if (map[x][y+1] == 5 && map[x+1][y] == 5)
                    return true;
                //Lower left corner
                if (map[x][y+1] == 5 && map[x-1][y] == 5)
                    return true;
            }
        }
    }
    return false;
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
