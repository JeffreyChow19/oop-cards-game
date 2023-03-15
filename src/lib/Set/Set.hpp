#ifndef _SET_HPP_
#define _SET_HPP_

#include <vector>
#include "../InventoryHolder/MainDeck/MainDeck.hpp"
#include "../InventoryHolder/TableDeck/TableDeck.hpp"
#include "../Valuable/Player/Player.hpp"
#include "../Exception/Exception.hpp"

class Set
{
protected:
    long long points_;
    int round_;
    int firstPlayerIdx_;
    int currPlayerIdx;
    vector<Player> &listOfPlayer_;
    MainDeck mainDeck_;
    TableDeck tableDeck_;

public:
    /**
     * @brief Construct a new Set object
     *
     * @param listOfPlayer
     * @param currPlayerIdx
     */
    Set(vector<Player> &listOfPlayer, int currPlayerIdx);
    /**
     * @brief Set the points of Set to this->points_ * multiplier
     *
     * @param multiplier
     */
    void setPoints(float multiplier);
    /**
     * @brief Destroy the Set object
     *
     */
    virtual ~Set();
    /**
     * @brief print the current point in the set
     *
     */
    void printSetInfo();
    /**
     * @brief Get the set's listOfPlayer_
     *
     * @return vector<Player>&
     */
    vector<Player> &getListOfPlayers();

    /**
     * @brief Get the index of the first player for the set
     *
     * @return int
     */
    int getFirstPlayerIdx();

    int getCurrPlayerIdx();

    MainDeck &getMainDeck();

    long long getPoints();

    void setMainDeck(MainDeck);

    void setFirstPlayerIdx(int);
    void setCurrPlayerIdx(int);
};

#endif