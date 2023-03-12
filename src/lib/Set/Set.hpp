#ifndef _SET_HPP_
#define _SET_HPP_

#include <bits/stdc++.h>

#include "../InventoryHolder/MainDeck/MainDeck.hpp"
#include "../InventoryHolder/TableDeck/TableDeck.hpp"
#include "../Valuable/Player/Player.hpp"

class Set {
    private:
        int points_;
        int round_;
        vector <Player> listOfPlayer_;
        MainDeck mainDeck_;
        TableDeck tableDeck_;

    public:
        Set(vector <Player> listOfPlayer);
        void startRound();
        void advanceRound();
        void askCommand(vector <string> allowedCommands);
        string inputCommand(vector <string> allowedCommands);

};

#endif