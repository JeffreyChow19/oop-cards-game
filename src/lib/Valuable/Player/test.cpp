#include "Player.hpp"

int main()
{
    Player p1("Rachel");
    p1.setPoint(1000);
    p1.setAbility("ReRoll");
    cout << "Player Point " << p1.getPoint() << endl;
    cout << "Player Ability " << p1.getAbility() << endl;
    ColorCard red1(Color::Red, 1);
    ColorCard red2(Color::Red, 2);
    ColorCard red3(Color::Red, 3);
    ColorCard red4(Color::Red, 4);
    ColorCard red5(Color::Red, 5);
    ColorCard green1(Color::Green, 1);
    ColorCard green2(Color::Green, 2);
    vector<ColorCard> temp = {red1, red2, red3, red4, red5, green1, green2};
    Flush *cmb = p1.checkPlayerFlush(temp);
}