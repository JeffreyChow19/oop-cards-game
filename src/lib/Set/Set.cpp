#include "Set.hpp"
#include <bits/stdc++.h>

using namespace std;

Set::Set(vector <Player> listOfPlayer){
    this->listOfPlayer = listOfPlayer;
    this->points = 64;
    this->round = 1;
    this->mainDeck = MainDeck();
    this->tableDeck = TableDeck();
}

void Set::startRound(){
    cout <<"Welcome to round " << this->round; 
    switch (this->round){
        case 1:
            break;
        default:
            break;
    }
}

void Set::advanceRound(){

}

void Set::askCommand(){
    string command;
    cout << "Input command : ";
    cin >> command;

    
}