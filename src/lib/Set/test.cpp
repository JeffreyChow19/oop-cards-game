#include "SetProcess.hpp"

int main()
{
    Player p1("Rachel");
    Player p2("Chow");
    Player p3("Livia");
    vector<Player> listOfPlayer = {p1, p2, p3};
    SetProcess setProcess(listOfPlayer, 0);
}