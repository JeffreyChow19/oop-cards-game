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
    // random_device randDevice;
    // mt19937 numGen(randDevice());

    // random_shuffle(this->deck.begin(), this->deck.end(), numGen);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, deck.size() - 1);

    // Shuffle the card
    for (int i = 0; i < deck.size(); ++i) {
        swap(deck[i], deck[dis(gen)]);
    }
}

ColorCard MainDeck::getFromMainDeck()
{
    ColorCard toRemove = this->deck.back();
    (*this) - toRemove;
    return toRemove;
}


MainDeck& MainDeck::operator=(const MainDeck& other){
    this->deck.clear();
    for (auto c : other.deck){
        this->deck.push_back(c);
    }
    return *this;
}

void MainDeck::print() {
    for (int i = 0; i < this->deck.size(); i++) {
        this->deck[i].printInfo();
        cout << endl;
    }
}