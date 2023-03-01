#include "ColorCard.hpp"
#include "bits/stdc++.h"

using namespace std;

ColorCard::ColorCard(Color color, int value) : color_(color), Card(value) {}

ColorCard::ColorCard(const ColorCard &other) : color_(other.color_), Card(other.value_)
{
}

string ColorCard::getColor() const
{
    map<Color, string> colorMap = {
        {Color::Red, "Red"},
        {Color::Yellow, "Yellow"},
        {Color::Green, "Green"},
        {Color::Blue, "Blue"}};
    return colorMap[color_];
}

double ColorCard::getBaseValue() const
{
    map<Color, double> baseValues = {
        {Color::Red, 0.1},
        {Color::Yellow, 0.12},
        {Color::Green, 0.15},
        {Color::Blue, 0.18}};
    return baseValues[color_];
}

double ColorCard::getValue() const
{
    return getBaseValue() + 0.1 * value_;
}

bool ColorCard::operator<(const ColorCard &other) const
{
    return this->getValue() < other.getValue();
}

bool ColorCard::operator>(const ColorCard &other) const
{
    return this->getValue() > other.getValue();
}

bool ColorCard::operator==(const ColorCard &other) const
{
    return this->getValue() == other.getValue();
}

void ColorCard::printInfo()
{
    cout << getColor() << " " << value_;
}