#include "Player.hpp"

int main()
{
    Player p1("Rachel");
    p1.setPoint(1000);
    p1.setAbility("ReRoll");
    cout << "Player Point " << p1.getPoint() << endl;
    cout << "Player Ability " << p1.getAbility() << endl;
    ColorCard red13(Color::Red, 13);
    ColorCard red12(Color::Red, 12);
    ColorCard red10(Color::Red, 10);
    ColorCard red9(Color::Red, 9);
    ColorCard red5(Color::Red, 5);
    ColorCard red6(Color::Red, 6);
    ColorCard red7(Color::Red, 7);
    ColorCard green1(Color::Green, 1);
    ColorCard green2(Color::Green, 2);
    TableDeck tableDeck;
    p1.addPlayerCard(red9);  // simpan card 1 player
    p1.addPlayerCard(red13); // simpan card 2 player
    tableDeck + red12;       // atur table deck
    tableDeck + red5;
    tableDeck + red10;
    tableDeck + red6;
    tableDeck + red7;
    if (p1.checkPlayerFlush(tableDeck) != nullptr)
    {
        p1.checkPlayerFlush(tableDeck)->print(); // cek flush yg terbentuk udah bener ga
    }
}