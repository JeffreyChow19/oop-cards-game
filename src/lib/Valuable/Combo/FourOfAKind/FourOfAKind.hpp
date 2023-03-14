#ifndef _FOUR_OF_A_KIND_HPP_
#define _FOUR_OF_A_KIND_HPP_

#include "../Combo.hpp"

class FourOfAKind : public Combo {
    private:
        vector<ColorCard> quad_;
    public:
        FourOfAKind(ColorCard, ColorCard, ColorCard, ColorCard);
        virtual ~FourOfAKind();
        float getValue();
        void print();
};

#endif