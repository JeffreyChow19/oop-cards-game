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
    float res = 11.03;   /* maximum three of a kind value */

    res += 0.05 * this->deck_[4].getBaseValue() + 0.2 *this->deck_[4].getValue();       /* highest card in the combination */
    
    return res;
}