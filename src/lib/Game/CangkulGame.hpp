#ifndef _CANGKULGAME_HPP
#define _CANGKULGAME_HPP_

#include <iostream>
#include <unistd.h>
#include "../Valuable/Player/CangkulPlayer.hpp"
#include "../InventoryHolder/MainDeck/MainDeck.hpp"
#include "../Util/Coloring.hpp"

using namespace std;

class CangkulGame
{
private:
    vector<CangkulPlayer> listOfPlayers_;
    MainDeck mainDeck_;
    vector<ColorCard> thrownCards_;

public:
    CangkulGame();
    void startGame();
    int getCardChoice(CangkulPlayer &roundWinner);
    ColorCard *takeCardFromDeck(CangkulPlayer &p, ColorCard tableCard);
};

#endif