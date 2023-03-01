#ifndef _COLORCARD_HPP_
#define _COLORCARD_HPP_

#include <bits/stdc++.h>
#include "../Card.hpp"

using namespace std;

enum class Color
{
    Red,
    Yellow,
    Green,
    Blue
}; // tanya boleh pake enum ga

class ColorCard : public Card
{
private:
    Color color_;
    int value_;

public:
    /**
     * @brief Construct a new Color Card object
     *
     * @param color
     * @param value
     */
    ColorCard(Color color, int value);

    /**
     * @brief Construct a new Color Card object copied from other
     *
     * @param other
     */
    ColorCard(const ColorCard &other);

    double getBaseValue() const;

    /**
     * @brief Get the value of the card (adds base value with this->value)
     * formula refer to pg 10
     *
     * @return double
     */
    virtual double getValue();
    // {
    //     static std::map<CardColor, double> base_values = {
    //         {CardColor::Red, 0.1},
    //         {CardColor::Yellow, 0.12},
    //         {CardColor::Green, 0.15},
    //         {CardColor::Blue, 0.18}};
    //     return base_values[color_];
    // }

    /**
     * @brief compares this with other ColorCard
     *
     * @return true if smaller
     * @return false
     */
    bool operator<(const ColorCard &) const;

    /**
     * @brief compares this with other ColorCard
     *
     * @return true if larger
     * @return false
     */
    bool operator>(const ColorCard &) const;

    /**
     * @brief compares if equal
     *
     * @return true if equal
     * @return false
     */
    bool operator==(const ColorCard &) const;
};

#endif