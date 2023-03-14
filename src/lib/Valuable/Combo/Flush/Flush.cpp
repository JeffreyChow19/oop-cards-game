#include "Flush.hpp"

Flush::Flush(vector<ColorCard> cards)
{
    this->flushHand_ = cards;
    /* sort ascending by card value */
    sort(this->flushHand_.begin(), this->flushHand_.end(), ColorCard::compareByValue);
}

Flush::~Flush()
{
    this->flushHand_.clear();
}

float Flush::getValue()
{
    float result = 13.78; /* maximum straight value */

    for (int i = 0; i < this->flushHand_.size(); i++)
    {
        /* 0.01 * card value + max of previous index */
        result += 0.01 * this->flushHand_[i].getValue() + i * 0.13;
    }
    result += 0.001 * this->flushHand_[0].getBaseValue(); /* color tie breaker */

    return 0;
}


