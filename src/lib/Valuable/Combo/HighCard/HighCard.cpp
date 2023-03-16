#include "HighCard.hpp"
using namespace std;

HighCard::HighCard(ColorCard card) : card_(card) {}

HighCard::~HighCard()
{
}

float HighCard::getValue() const
{
    return 0.03 * card_.getBaseValue() + 0.1 * card_.getValue();
}

void HighCard::print()
{
    this->card_.printInfo();
}

string HighCard::getComboName() const {
    return "HIGH CARD";
}