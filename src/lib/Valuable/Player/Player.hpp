#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "../../InventoryHolder/InventoryHolder.hpp"
#include "../../InventoryHolder/MainDeck/MainDeck.hpp"
#include "../../InventoryHolder/TableDeck/TableDeck.hpp"
#include "../Card/ColorCard/ColorCard.hpp"
#include "../Valuable.hpp"
#include "../Combo/Flush/Flush.hpp"
#include "../Combo/FourOfAKind/FourOfAKind.hpp"
#include "../Combo/Straight/Straight.hpp"
#include "../Combo/FullHouse/FullHouse.hpp"
#include "../Combo/HighCard/HighCard.hpp"
#include "../Combo/Pair/Pair.hpp"
#include "../Combo/ThreeOfAKind/ThreeOfAKind.hpp"
#include "../Combo/TwoPair/TwoPair.hpp"
#include "../Combo/StraightFlush/StraightFlush.hpp"

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

class Player : public Valuable, public InventoryHolder<ColorCard>
{
protected:
    static int playerCount_;
    int id_;
    string nickname_;

public:
    Player();

    /**
     * @brief Construct a new Player object
     *
     * @param nickname
     */
    Player(string nickname);

    /**
     * @brief Copy a new Player object
     *
     * @param other
     */
    Player(const Player &other);

    /**
     * @brief Destroy the Player object
     *
     */
    virtual ~Player();

    /**
     * @brief Set the Nickname object
     *
     */
    void setNickname(string nickname);

    /**
     * @brief Get the player nickname
     *
     * @return string
     */
    string getNickname() const;

    /**
     * @brief Get the Player Count
     *
     * @return int
     */
    static int getPlayerCount();

    /**
     * @brief Clears player's deck
     *
     */
    void clearDeck();

    /**
     * @brief Returns player's value
     *
     * @return float
     */
    float getValue() const;

    /**
     * @brief Removes a card from player's deck
     *
     */
    void removePlayerCard(ColorCard);

    /**
     * @brief Adds a card to player's deck
     *
     */
    void addPlayerCard(ColorCard);

    /**
     * @brief Returns player's deck
     *
     * @return vector<ColorCard>
     */
    vector<ColorCard> getPlayerDeck();

    /**
     * @brief Set the Player's deck
     *
     */
    void setPlayerDeck(vector<ColorCard>);

    /**
     * @brief Print player's info including their nickname and points
     *
     */
    virtual void print() = 0;

    /**
     * @brief Prints player's cards
     *
     */
    void printCards();
};

#endif