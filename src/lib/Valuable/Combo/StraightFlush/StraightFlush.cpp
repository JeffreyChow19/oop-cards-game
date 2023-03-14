#include "StraightFlush.hpp"

StraightFlush::StraightFlush(vector<ColorCard> cards) 
{
    this->cards_ = cards;

    /* sort ascending by card value */
    sort(this->cards_.begin(), this->cards_.end(), ColorCard::compareByValue);
}

StraightFlush::~StraightFlush() 
{
    this->cards_.clear();
}

float StraightFlush::getValue() const
{
    float res = 11.03;   /* maximum four of a kind value */

    res += 0.05 * this->cards_[4].getBaseValue() + 0.2 *this->cards_[4].getValue();       /* highest card in the combination */
    
    return res;
}