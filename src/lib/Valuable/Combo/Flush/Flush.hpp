#ifndef _FLUSH_HPP_
#define _FLUSH_HPP_

#include "../Combo.hpp"
#include <math.h>

class Flush {
    private:
        vector<ColorCard> flushHand_; 
    public:
        /**
         * @brief Construct a new Flush object
         * 
         * @param cards 
         */
        Flush(vector<ColorCard> cards);

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
        float getValue() const;
};

#endif