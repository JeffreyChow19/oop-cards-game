#include "Set.hpp"
#include "../Exception/Exception.hpp"
#include <bits/stdc++.h>

using namespace std;

Set::Set(vector <Player> listOfPlayer){
    this->listOfPlayer_ = listOfPlayer;
    this->points_ = 64;
    this->round_ = 1;
    this->mainDeck_ = MainDeck();
    this->tableDeck_ = TableDeck();
}

void Set::startRound(){
    cout <<"Welcome to round_ " << this->round_ << endl; 
    cout << "In this round_, " << endl;
    if (this->round_ != 6){
        vector <string> allowedCommands = {"NEXT", "HALF", "DOUBLE"};
        if (round_!=1){
            vector <string> abilityCommands = {"","",""};
            allowedCommands.insert(allowedCommands.end(), abilityCommands.begin(), abilityCommands.end());
        }
        cout << " you can use these commands: ";
        for (int i = 0 ; i <allowedCommands.size() ;i++){
            cout << "[" << i+1 <<"] " << allowedCommands[i] << endl;
        }
        askCommand(allowedCommands);
    }
}

void Set::advanceRound(){
    if (this->round_ < 6){
        this->round_++;
        // ubah urutan player
    }
}

void Set::askCommand(vector <string> allowedCommands){
    string command = "none";
    while (command == "none"){
        try {
            cout << "Input command : ";
            cin >> command;
        } catch(CommandException& err){
            
        }
    }

}

string Set::inputCommand(vector <string> allowedCommands){
    string command;
    cin >> command;
    if (cin.fail() || find(allowedCommands.begin(), allowedCommands.end(), command) == allowedCommands.end()){
        throw CommandException();
    }
    return command;
}