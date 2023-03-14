#ifndef _HIGH_CARD_HPP_
#define _HIGH_CARD_HPP_

#include "../Combo.hpp"
#include <bits/stdc++.h>
using namespace std;

class HighCard:public Combo {
    private:
        ColorCard card_;
    public:
        HighCard(ColorCard card);
        ~HighCard();
        float getValue();
        void print();
};

#endif