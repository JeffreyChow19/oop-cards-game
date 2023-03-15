#include "lib/Game/Game.hpp"
#include "lib/Util/Util.hpp"
#include "lib/Util/Coloring.hpp"

int main()
{
    // Initialize coloring
    Coloring clr;

    // Welcoming message
    clr.green(true);

    cout << "\n================================" << endl;
    cout << "Welcome to MasbroParty Card Game" << endl;
    cout << "================================" << endl << endl;

    clr.reset();

    // initialize option value
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
    
    // game ended
    clr.white(true);
    cout << "Thank you for playing!!" << endl;
    clr.reset();
}