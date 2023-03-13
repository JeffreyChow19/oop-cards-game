#ifndef _TWO_PAIR_HPP_
#define _TWO_PAIR_HPP_

#include "../Combo.hpp"
#include "../Pair/Pair.hpp"
#include <bits/stdc++.h>
using namespace std;

class TwoPair:public Combo {
    private:
        Pair firstPair_;
        Pair secondPair_;
    public:
        TwoPair(Pair firstPair, Pair secondPair);
        ~TwoPair();
        float getValue();
};

#endif