#include "FourOfAKind.hpp"

FourOfAKind::FourOfAKind(vector<ColorCard> cards)
{
    this->quad_ = cards;

    /* sort ascending by card value */
    sort(this->quad_.begin(), this->quad_.end(), ColorCard::compareByColor);
}
FourOfAKind::~FourOfAKind()
{
    this->quad_.clear();
}
float FourOfAKind::getValue()
{
    return 21.27 + 0.2 * this->quad_[0].getValue();
}

void FourOfAKind::print()
{
    for (auto &c : this->quad_)
    {
        c.printInfo();
    }
}