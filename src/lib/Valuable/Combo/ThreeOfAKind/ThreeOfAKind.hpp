#ifndef _THREE_OF_A_KIND_HPP_
#define _THREE_OF_A_KIND_HPP_

#include "../Combo.hpp"

class ThreeOfAKind : public Combo
{
private:
    vector<ColorCard> triple_;

public:
    /**
     * @brief Construct a new Three Of A Kind object
     *
     * @param firstCard
     * @param secondCard
     * @param thirdCard
     */
    ThreeOfAKind(vector<ColorCard> cards);

    /**
     * @brief Destroy the Three Of A Kind object
     *
     */
    virtual ~ThreeOfAKind();

    /**
     * @brief Get the Value of object
     *
     * @return float
     */
    float getValue();
    void print();
};

#endif