#include "FullHouse.hpp"
using namespace std;

FullHouse::FullHouse(vector<ColorCard> threes, vector<ColorCard> twos){
    this->tris_ = ThreeOfAKind(threes);
    this->pair_ = Pair(make_pair(twos[0], twos[1]));
}

FullHouse::~FullHouse(){

}

float FullHouse::getValue() const {
    /* rumus : concat(encode(three), encode(pair)) + maxflush */       
    float res = FLUSH_MAX;   /* maximum flush value */

    res += tris_.getValue() + 0.00001 * pair_.getValue();
    
    return res;
}

void FullHouse::print()
{
    pair_.print();
    tris_.print();
}

string FullHouse::getComboName() const{
    return "FULL HOUSE";
}