#include "ThreeOfAKind.hpp"

ThreeOfAKind::ThreeOfAKind(){}

ThreeOfAKind::ThreeOfAKind(vector<ColorCard> cards) 
{
    this->triple_ = cards;

    /* sort ascending by color */
    sort(this->triple_.begin(), this->triple_.end(), ColorCard::compareByColor);
}

ThreeOfAKind::~ThreeOfAKind()
{
    this->triple_.clear();
}


void ThreeOfAKind::print()
{
    for (auto &c : this->triple_)
    {
        c.printInfo();
    }
}

float ThreeOfAKind::getValue() const 
{
    int angka = triple_[0].getValue();
    int maxColor = triple_[2].getBaseValue();

    /* Rumus : 0.2 * angka + 0.05 * maxColor + 8.3 (tertinggi dari two pair) + colorbits */
    float result = 0.2 * angka + 0.05 * maxColor + TWO_PAIR_MAX;

    float multiplier = 0.0001;
    for (int i = 0; i < this->triple_.size(); i++)
    {
        result += this->triple_[i].getBaseValue() * multiplier;
        multiplier *= 10;
    }
    
    return result;
}