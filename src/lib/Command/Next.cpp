#include "Next.hpp"

Next::Next(){}
void Next::activate(Set &set)
{
    cout << "Advancing to next player without doing anything..." << endl;
}

string Next::getCommandName()
{
    return "NEXT";
}