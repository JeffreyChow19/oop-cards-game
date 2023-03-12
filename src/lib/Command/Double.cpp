#include "Double.hpp"

void Double::activate(Set &set)
{
    set.setPoint(2);
}

string Double::getCommandName()
{
    return "DOUBLE";
}