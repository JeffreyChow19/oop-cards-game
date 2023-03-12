#include "Set.hpp"
#include <bits/stdc++.h>

using namespace std;

Set::Set(){
    
}

Set::Set(vector<Player> &listOfPlayer, int currPlayerIdx)
{
    this->listOfPlayer_ = listOfPlayer;
    this->points_ = 64;
    this->round_ = 1;
    this->mainDeck_ = MainDeck();
    this->tableDeck_ = TableDeck();
    this->currPlayerIdx_ = currPlayerIdx;
}
