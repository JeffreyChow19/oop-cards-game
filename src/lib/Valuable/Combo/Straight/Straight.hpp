#ifndef _STRAIGHT_HPP_
#define _STRAIGHT_HPP_

#include "../Combo.hpp"

class Straight : public Combo
{
private:
    vector<ColorCard> deck_;

public:
    /**
     * @brief Construct a new straight object
     *
     * @param firstCard
     * @param secondCard
     * @param thirdCard
     * @param fourthCard
     * @param fifthCard
     */
    Straight(vector<ColorCard> deck);

    /**
     * @brief Destroy Straight object
     *
     */
    virtual ~Straight();

    float getValue() const;

    void print();
};

#endif