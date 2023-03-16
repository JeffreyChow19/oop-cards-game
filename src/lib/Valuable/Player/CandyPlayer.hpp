#ifndef _CANDYPLAYER_HPP_
#define _CANDYPLAYER_HPP_

#include "Player.hpp"

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

class CandyPlayer : public Player
{
private:
    long long point_;
    string ability_;
    bool hasPlayed_;
    bool abilityStatus_;
    bool abilityUse_;

public:
    CandyPlayer();

    /**
     * @brief Construct a new CandyPlayer object
     *
     * @param nickname
     */
    CandyPlayer(string nickname);

    /**
     * @brief Copy a new CandyPlayer object
     *
     * @param other
     */
    CandyPlayer(const CandyPlayer &other);

    /**
     * @brief Destroy the CandyPlayer object
     *
     */
    ~CandyPlayer();

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
     * @brief Get the player object
     *
     * @return long long
     */
    long long getPoint() const;

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
     * @brief Get the status of player's ability
     *
     * @return true
     * @return false
     */
    void setAbilityStatus(bool);

    void setHasPlayed(bool hasPlayed);

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
     * @brief Delete the minimum card value from the combo
     *
     * @param combo
     * @param limit
     */
    void deleteMinValueFromCombo(vector<ColorCard> &combo, int limit);
    void deleteMinColorFromCombo(vector<ColorCard> &combo, int limit);
    bool getAbilityUse();

    void setAbilityUse(bool);
};

#endif