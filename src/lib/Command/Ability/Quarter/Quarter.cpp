#include "Quarter.hpp"

void Quarter::activate(Set &set)
{
    try
    {
        set.setPoints(0.25);
        cout << "The point for this set is quartered!" << endl;
    }
    catch (PointException &e)
    {
        cout << e.what();
    }
}

string Quarter::getCommandName()
{
    return "QUARTER";
}