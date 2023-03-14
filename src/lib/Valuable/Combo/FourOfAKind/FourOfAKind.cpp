#include "FourOfAKind.hpp"

FourOfAKind::FourOfAKind(ColorCard firstCard, ColorCard secondCard, ColorCard thirdCard, ColorCard fourthCard) 
{
    this->quad_.push_back(firstCard);
    this->quad_.push_back(secondCard);
    this->quad_.push_back(thirdCard);
    this->quad_.push_back(fourthCard);

    /* sort ascending by card value */
    sort(this->quad_.begin(), this->quad_.end(), ColorCard::compareByColor);
}
FourOfAKind::~FourOfAKind() 
{
    this->quad_.clear();
}
float FourOfAKind::getValue() {
    return 21.27 + 0.2*this->quad_[0].getValue();
}

void FourOfAKind::print() {
    for (auto &c : this->quad_){
        c.printInfo();
    }
}