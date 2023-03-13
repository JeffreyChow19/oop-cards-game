#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <bits/stdc++.h>
#include "../../InventoryHolder/InventoryHolder.hpp"
#include "../../InventoryHolder/MainDeck/MainDeck.hpp"
#include "../Card/ColorCard/ColorCard.hpp"
#include "../Valuable.hpp"

using namespace std;

class Player : public Valuable, public InventoryHolder<ColorCard>
{
private:
    static int playerCount_;
    int id_;
    string nickname_;
    int point_;
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

    float getValue();

    void removePlayerCard(ColorCard);

    void addPlayerCard(ColorCard);
    
    vector<ColorCard> getPlayerDeck() const;

    void setPlayerDeck(vector<ColorCard>);

    void setAbility(string);

    string getAbility();

    void setAbilityStatus(bool);

    void setHasPlayed(bool);

    bool getHasPlayed();
};

#endif