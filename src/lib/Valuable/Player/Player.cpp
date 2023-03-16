#include "Player.hpp"

using namespace std;

int Player::playerCount_ = 0;
Player::Player()
{
}
Player::Player(string nickname) : nickname_(nickname)
{
    playerCount_++;
    this->id_ = playerCount_;
}

Player::Player(const Player &other) : InventoryHolder(other)
{
    this->nickname_ = other.nickname_;
    this->deck = other.deck;
    playerCount_++;
    this->id_ = playerCount_;
}

Player::~Player()
{
    playerCount_--;
}

void Player::setNickname(string nickname)
{
    this->nickname_ = nickname;
}

string Player::getNickname() const
{
    return this->nickname_;
}

int Player::getPlayerCount()
{
    return playerCount_;
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

void Player::clearDeck()
{
    this->deck.clear();
}

float Player::getValue() const
{
    return 0.0;
}

void Player::printCards()
{
    ColorCard::printGroup(this->deck);
}
