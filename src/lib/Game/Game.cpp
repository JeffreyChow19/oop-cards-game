#include "Game.hpp"
#include "../Exception/Exception.hpp"

Game::Game() : endGame(false) {
    for (int i = 0; i < 7; i++) {
        string nickname;
        try {
            cin >> nickname;
            if (cin.fail()) {
                throw InputException();
            }
            Player playerElmt(nickname);
            this->listOfPlayer.push_back(playerElmt);
        } catch (InputException& e) {
            e.what();
        }
        
    }
}