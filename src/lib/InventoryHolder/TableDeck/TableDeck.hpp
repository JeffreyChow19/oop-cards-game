#ifndef _TABLE_DECK_HPP_
#define _TABLE_DECK_HPP_

#include "../InventoryHolder.hpp"
#include "../MainDeck/MainDeck.hpp"
#include "../../Valuable/Card/ColorCard/ColorCard.hpp"
using namespace std;

class TableDeck : public InventoryHolder<ColorCard>
{
private:
public:
    /**
     * @brief Construct a new Table Deck object
     *
     */
    TableDeck();
    TableDeck(vector<ColorCard> cards);
    void addCard(MainDeck &);
    void addCard(ColorCard);
    virtual TableDeck &operator=(const TableDeck &other);
    void print();
};

#endif