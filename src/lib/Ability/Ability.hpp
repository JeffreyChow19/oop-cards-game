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
         * @brief Copy Construct a new Ability object
         * 
         * @param other 
         */
        Ability(const Ability& other);

        /**
         * @brief Destroy the Ability object
         * 
         */
        ~Ability();

        /**
         * @brief Activate Ability
         * 
         */
        virtual void activate();
};

#endif