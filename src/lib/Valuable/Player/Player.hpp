#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <bits/stdc++.h>
#include "../../Ability/Ability.hpp"
#include "../../InventoryHolder/InventoryHolder.hpp"
#include "../Card/ColorCard/ColorCard.hpp"

using namespace std;

class Player : public InventoryHolder<ColorCard>
{
private:
    static int playerCount_;
    int id_;
    string nickname_;
    int point_;
    Ability ability_;

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
     * @brief add Player points
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
};

#endif