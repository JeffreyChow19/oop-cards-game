#include "ColorCard.hpp"
#include "bits/stdc++.h"

using namespace std;

ColorCard::ColorCard(Color color, int value) : color_(color), Card(value) {
}

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
    return static_cast<double>(this->color_);
}

double ColorCard::getValue() const
{
    return value_;
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
    if (this->getColor() == other.getColor() && this->getValue() == other.getValue())
    {
        return true;
    }
    return false;
}

void ColorCard::printInfo(){
    Coloring clr;
    switch (this->color_){
        case Color::Red:
            clr.red();
            break;
        case Color::Green:
            clr.green();
            break;
        case Color::Blue:
            clr.blue();
            break;
        case Color::Yellow:
            clr.yellow();
            break;
    }

    if (this->value_ >= 10){
        cout << " ______ \n" 
                "|" + to_string(this->value_) + "    |\n"
                "|      |\n"
                "|      |\n"
                "|      |\n"
                "|____" + to_string(this->value_) + "|\n";              
    } else {
        cout << " _____ \n" 
                "|" + to_string(this->value_) + "    |\n"
                "|     |\n"
                "|     |\n"
                "|     |\n"
                "|____" + to_string(this->value_) + "|\n";        
    } 

    clr.reset();
}