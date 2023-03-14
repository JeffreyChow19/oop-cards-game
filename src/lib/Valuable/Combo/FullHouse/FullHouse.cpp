#include "FullHouse.hpp"
using namespace std;

FullHouse::FullHouse(vector<ColorCard> deck){
    vector<ColorCard> temp = deck;
    sort(temp.begin(), temp.end(), ColorCard::compareByValue);
    if(temp[1]== temp[2]){
        Pair pair(make_pair(temp[3], temp[4]));
        this->pair_ = pair;
        vector<ColorCard> newTris;
        newTris.push_back(temp[0]);
        newTris.push_back(temp[1]);
        newTris.push_back(temp[2]);
        ThreeOfAKind tris(newTris);
        this->tris_ = tris;
    }else{
        Pair pair(make_pair(temp[0], temp[1]));
        this->pair_ = pair;
        vector<ColorCard> newTris;
        newTris.push_back(temp[2]);
        newTris.push_back(temp[3]);
        newTris.push_back(temp[4]);
        ThreeOfAKind tris(newTris);
        this->tris_ = tris;
    }
}

FullHouse::~FullHouse(){

}

float FullHouse::getValue() const{
    float res = FLUSH_MAX;   /* maximum flush value */

    res += tris_.getValue();       /* highest card in the combination */
    
    return res;
}