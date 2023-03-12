#ifndef _SET_HPP_
#define _SET_HPP_

#include <bits/stdc++.h>

#include "../InventoryHolder/MainDeck/MainDeck.hpp"
#include "../InventoryHolder/TableDeck/TableDeck.hpp"
#include "../Valuable/Player/Player.hpp"

class Set {
    private:
        int points;
        int round;
        vector <Player> listOfPlayer;
        MainDeck mainDeck;
        TableDeck tableDeck;

    public:
        Set(vector <Player> listOfPlayer);
        void startRound();
        void advanceRound();
        void askCommand();

};

#endif