#include "lib/Game/Game.hpp"
#include "lib/Util/Util.hpp"

int main()
{
    string opt = "Y";
    while (opt != "N" && opt != "n")
    {
        try
        {
            opt = askToStart();
            if (opt == "Y" || opt == "y")
            {
                Game game;
                game.startGame();
            }
        }
        catch (StringException &e)
        {
            e.what();
        }
    }
    cout << "Thank you for playing!!" << endl;
}