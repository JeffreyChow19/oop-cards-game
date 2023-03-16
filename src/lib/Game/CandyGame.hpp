#ifndef _CANDY_GAME_HPP
#define _CANDY_GAME_HPP

#include "../Valuable/Player/CandyPlayer.hpp"
#include "../Exception/Exception.hpp"
#include "../Util/Coloring.hpp"
#include <unistd.h>
#include <iomanip>

using namespace std;

class CandyGame
{
private:
        vector<CandyPlayer> listOfPlayer;

public:
        CandyGame();
        ~CandyGame();
        void startGame();
        bool checkEndGame();
};

#endif