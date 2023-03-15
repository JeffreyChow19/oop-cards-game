#ifndef _FLUSH_HPP_
#define _FLUSH_HPP_

#include "../Combo.hpp"
#include <math.h>
#include <algorithm>

class Flush : public Combo {
    private:
        vector<ColorCard> flushHand_; 
    public:
        /**
         * @brief Construct a new Flush object
         * 
         * @param cards 
         */
        Flush(vector<ColorCard> cards);

    ~Flush();

    /**
     * @brief Get the Value object
     *
     * @return float
     */
    float getValue() const;

    void print();

    string getComboName() const;
};

#endif