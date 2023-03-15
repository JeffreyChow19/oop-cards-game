#ifndef _PAIR_HPP_
#define _PAIR_HPP_

#include "../Combo.hpp"
#include <utility>
#include <algorithm>
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
        pair<ColorCard, ColorCard> getPair();
};

#endif
