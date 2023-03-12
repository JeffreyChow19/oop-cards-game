#include "Player.hpp"

int main()
{
    Player p1("Rachel");
    p1.setPoint(1000);
    p1.setAbility("ReRoll");
    cout << "Player Point " << p1.getPoint() << endl;
    cout << "Player Ability " << p1.getAbility() << endl;
}