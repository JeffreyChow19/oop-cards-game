#ifndef _COMBO_HPP_
#define _COMBO_HPP_

#include "../Valuable.hpp"
#include <bits/stdc++.h>
using namespace std;

class Combo:public Valuable {
    private:
        
    public:
        Combo();
        virtual ~Combo();
        virtual float getValue()=0;
};

#endif