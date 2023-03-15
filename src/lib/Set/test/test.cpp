#include "../SetProcess.hpp"

int main()
{
    Player p1("Rachel");
    Player p2("Chow");
    Player p3("Livia");
    Player p4("Tes4");
    Player p5("Tes5");
    Player p6("Tes6");
    Player p7("Tes7");
    vector<Player> listOfPlayer = {p1, p2, p3, p4, p5, p6, p7};
    SetProcess setProcess(listOfPlayer, 0);
}