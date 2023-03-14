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
    ColorCard red6(Color::Red, 6);
    ColorCard red7(Color::Red, 7);
    ColorCard green1(Color::Green, 1);
    ColorCard green2(Color::Green, 2);
    TableDeck tableDeck;
    p1.addPlayerCard(red6);
    p1.addPlayerCard(red7);
    tableDeck + red3;
    tableDeck + red4;
    tableDeck + red5;
    tableDeck + red6;
    tableDeck + red1;
    if (p1.checkPlayerFlush(tableDeck) != nullptr)
    {
        p1.checkPlayerFlush(tableDeck)->print();
    }
}