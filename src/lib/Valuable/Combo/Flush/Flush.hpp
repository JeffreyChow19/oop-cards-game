#ifndef _FLUSH_HPP_
#define _FLUSH_HPP_

#include "../Combo.hpp"

class Flush {
    private:
        vector<ColorCard> flushHand_; 
    public:
        /**
         * @brief Construct a new Flush object
         * 
         * @param firstCard 
         * @param secondCard 
         * @param thirdCard 
         * @param fourthCard 
         * @param fifthCard 
         */
        Flush(ColorCard firstCard, ColorCard secondCard, ColorCard thirdCard, ColorCard fourthCard, ColorCard fifthCard);

        /**
         * @brief Destroy the Flush object
         * 
         */
        virtual ~Flush();

        /**
         * @brief Get the Value object
         * 
         * @return float 
         */
        float getValue();
};

#endif