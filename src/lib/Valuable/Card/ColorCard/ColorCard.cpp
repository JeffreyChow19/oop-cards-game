#include "ColorCard.hpp"
#include "bits/stdc++.h"

using namespace std;

ColorCard::ColorCard() : color_(Color::Green), Card(1) {}

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

float ColorCard::getBaseValue() const
{
    return static_cast<float>(this->color_);
}

float ColorCard::getValue() const
{
    return static_cast<float>(this->value_);
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

bool ColorCard::compareByColor(const ColorCard &first, const ColorCard &second)
{
    return first.getBaseValue() <= second.getBaseValue();
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

void ColorCard::printGroup(vector<ColorCard> cc){
    Coloring clr;
    for (int i = 0; i < 6; i++){
        for (auto &c : cc){
            // apply c color
            switch (c.color_){
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

            // initialize padding
            string padding = c.value_ >= 10 ? " " : "";

            // which line
            if (i == 0){
                cout << " _____" << ((c.value_ >= 10) ? "_" : "") << " ";
            } else if (i == 1){
                cout << "|" << to_string(c.value_) << "    |";
            } else if (i == 5){
                cout << "|____" << to_string(c.value_) << "|";
            } else {
                cout << "|     " << ((c.value_ >= 10) ? " " : "") << "|"; 
            }

            // padding right
            cout << "  ";
            clr.reset();
        }
        cout << endl;
    }
}