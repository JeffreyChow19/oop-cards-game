#include "Game.hpp"
#include "../Set/SetProcess.hpp"
#include "../Exception/Exception.hpp"

Game::Game()
{
    cout << " __   __  _______  _______  _______  ______    _______    _______  _______  ______    _______  __   __ "
            "|  |_|  ||   _   ||       ||  _    ||    _ |  |       |  |       ||   _   ||    _ |  |       ||  | |  |"
            "|       ||  |_|  ||  _____|| |_|   ||   | ||  |   _   |  |    _  ||  |_|  ||   | ||  |_     _||  |_|  |"
            "|       ||       || |_____ |       ||   |_||_ |  | |  |  |   |_| ||       ||   |_||_   |   |  |       |"
            "|       ||       ||_____  ||  _   | |    __  ||  |_|  |  |    ___||       ||    __  |  |   |  |_     _|"
            "| ||_|| ||   _   | _____| || |_|   ||   |  | ||       |  |   |    |   _   ||   |  | |  |   |    |   |  "
            "|_|   |_||__| |__||_______||_______||___|  |_||_______|  |___|    |__| |__||___|  |_|  |___|    |___|  "
         << endl;

    for (int i = 0; i < 7; i++)
    {
        string nickname;
        try
        {
            cout << "Enter the nickname of Player " << i + 1 << ": ";
            cin >> nickname;
            if (cin.fail())
            {
                throw StringException();
            }
            Player playerElmt(nickname);
            this->listOfPlayer.push_back(playerElmt);
        }
        catch (StringException &e)
        {
            e.what();
        }
    }

}

void Game::startGame(){
    while (!checkEndGame())
    {
        SetProcess gameSet(listOfPlayer, 0);
    }
}

bool Game::checkEndGame()
{
    for (auto &p: listOfPlayer){
        if (p.getPoint() == pow(2, 32)){
            return true;
        }
    }
    return false;
}

Game::~Game(){
    this->listOfPlayer.clear();
}