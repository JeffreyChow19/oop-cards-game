#ifndef _COMBO_HPP_
#define _COMBO_HPP_

#include "../Valuable.hpp"
#include "../Card/ColorCard/ColorCard.hpp"
#include <bits/stdc++.h>
using namespace std;

class Combo:public Valuable {
    private:
        
    public:
        Combo();
        virtual ~Combo();
        virtual float getValue() const=0;
};

#endif