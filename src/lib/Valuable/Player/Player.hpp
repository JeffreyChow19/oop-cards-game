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
    void addPoint(int point);

    /**
     * @brief Get the player nickname
     *
     * @return string
     */
    string getNickname() const;

    /**
     * @brief Get the player object
     *
     * @return int
     */
    int getPoint() const;

    /**
     * @brief Get the Player Count
     *
     * @return int
     */
    static int getPlayerCount();

    void clearDeck();
    
    float getValue() const;

    void removePlayerCard(ColorCard);

    void addPlayerCard(ColorCard);

    vector<ColorCard> getPlayerDeck();

    void setPlayerDeck(vector<ColorCard>);

    void setAbility(string);

    string getAbility();

    bool getAbilityStatus();

    void setAbilityStatus(bool);

    void setHasPlayed(bool);

    bool getHasPlayed();

    void print();

    Combo *checkPlayerCombo(TableDeck &tableDeck);

    Flush *checkPlayerFlush(TableDeck &tableDeck);

    FourOfAKind *checkPlayerFourOfAKind(TableDeck &tableDeck);

    HighCard *checkPlayerHighCard();

    Pair *checkPlayerPair(TableDeck &tableDeck);

    Straight *checkPlayerStraight(TableDeck &tableDeck);

    ThreeOfAKind *checkPlayerThreeOfAKind(TableDeck &tableDeck);

    TwoPair *checkPlayerTwoPair(TableDeck &tableDeck);

    FullHouse *checkPlayerFullHouse(TableDeck &tableDeck);

    StraightFlush *checkPlayerStraightFlush(TableDeck &tableDeck);

    void printCards();

    void deleteMinValueFromCombo(vector<ColorCard> &combo, int limit);
    void deleteMinColorFromCombo(vector<ColorCard> &combo, int limit);
};

#endif