#include "Quadruple.hpp"

void Quadruple::activate(Set &set)
{
    try
    {
        set.setPoints(4);
        cout << "The point for this set is quadrupled!" << endl;
    }
    catch (PointException &e)
    {
        cout << e.what();
    }
}

string Quadruple::getCommandName()
{
    return "QUADRUPLE";
}