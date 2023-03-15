#ifndef _COMBO_HPP_
#define _COMBO_HPP_

#include "../Valuable.hpp"
#include "../Card/ColorCard/ColorCard.hpp"
#include <bits/stdc++.h>
using namespace std;

class Combo : public Valuable
{
protected:
    static const float HIGH_CARD_MAX;
    static const float PAIR_MAX;
    static const float TWO_PAIR_MAX;
    static const float THREE_KIND_MAX;
    static const float STRAIGHT_MAX;
    static const float FLUSH_MAX;

    /* chore: FULLHOUSE and above max */
    static const float FULL_HOUSE_MAX;
    static const float FOUR_KIND_MAX;
    static const float STRAIGHT_FLUSH_MAX;

public:
    Combo();
    virtual ~Combo();
    virtual float getValue() const = 0;
    virtual void print() = 0;
};

#endif