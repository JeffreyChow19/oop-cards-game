#ifndef _GAME_HPP
#define _GAME_HPP

#include <bits/stdc++.h>
#include "../Valuable/Player/Player.hpp"

using namespace std;

class Game
{
private:
        vector<Player> listOfPlayer;

public:
        Game();
        ~Game();
        bool checkEndGame();
};

#endif