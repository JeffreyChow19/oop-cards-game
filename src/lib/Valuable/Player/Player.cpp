#include <bits/stdc++.h>
#include "Player.hpp"

using namespace std;

int Player::playerCount_ = 0;
Player::Player(string nickname) : nickname_(nickname), hasPlayed_(false), abilityStatus_(false)
{
    this->point_ = 0;
    playerCount_++;
    this->id_ = playerCount_;
    // To do: adding deck & ability
}

Player::Player(const Player &other)
{
    this->nickname_ = other.nickname_;
    this->point_ = other.point_;
    this->hasPlayed_ = other.hasPlayed_;
    this->ability_ = other.ability_;
    this->abilityStatus_ = other.abilityStatus_;
    playerCount_++;
    this->id_ = playerCount_;
    // To do: adding deck & ability
}

Player::~Player()
{
    playerCount_--;
}

void Player::setNickname(string nickname)
{
    this->nickname_ = nickname;
}

void Player::setPoint(int point)
{
    this->point_ = point;
}

void Player::addPoint(int pointVal)
{
    this->point_ += pointVal;
}

string Player::getNickname() const
{
    return this->nickname_;
}

int Player::getPoint() const
{
    return this->point_;
}

int Player::getPlayerCount()
{
    return playerCount_;
}

string Player::getAbility()
{
    return ability_;
}

void Player::removePlayerCard(ColorCard toRemove)
{
    (*this) - toRemove;
}

void Player::addPlayerCard(ColorCard toAdd)
{
    (*this) + toAdd;
}

vector<ColorCard> Player::getPlayerDeck()
{
    return this->deck;
}

void Player::setPlayerDeck(vector<ColorCard> playerDeck)
{
    this->deck = playerDeck;
}

float Player::getValue()
{
    return 0.0;
}

void Player::setAbility(string ability)
{
    this->ability_ = ability;
}

bool Player::getAbilityStatus()
{
    return this->abilityStatus_;
}

void Player::setAbilityStatus(bool status)
{
    this->abilityStatus_ = status;
}

void Player::setHasPlayed(bool hasPlayed)
{
    this->hasPlayed_ = hasPlayed;
}

bool Player::getHasPlayed()
{
    return this->hasPlayed_;
}

void Player::print()
{
    cout << nickname_ << endl;
    cout << "  Points: " << point_ << endl;
}

void Player::printCards()
{
    for (auto &c : this->deck)
    {
        c.printInfo();
    }
    ColorCard::printGroup(this->deck);
}

void Player::deleteMinValueFromCombo(vector<ColorCard> &combo, int limit)
{
    if (combo.size() == limit)
    {
        auto minVal = min_element(combo.begin(), combo.end(), Card::compareByValue);
        if (minVal != combo.end())
        {
            combo.erase(minVal);
        }
    }
}

void Player::deleteMinColorFromCombo(vector<ColorCard> &combo, int limit)
{
    if (combo.size() == limit)
    {
        auto minVal = min_element(combo.begin(), combo.end(), ColorCard::compareByColor);
        if (minVal != combo.end())
        {
            combo.erase(minVal);
        }
    }
}

Combo *Player::checkPlayerCombo(TableDeck tableDeck)
{
    return nullptr;
}

Flush *Player::checkPlayerFlush(TableDeck tableDeck)
{
    map<string, vector<ColorCard>> temp;
    // count the freq of each color in the table deck
    for (auto &c : tableDeck.getDeck())
    {
        temp[c.getColor()].push_back(c);
    }
    ColorCard firstCard = this->deck[0];
    deleteMinValueFromCombo(temp[firstCard.getColor()], 5);
    temp[firstCard.getColor()].push_back(firstCard);

    ColorCard secondCard = this->deck[1];
    if (secondCard.getColor() == firstCard.getColor())
    {
        if (secondCard.getValue() > min_element(temp[secondCard.getColor()].begin(), temp[secondCard.getColor()].end(), Card::compareByValue)->getValue() || temp[secondCard.getColor()].size() < 5)
        {
            deleteMinValueFromCombo(temp[secondCard.getColor()], 5);
            temp[secondCard.getColor()].push_back(secondCard);
        }
    }
    else
    {
        deleteMinValueFromCombo(temp[secondCard.getColor()], 5);
        temp[secondCard.getColor()].push_back(secondCard);
    }

    if (temp[firstCard.getColor()].size() == 5)
    {
        return new Flush(temp[firstCard.getColor()]);
    }

    if (temp[secondCard.getColor()].size() == 5)
    {
        return new Flush(temp[secondCard.getColor()]);
    }

    return nullptr;
}

