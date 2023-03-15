#include "Straight.hpp"
#include <bits/stdc++.h>
using namespace std;

Straight::Straight(vector<ColorCard> deck) {
    this->deck_ = deck;
    /* sort ascending by card value */
    sort(this->deck_.begin(), this->deck_.end(), ColorCard::compareByValue);
}

Straight::~Straight()
{
    this->deck_.clear();
}

float Straight::getValue() const
{
    /* result = encoding + max three of a kind*/
    float result = THREE_KIND_MAX;   /* maximum three of a kind value */

    /* encode maxValue and color sequence (descending) */
    /* V,VCCCCC*/
    float encoding = 0.1 * this->deck_[4].getValue();
    float multiplier = 0.000001;
    for (int i = 0; i < this->deck_.size(); i++)
    {
        encoding += multiplier * this->deck_[i].getBaseValue();
        multiplier *= 10;
    }

    result += encoding;

    return result;
}

void Straight::print()
{
    ColorCard::printGroup(this->deck_);
}

vector<ColorCard> &Straight::getDeck()
{
    return this->deck_;
}