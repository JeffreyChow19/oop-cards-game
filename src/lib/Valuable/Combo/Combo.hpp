#ifndef _COMBO_HPP_
#define _COMBO_HPP_

#include "../Valuable.hpp"
#include "../Card/ColorCard/ColorCard.hpp"
#include <bits/stdc++.h>
using namespace std;

class Combo:public Valuable {
    protected:
        static const float HIGH_CARD_MAX = 1.39;
        static const float PAIR_MAX = 4.14;
        static const float TWO_PAIR_MAX = 8.3;
        static const float THREE_KIND_MAX = 11;
        static const float STRAIGHT_MAX = 12.5;
        static const float FLUSH_MAX = 17.6;

        static const float FULL_HOUSE_MAX = 28.7;
        static const float FOUR_KIND_MAX = 31.3;
        static const float STRAIGHT_FLUSH_MAX = 34.05;
    public:
        Combo();
        virtual ~Combo();
        virtual float getValue() const=0;
};

#endif