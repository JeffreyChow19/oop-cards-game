#include "StraightFlush.hpp"

StraightFlush::StraightFlush(ColorCard firstCard, ColorCard secondCard, ColorCard thirdCard, ColorCard fourthCard, ColorCard fifthCard) 
{
    this->sfHand_.push_back(firstCard);
    this->sfHand_.push_back(secondCard);
    this->sfHand_.push_back(thirdCard);
    this->sfHand_.push_back(fourthCard);
    this->sfHand_.push_back(fifthCard);

    /* sort ascending by card value */
    sort(this->sfHand_.begin(), this->sfHand_.end(), ColorCard::compareByValue);
}

StraightFlush::~StraightFlush() 
{
    this->sfHand_.clear();
}

float StraightFlush::getValue()
{
    float res = 11.03;   /* maximum four of a kind value */

    res += 0.05 * this->sfHand_[4].getBaseValue() + 0.2 *this->sfHand_[4].getValue();       /* highest card in the combination */
    
    return res;
}