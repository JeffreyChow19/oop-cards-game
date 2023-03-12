#include "Double.hpp"

void Double::activate(Set &set)
{
    try
    {
        set.setPoints(2);
        cout << "The point for this set is doubled!" << endl;
    }
    catch (PointException &e)
    {
        cout << e.what();
    }
}

string Double::getCommandName()
{
    return "DOUBLE";
}