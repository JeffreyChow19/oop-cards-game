#include "Half.hpp"

void Half::activate(Set &set)
{
    set.setPoint(0.5);
}

string Half::getCommandName()
{
    return "HALF";
}