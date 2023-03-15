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

void Set::setPoints(float multiplier)
{
    if (this->points_ == 1)
    {
        throw PointException();
    }
    this->points_ = this->points_ * multiplier;
}
void Set::printSetInfo()
{
    cout << "Current point for this set is " << points_ << endl;
    int ctr = 0;
    cout << "Current turn: " << endl;
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
