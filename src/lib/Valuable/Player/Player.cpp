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

void Player::printCards(){
    for (auto &c : this->deck){
        c.printInfo();
    }
    ColorCard::printGroup(this->deck);
}

Combo *Player::checkPlayerCombo(TableDeck tableDeck)
{
    return nullptr;
}

Flush *Player::checkPlayerFlush(vector<ColorCard> cards)
{
    map<string, vector<ColorCard>> temp;
    for (auto &c : cards)
    {
        temp[c.getColor()].push_back(c);
        if (temp[c.getColor()].size() == 5)
        {
            return new Flush(temp[c.getColor()]);
        }
    }
    return nullptr;
}
