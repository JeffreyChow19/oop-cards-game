#include "Half.hpp"

void Half::activate(Set &set)
{
    if (set.getPoints() == 1)
    {
        throw PointException();
    }
    set.setPoints(0.5);
    cout << "The point for this set is halfed!" << endl;
}

string Half::getCommandName()
{
    return "HALF";
}