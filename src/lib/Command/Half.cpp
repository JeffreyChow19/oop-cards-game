#include "Half.hpp"

void Half::activate(Set &set)
{
    try
    {
        set.setPoints(0.5);
        cout << "The point for this set is halfed!" << endl;
    }
    catch (PointException &e)
    {
        cout << e.what();
    }
}

string Half::getCommandName()
{
    return "HALF";
}