#include "Pair.hpp"
#include <bits/stdc++.h>
using namespace std;

Pair::Pair(pair<ColorCard,ColorCard> cardPair):cardPair_(cardPair){

}

Pair::~Pair(){

}

float Pair::getValue(){
    return 1.39 + (0.05 * cardPair_.first.getBaseValue() + 0.2 * cardPair_.first.getValue());
}