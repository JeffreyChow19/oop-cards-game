#include "Game.hpp"
#include "../Exception/Exception.hpp"

Game::Game() {
    for (int i = 0; i < 7; i++) {
        string nickname;
        try {
            cin >> nickname;
            if (cin.fail()) {
                throw StringException();
            }
            Player playerElmt(nickname);
            this->listOfPlayer.push_back(playerElmt);
        } catch (StringException& e) {
            e.what();
        } 
    }

    while (!checkEndGame) {
        
    }
}

bool Game::checkEndGame() {
    auto player_itr = this->listOfPlayer.begin();
    while (player_itr != this->listOfPlayer.end()) {
        if (player_itr->getPoint()== pow(2,32)) {
            return true;
        }
    }
    return false;
}