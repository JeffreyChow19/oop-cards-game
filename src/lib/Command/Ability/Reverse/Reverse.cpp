#include "Reverse.hpp"

void Reverse::activate(Set &set)
{
    vector<Player> &listOfPlayers = set.getListOfPlayers();
    reverse(listOfPlayers.begin(), listOfPlayers.end());
    set.setCurrPlayerIdx(listOfPlayers.size() - 1 - set.getCurrPlayerIdx());
    set.setFirstPlayerIdx(listOfPlayers.size() - 1 - set.getFirstPlayerIdx());
    cout << "Successfully reversed the players turns." << endl;
}

string Reverse::getCommandName()
{
    return "REVERSE";
}