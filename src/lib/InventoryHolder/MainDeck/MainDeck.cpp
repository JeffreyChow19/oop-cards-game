#include "MainDeck.hpp"

MainDeck::MainDeck()
{
    for (int i = 0; i < static_cast<int>(Color::Last); ++i)
    {
        Color c = static_cast<Color>(i);
        for (int j = 1; j < 14; j++)
        {
            ColorCard cardObj(c, j);
            // this->deck.push_back(make_shared<Card>(cardObj));
            this->deck.push_back(cardObj);
        }
    }
}

void MainDeck::randomizeCard()
{
    random_device randDevice;
    mt19937 numGen(randDevice());

    random_shuffle(this->deck.begin(), this->deck.end(), numGen);
}

ColorCard MainDeck::getFromMainDeck()
{
    ColorCard toRemove = this->deck.back();
    (*this) - toRemove;
    return toRemove;
}