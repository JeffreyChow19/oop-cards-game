#ifndef _GAME_HPP
#define _GAME_HPP

#include "../Valuable/Player/CandyPlayer.hpp"
#include "../Exception/Exception.hpp"
#include "../Util/Coloring.hpp"
#include <unistd.h>
#include <iomanip>

using namespace std;

class Game
{
private:
        vector<CandyPlayer> listOfPlayer;

public:
        Game();
        ~Game();
        void startGame();
        bool checkEndGame();
};

#endif