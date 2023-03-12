#include "TableDeck.hpp"

TableDeck::TableDeck() {}

void TableDeck::addCard()
{
    // ColorCard toAdd = get
}

TableDeck &TableDeck::operator=(const TableDeck &other)
{
    if (this != &other)
    {
        this->deck.clear();
        this->deck = other.deck;
    }
    return *this;
};