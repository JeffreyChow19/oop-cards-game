#include "ThreeOfAKind.hpp"

ThreeOfAKind::ThreeOfAKind(ColorCard firstCard, ColorCard secondCard, ColorCard thirdCard)
{
    this->triple_.push_back(firstCard);
    this->triple_.push_back(secondCard);
    this->triple_.push_back(thirdCard);
}

ThreeOfAKind::~ThreeOfAKind()
{
    this->triple_.clear();
}

float ThreeOfAKind::getValue()
{
    /* Rumus : 0.2 * angka + 0.05 * color + 8.28 (tertinggi dari two pair) */
    return (
        0.2 * triple_[0].getValue() + 0.05 * max_element(triple_.begin(), triple_.end(), ColorCard::compareByColor)->getBaseValue() + 8.28);
}

void ThreeOfAKind::print()
{
    for (auto &c : this->triple_)
    {
        c.printInfo();
    }
}