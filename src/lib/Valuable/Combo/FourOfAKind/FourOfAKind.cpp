#include "FourOfAKind.hpp"

FourOfAKind::FourOfAKind(vector<ColorCard> cards) 
{
    this->quad_ = cards;

    /* sort ascending by card color */
    sort(this->quad_.begin(), this->quad_.end(), ColorCard::compareByColor);
}

FourOfAKind::~FourOfAKind() 
{
    this->quad_.clear();
}

float FourOfAKind::getValue() const
{
    /* (maximum of fullHouse) + quad combination value */
    float result = FULL_HOUSE_MAX + 0.2 * this->quad_[0].getValue();
    return result;
}

void FourOfAKind::print()
{
    ColorCard::printGroup(quad_);
}