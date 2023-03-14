#ifndef _STRAIGHT_HPP_
#define _STRAIGHT_HPP_

#include "../Combo.hpp"


class StraightFlush : public Combo {
    private:
        vector<ColorCard> cards_; 
    public:
        /**
         * @brief Construct a new Straight Flush object
         * 
         * @param cards 
         */
        StraightFlush(vector<ColorCard> cards);

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
        float getValue() const;
};

#endif