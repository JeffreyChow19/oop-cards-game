#include "Util.hpp"

using namespace std;

string askToStart(bool firstGame)
{
    // Initialize coloring
    Coloring clr;

    // Input options
    if (firstGame)
    {
        cout << "Are you ready to start the game? [Y/N] : ";
    }
    else
    {
        cout << "Play again? [Y/N] : ";
    }

    string opt;

    clr.lgreen();
    cin >> opt;
    clr.reset();

    if (opt != "Y" && opt != "N" && opt != "y" && opt != "n")
    {
        throw StringException();
    }
    return opt;
}

int askGame()
{
    cout << "Which game do you want to play? " << endl;
    cout << "[1] MasBro Candy" << endl;
    cout << "[2] MasBro Cangkul" << endl;
    int opt;
    cin >> opt;
    if (cin.fail())
    {
        throw IntegerException();
    }
    if (opt != 1 && opt != 2)
    {
        throw OptionException();
    }
    return opt;
}