#ifndef _COLORCARD_HPP_
#define _COLORCARD_HPP_

#include <bits/stdc++.h>
#include "../Card.hpp"

using namespace std;


enum class Color
{
    Green = 0,
    Blue = 1,
    Yellow = 2,
    Red = 3,
    Last
}; // tanya boleh pake enum ga

class ColorCard : public Card
{
private:
    Color color_;

public:
    /**
     * @brief Construct a new Color Card object, default color=Green, value=1
     * 
     */
    ColorCard();

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

    string getColor() const;

    double getBaseValue() const;

    /**
     * @brief Get the value of the card (adds base value with this->value)
     * formula refer to pg 10
     *
     * @return double
     */
    virtual double getValue() const;

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
     * @brief print card info
     *
     */
    void printInfo();

    bool operator==(const ColorCard &) const;

    friend bool compareByColor(const ColorCard &, const ColorCard &);
};

#endif