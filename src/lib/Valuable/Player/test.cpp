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
    ColorCard red10(Color::Red, 10);
    ColorCard red12(Color::Red, 12);
    ColorCard red13(Color::Red, 13);
    ColorCard blue10(Color::Blue, 10);
    ColorCard red9(Color::Red, 9);
    ColorCard red5(Color::Red, 5);
    ColorCard yellow5(Color::Yellow, 5);
    ColorCard red6(Color::Red, 6);
    ColorCard red7(Color::Red, 7);
    ColorCard green7(Color::Green, 7);
    ColorCard green1(Color::Green, 1);
    ColorCard green2(Color::Green, 2);
    ColorCard green3(Color::Green, 3);
    ColorCard green4(Color::Green, 4);
    ColorCard blue1(Color::Blue, 1);
    ColorCard blue2(Color::Blue, 2);
    ColorCard blue3(Color::Blue, 3);
    ColorCard blue4(Color::Blue, 4);
    TableDeck tableDeck;
    p1.addPlayerCard(green2); // simpan card 1 player
    p1.addPlayerCard(red1);   // simpan card 2 player
    tableDeck + blue3;        // atur table deck
    tableDeck + green3;
    tableDeck + blue4;
    tableDeck + red4;
    tableDeck + green4;

    // Flush* isFlush = p1.checkPlayerFlush(tableDeck);
    // if (p1.checkPlayerFlush(tableDeck) != nullptr)
    // {
    //     // p1.checkPlayerFlush(tableDeck)->print(); // cek flush yg terbentuk udah bener ga
    //     // ColorCard::printGroup(isFlush->print);
    //     isFlush->print();
    // }

    // Pair* isPair = p1.checkPlayerPair(tableDeck);
    // if (isPair != nullptr){
    //     cout << "hellow" << endl;
    //     isPair->print();
    // }

    FullHouse *isFullHouse = p1.checkPlayerFullHouse(tableDeck);
    if (isFullHouse != nullptr)
    {
        isFullHouse->print();
    }
    else
    {
        cout << "AAA" << endl;
    }
}