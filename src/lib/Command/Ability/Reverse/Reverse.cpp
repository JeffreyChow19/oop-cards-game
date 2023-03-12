#include "Reverse.hpp"

void Reverse::activate(Set &set)
{
    vector<Player> &listOfPlayers = set.getListOfPlayers();
    reverse(listOfPlayers.begin(), listOfPlayers.end());
    cout << "Successfully reversed the players turns." << endl;
}

string Reverse::getCommandName()
{
    return "REVERSE";
}