FourOfAKind *Player::checkPlayerFourOfAKind(TableDeck tableDeck)
{
    map<int, vector<ColorCard>> temp;
    // count the freq of each color in the table deck
    for (auto &c : tableDeck.getDeck())
    {
        deleteMinColorFromCombo(temp[c.getValue()], 4);
        temp[c.getValue()].push_back(c);
    }

    ColorCard firstCard = this->deck[0];
    deleteMinColorFromCombo(temp[firstCard.getValue()], 4);
    temp[firstCard.getValue()].push_back(firstCard);

    ColorCard secondCard = this->deck[1];
    if (temp[secondCard.getValue()].size() == 4)
    {
        auto minVal = min_element(temp[secondCard.getValue()].begin(), temp[secondCard.getValue()].end(), ColorCard::compareByColor);
        if (minVal != temp[secondCard.getValue()].end())
        {
            temp[secondCard.getValue()].erase(minVal);
        }
    }
    temp[secondCard.getValue()].push_back(secondCard);

    if (temp[firstCard.getValue()].size() == 4)
    {
        return new FourOfAKind(temp[firstCard.getValue()]);
    }

    if (temp[secondCard.getValue()].size() == 4)
    {
        return new FourOfAKind(temp[secondCard.getValue()]);
    }

    return nullptr;
};

HighCard *Player::checkPlayerHighCard()
{
    HighCard *hc1 = new HighCard(this->deck[0]);
    HighCard *hc2 = new HighCard(this->deck[0]);
    if (hc1->getValue() > hc2->getValue())
    {
        delete hc2;
        return hc1;
    }
    delete hc1;
    return hc2;
};

Pair *Player::checkPlayerPair(TableDeck tableDeck){
    // sort ascending
    sort(this->deck.begin(), this->deck.end(), ColorCard::compareByValueThenColor);
    sort(tableDeck.getDeck().begin(), tableDeck.getDeck().end(), ColorCard::compareByValueThenColor);

    // check inner deck first
    bool playerPair = false;

    if (this->deck[0].getValue() == this->deck[1].getValue()){
        playerPair = true;
    }

    // loop through each card in deck
    for (auto c = this->deck.rbegin(); c != this->deck.rend(); ++c){
        // check if c have pair in tableDeck
        for (auto d = tableDeck.getDeck().rbegin(); d != tableDeck.getDeck().rend(); ++d){
            // if there is pair, return pair
            if (c->getValue() == d->getValue()){
                pair<ColorCard,ColorCard> cardPair;      

                // check if inner deck is pair and inner deck pair is greater than this pair         
                if (playerPair && !ColorCard::compareByColor(this->deck[0], *d)){
                    cardPair.first = this->deck[0];
                    cardPair.second = this->deck[1];
                } else {
                    // return this pair           
                    cardPair.first = *c;
                    cardPair.second = *d;
                }

                return new Pair(cardPair);
            }
        }
    }  
    return nullptr; 
};

Straight *Player::checkPlayerStraight(TableDeck tableDeck){

};

// StraightFlush* checkPlayerStraightFlush();

ThreeOfAKind *Player::checkPlayerThreeOfAKind(TableDeck tableDeck)
{
    map<int, vector<ColorCard>> temp;
    // count the freq of each color in the table deck
    for (auto &c : tableDeck.getDeck())
    {
        deleteMinColorFromCombo(temp[c.getValue()], 3);
        temp[c.getValue()].push_back(c);
    }

    ColorCard firstCard = this->deck[0];
    deleteMinColorFromCombo(temp[firstCard.getValue()], 3);
    temp[firstCard.getValue()].push_back(firstCard);

    ColorCard secondCard = this->deck[1];
    if (temp[secondCard.getValue()].size() == 3)
    {
        auto minVal = min_element(temp[secondCard.getValue()].begin(), temp[secondCard.getValue()].end(), ColorCard::compareByColor);
        if (minVal != temp[secondCard.getValue()].end())
        {
            temp[secondCard.getValue()].erase(minVal);
        }
    }
    temp[secondCard.getValue()].push_back(secondCard);

    if (temp[firstCard.getValue()].size() == 3)
    {
        return new ThreeOfAKind(temp[firstCard.getValue()]);
    }

    if (temp[secondCard.getValue()].size() == 3)
    {
        return new ThreeOfAKind(temp[secondCard.getValue()]);
    }

    return nullptr;
};

TwoPair *Player::checkPlayerTwoPair(TableDeck tableDeck){

};
