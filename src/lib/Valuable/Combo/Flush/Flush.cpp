#include "Flush.hpp"

Flush::Flush(ColorCard firstCard, ColorCard secondCard, ColorCard thirdCard, ColorCard fourthCard, ColorCard fifthCard) 
{
    this->flushHand_.push_back(firstCard);
    this->flushHand_.push_back(secondCard);
    this->flushHand_.push_back(thirdCard);
    this->flushHand_.push_back(fourthCard);
    this->flushHand_.push_back(fifthCard);

    /* sort ascending by card value */
    sort(this->flushHand_.begin(), this->flushHand_.end(), ColorCard::compareByValue);
}

Flush::~Flush() 
{
    this->flushHand_.clear();
}

float Flush::getValue() 
{
    float result = 13.78;   /* maximum straight value */

    for (int i = 0; i < this->flushHand_.size(); i++)
    {
        /* 0.01 * card value + max of previous index */
        result += 0.01 * this->flushHand_[i].getValue() + i * 0.13;
    }
    result += 0.001 * this->flushHand_[0].getBaseValue();       /* color tie breaker */
    
    return 0;
}
