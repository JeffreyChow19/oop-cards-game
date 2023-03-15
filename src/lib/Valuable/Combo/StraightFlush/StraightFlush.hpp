#ifndef _STRAIGHTFLUSH_HPP_
#define _STRAIGHTFLUSH_HPP_

#include "../Combo.hpp"
#include <algorithm>
#include <vector>

class StraightFlush : public Combo
{
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

    void print();

    string getComboName() const;
};

#endif