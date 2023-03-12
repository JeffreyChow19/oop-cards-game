#ifndef _ABILITY_HPP_
#define _ABILITY_HPP_

#include <bits/stdc++.h>
using namespace std;

class Ability {
    protected:
        bool status; 

    public:
        /**
         * @brief Construct a new Ability object
         * 
         */
        Ability();

        /**
         * @brief Activate Ability
         * 
         */
        virtual void activate() = 0;

        virtual string getAbilityName() = 0;


};

#endif