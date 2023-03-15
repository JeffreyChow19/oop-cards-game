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
private:
    static int playerCount_;
    int id_;
    string nickname_;
    long long point_;
    string ability_;
    bool hasPlayed_;
    bool abilityStatus_;
    bool abilityUse_;

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
    ~Player();

    /**
     * @brief Set the Nickname object
     *
     */
    void setNickname(string nickname);

    /**
     * @brief Set the Point object
     *
     */
    void setPoint(int point);

    /**
     * @brief add Player points_
     *
     * @param point
     */
    void addPoint(long long point);

    /**
     * @brief Get the player nickname
     *
     * @return string
     */
    string getNickname() const;

    /**
     * @brief Get the player object
     *
     * @return long long
     */
    long long getPoint() const;

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
     * @brief Set player's ability
     *
     */
    void setAbility(string);

    /**
     * @brief Returns player's ability
     *
     * @return string
     */
    string getAbility();

    /**
     * @brief Get the status of player's ability
     *
     * @return true
     * @return false
     */
    bool getAbilityStatus();

    /**
     * @brief Set the player's ability status
     *
     */
    void setAbilityStatus(bool);

    bool getAbilityUse();

    void setAbilityUse(bool);

    /**
     * @brief Set the player's hasPlayed
     *
     */
    void setHasPlayed(bool);

    /**
     * @brief Get the player's hasPlayed status
     *
     * @return true
     * @return false
     */
    bool getHasPlayed();

    /**
     * @brief Print player's info including their nickname and points
     *
     */
    void print();

    /**
     * @brief checks player's best combo
     *
     * @param tableDeck
     * @return Combo*
     */
    Combo *checkPlayerCombo(TableDeck &tableDeck);

    /**
     * @brief Checks if player can make Flush
     *
     * @param tableDeck
     * @return Flush*
     */
    Flush *checkPlayerFlush(TableDeck &tableDeck);

    /**
     * @brief Checks if player can make FourOfAKind combo
     *
     * @param tableDeck
     * @return FourOfAKind*
     */
    FourOfAKind *checkPlayerFourOfAKind(TableDeck &tableDeck);

    /**
     * @brief checks player's high card
     *
     * @return HighCard*
     */
    HighCard *checkPlayerHighCard();

    /**
     * @brief Checks if player can make a Pair combo
     *
     * @param tableDeck
     * @return Pair*
     */
    Pair *checkPlayerPair(TableDeck &tableDeck);

    /**
     * @brief Checks if player can make a Straight combo
     *
     * @param tableDeck
     * @return Straight*
     */
    Straight *checkPlayerStraight(TableDeck &tableDeck);

    /**
     * @brief Checks if player can make a Three Of A Kind combo
     *
     * @param tableDeck
     * @return ThreeOfAKind*
     */
    ThreeOfAKind *checkPlayerThreeOfAKind(TableDeck &tableDeck);

    /**
     * @brief Checks if player can make a Two Pair combo
     *
     * @param tableDeck
     * @return TwoPair*
     */
    TwoPair *checkPlayerTwoPair(TableDeck &tableDeck);

    /**
     * @brief Checks if player can make Full House
     *
     * @param tableDeck
     * @return FullHouse*
     */
    FullHouse *checkPlayerFullHouse(TableDeck &tableDeck);

    /**
     * @brief Checks if player can make a Straight Flush combo
     *
     * @param tableDeck
     * @return StraightFlush*
     */
    StraightFlush *checkPlayerStraightFlush(TableDeck &tableDeck);

    /**
     * @brief Prints player's cards
     *
     */
    void printCards();

    /**
     * @brief Delete the minimum card value from the combo
     *
     * @param combo
     * @param limit
     */
    void deleteMinValueFromCombo(vector<ColorCard> &combo, int limit);
    void deleteMinColorFromCombo(vector<ColorCard> &combo, int limit);
};

#endif