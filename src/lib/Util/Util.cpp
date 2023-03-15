#include "Util.hpp"

using namespace std;

string askToStart()
{
    // Initialize coloring
    Coloring clr;

    // Input options
    cout << "Are you ready to start the game? [Y/N] : ";

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