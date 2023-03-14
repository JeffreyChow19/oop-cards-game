#include "Reverse.hpp"

void Reverse::activate(Set &set)
{
    vector<Player> &listOfPlayers = set.getListOfPlayers();
    vector<Player> temp;
    int currPlayerIdx = set.getCurrPlayerIdx();
    for (int i = currPlayerIdx+1; i<listOfPlayers.size(); i++) {
        temp.push_back(listOfPlayers[i]);
    }
    for(int i = 0; i < currPlayerIdx+1; i++) {
        temp.push_back(listOfPlayers[i]);
    }
    listOfPlayers = temp;
    reverse(listOfPlayers.begin(), listOfPlayers.end());
    set.setCurrPlayerIdx(0);
    set.setFirstPlayerIdx(0);
    cout << "Successfully reversed the players turns." << endl;
}

string Reverse::getCommandName()
{
    return "REVERSE";
}