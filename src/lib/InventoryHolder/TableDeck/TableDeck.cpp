#include "TableDeck.hpp"

TableDeck::TableDeck() {}

void TableDeck::addCard(MainDeck& _mainDeck)
{
    ColorCard toAdd = _mainDeck.getFromMainDeck();
    (*this) + toAdd;
}

TableDeck &TableDeck::operator=(const TableDeck &other)
{
    if (this != &other)
    {
        this->deck.clear();
        this->deck = other.deck;
    }
    return *this;
}