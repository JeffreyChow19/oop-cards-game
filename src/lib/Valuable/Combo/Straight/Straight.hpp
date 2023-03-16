#ifndef _STRAIGHT_HPP_
#define _STRAIGHT_HPP_

#include <vector>
#include <algorithm>
#include "../Combo.hpp"

class Straight : public Combo
{
protected:
    vector<ColorCard> deck_;

public:
    /**
     * @brief Construct a new Straight object
     * 
     * @param deck 
     */
    Straight(vector<ColorCard> deck);

    /**
     * @brief Destroy Straight object
     *
     */
    virtual ~Straight();

    float getValue() const;

    void print();

    vector<ColorCard> &getDeck();

    string getComboName() const;
};

#endif