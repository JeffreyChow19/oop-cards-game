#include "Set.hpp"

using namespace std;

Set::Set(vector<Player> &listOfPlayer, int firstPlayerIdx) : listOfPlayer_(listOfPlayer)
{
    this->points_ = 64;
    this->round_ = 1;
    this->firstPlayerIdx_ = firstPlayerIdx;
    this->currPlayerIdx = firstPlayerIdx;

    MainDeck mainDeck;
    mainDeck.fillDeck();
    this->mainDeck_ = mainDeck;

    TableDeck tableDeck;
    this->tableDeck_ = tableDeck;

    for (int i = 0; i < listOfPlayer_.size(); i++)
    {
        ColorCard add1 = mainDeck_.getFromMainDeck();
        ColorCard add2 = mainDeck_.getFromMainDeck();
        listOfPlayer_[i].addPlayerCard(add1);
        listOfPlayer_[i].addPlayerCard(add2);
    }
}

Set::~Set()
{
    for (auto &p : listOfPlayer_)
    {
        p.clearDeck();
    }
}

long long Set::getPoints()
{
    return this->points_;
}

void Set::setPoints(float multiplier)
{
    this->points_ = this->points_ * multiplier;
}
void Set::printSetInfo()
{
    Coloring clr;
    cout << "Current point for this set is ";

    clr.white(true);
    cout << points_ << endl << endl;
    clr.reset();

    int ctr = 0;

    clr.white(true);
    cout << "Current turn: " << endl;
    clr.reset();
    
    while (ctr < listOfPlayer_.size())
    {
        cout << "[" << ctr + 1 << "] ";
        listOfPlayer_[((ctr + getCurrPlayerIdx()) % listOfPlayer_.size())].print();
        ctr++;
    }
}

vector<Player> &Set::getListOfPlayers()
{
    return this->listOfPlayer_;
}

int Set::getFirstPlayerIdx()
{
    return this->firstPlayerIdx_;
}

int Set::getCurrPlayerIdx()
{
    return this->currPlayerIdx;
}

MainDeck &Set::getMainDeck()
{
    return this->mainDeck_;
}

void Set::setMainDeck(MainDeck mainDeck)
{
    this->mainDeck_ = mainDeck;
}

void Set::setFirstPlayerIdx(int idx)
{
    this->firstPlayerIdx_ = idx;
};

void Set::setCurrPlayerIdx(int idx)
{
    this->currPlayerIdx = idx;
};
