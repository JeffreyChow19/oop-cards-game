#ifndef _FULLHOUSE_HPP_
#define _FULLHOUSE_HPP_

#include "../Combo.hpp"


class FullHouse:public Combo {
    private:
        vector<ColorCard> deck_; 
    public:
        /**
         * @brief Construct a new FullHouse object
         * 
         * @param firstCard 
         * @param secondCard 
         * @param thirdCard 
         * @param fourthCard 
         * @param fifthCard 
         */
        FullHouse(ColorCard firstCard, ColorCard secondCard, ColorCard thirdCard, ColorCard fourthCard, ColorCard fifthCard);

        /**
         * @brief Destroy FullHouse object
         * 
         */
        virtual ~FullHouse();

        /**
         * @brief Get the Value object
         * 
         * @return float 
         */
        float getValue() const;
};

#endif