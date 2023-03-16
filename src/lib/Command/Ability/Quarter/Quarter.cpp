#include "Quarter.hpp"

void Quarter::activate(Set &set)
{
    if (set.getPoints() ==1)
    {
        throw PointException();
    }else if(set.getPoints()==2){
        throw PointException2();
    }
    set.setPoints(0.25);
    cout << "The point for this set is quartered!" << endl;
}

string Quarter::getCommandName()
{
    return "QUARTER";
}