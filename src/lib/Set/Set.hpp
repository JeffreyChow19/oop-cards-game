#ifndef _SET_HPP_
#define _SET_HPP_

#include <bits/stdc++.h>

#include "../InventoryHolder/MainDeck/MainDeck.hpp"
#include "../InventoryHolder/TableDeck/TableDeck.hpp"
#include "../Valuable/Player/Player.hpp"

class Set
{
private:
    int points_;
    int round_;
    int currPlayerIdx_;
    vector<Player> listOfPlayer_;
    MainDeck mainDeck_;
    TableDeck tableDeck_;

public:
    Set(vector<Player> &listOfPlayer, int currPlayerIdx);
    void startRound();
    void advanceRound();
    void askCommand(vector<string> allowedCommands);
    string inputCommand(vector<string> allowedCommands);
    void setPoint(float multiplier);
};

#endif