#include "HighCard.hpp"
#include <bits/stdc++.h>
using namespace std;

HighCard::HighCard(ColorCard card) : card_(card){}

HighCard::~HighCard(){
}

float HighCard::getValue(){
    return 0.03 * card_.getBaseValue() + 0.1 * card_.getValue();
}