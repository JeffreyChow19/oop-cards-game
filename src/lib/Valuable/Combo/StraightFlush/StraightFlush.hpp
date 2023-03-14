#ifndef _STRAIGHT_HPP_
#define _STRAIGHT_HPP_

#include "../Combo.hpp"


class StraightFlush : public Combo {
    private:
        vector<ColorCard> sfHand_; 
    public:
        /**
         * @brief Construct a new Straight Flush object
         * 
         * @param firstCard 
         * @param secondCard 
         * @param thirdCard 
         * @param fourthCard 
         * @param fifthCard 
         */
        StraightFlush(ColorCard firstCard, ColorCard secondCard, ColorCard thirdCard, ColorCard fourthCard, ColorCard fifthCard);

        /**
         * @brief Destroy StraightFlush object
         * 
         */
        virtual ~StraightFlush();

        /**
         * @brief Get the Value object
         * 
         * @return float 
         */
        float getValue();
};

#endif