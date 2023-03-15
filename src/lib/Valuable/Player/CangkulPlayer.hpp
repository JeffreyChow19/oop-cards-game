#ifndef _CANGKULPLAYER_HPP_
#define _CANGKULPLAYER_HPP_

#include "Player.hpp"

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

class CangkulPlayer : public Player
{
private:
public:
    CangkulPlayer();

    /**
     * @brief Construct a new Player object
     *
     * @param nickname
     */
    CangkulPlayer(string nickname);

    /**
     * @brief Destroy the Player object
     *
     */
    ~CangkulPlayer();

    /**
     * @brief Print player's info including their nickname and points
     *
     */
    void print();

    ColorCard* getLargestCard(ColorCard &tableCard);

    int getCardChoice(int n);

    void takeCardFromDeck(MainDeck &mainDeck, ColorCard tableCard);
};

#endif