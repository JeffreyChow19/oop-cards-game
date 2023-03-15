#include "TableDeck.hpp"

TableDeck::TableDeck()
{
}

TableDeck::TableDeck(vector<ColorCard> cards)
{
    this->deck = cards;
}

void TableDeck::addCard(MainDeck &_mainDeck)
{
    ColorCard toAdd = _mainDeck.getFromMainDeck();
    (*this) + toAdd;
}

void TableDeck::addCard(ColorCard toAdd)
{
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

void TableDeck::print()
{
    ColorCard::printGroup(this->deck);
}
