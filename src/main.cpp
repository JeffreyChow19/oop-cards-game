#include "lib/Game/Game.hpp"
#include "lib/Game/CangkulGame.hpp"
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
    cout << "================================" << endl
         << endl;

    clr.reset();

    bool firstGame = true;

    // initialize option value
    string opt = "Y";

    while (opt != "N" && opt != "n")
    {
        try
        {
            opt = askToStart(firstGame);
            if (opt == "Y" || opt == "y")
            {
                int gameChoice = -1;
                while (gameChoice == -1)
                {
                    try
                    {
                        gameChoice = askGame();
                    }
                    catch (IntegerException &e)
                    {
                        clr.red();
                        cout << e.what();
                        clr.reset();

                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    catch (OptionException &e)
                    {
                        clr.red();
                        cout << e.what();
                        clr.reset();
                    }
                }
                if (gameChoice == 1)
                {
                    Game game;
                    game.startGame();
                }
                else
                {
                    CangkulGame game;
                    game.startGame();
                }
                firstGame = false;
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