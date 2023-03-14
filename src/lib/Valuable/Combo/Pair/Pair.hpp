#ifndef _PAIR_HPP_
#define _PAIR_HPP_

#include "../Combo.hpp"
#include <bits/stdc++.h>
using namespace std;

class Pair : public Combo
{
private:
        pair<ColorCard, ColorCard> cardPair_;

public:
        Pair();
        Pair(pair<ColorCard, ColorCard> cardPair);
        ~Pair();
        float getValue() const;
        void print();
};

#endif
