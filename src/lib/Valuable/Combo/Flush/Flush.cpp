#include "Flush.hpp"

Flush::Flush(ColorCard firstCard, ColorCard secondCard, ColorCard thirdCard, ColorCard fourthCard, ColorCard fifthCard) 
{
    this->flushHand_.push_back(firstCard);
    this->flushHand_.push_back(secondCard);
    this->flushHand_.push_back(thirdCard);
    this->flushHand_.push_back(fourthCard);
    this->flushHand_.push_back(fifthCard);
}

Flush::~Flush() 
{
    this->flushHand_.clear();
}

float Flush::getValue() 
{
    /* Rumus : 0.2 * angka + 0.05 * color + 13,78 (tertinggi dari straight) */
    return (
        0.2 * max_element(flushHand_.begin(), flushHand_.end(), ColorCard::compareByValue)->getValue()
        + 0.05 * flushHand_[0].getBaseValue()
        + 13.78
    );
}
