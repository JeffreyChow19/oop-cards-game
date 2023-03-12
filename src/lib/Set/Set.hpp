#ifndef _SET_HPP_
#define _SET_HPP_

#include <bits/stdc++.h>

#include "../InventoryHolder/MainDeck/MainDeck.hpp"
#include "../InventoryHolder/TableDeck/TableDeck.hpp"
#include "../Valuable/Player/Player.hpp"
#include "../Exception/Exception.hpp"

class Set
{
protected:
    int points_;
    int round_;
    int currPlayerIdx_;
    vector<Player> listOfPlayer_;
    MainDeck mainDeck_;
    TableDeck tableDeck_;

public:
    Set();
    Set(vector<Player> &listOfPlayer, int currPlayerIdx);
};

#endif