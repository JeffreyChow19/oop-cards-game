#include "Util.hpp"

using namespace std;

string askToStart()
{
    cout << "Start the game? (Y/N)";
    string opt;
    cin >> opt;
    if (opt != "Y" && opt != "N" && opt != "y" && opt != "n")
    {
        throw StringException();
    }
    return opt;
}