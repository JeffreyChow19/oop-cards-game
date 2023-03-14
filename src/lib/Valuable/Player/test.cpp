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
    ColorCard red11(Color::Red, 11);
    ColorCard red10(Color::Red, 10);
    ColorCard blue10(Color::Blue, 10);
    ColorCard red9(Color::Red, 9);
    ColorCard red5(Color::Red, 5);
    ColorCard yellow5(Color::Yellow, 5);
    ColorCard red6(Color::Red, 6);
    ColorCard red7(Color::Red, 7);
    ColorCard green7(Color::Green, 7);
    ColorCard green1(Color::Green, 1);
    ColorCard green2(Color::Green, 2);
    ColorCard green10(Color::Green, 10);
    ColorCard green11(Color::Green, 11);
    ColorCard green12(Color::Green, 12);
    ColorCard green13(Color::Green, 13);
    ColorCard green8(Color::Green, 8);


    TableDeck tableDeck;

    p1.addPlayerCard(red12);  // simpan card 1 player
    p1.addPlayerCard(green11); // simpan card 2 player

    tableDeck + green12;       // atur table deck
    tableDeck + red11;
    tableDeck + green10;
    tableDeck + red13;
    tableDeck + red9;

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

    // TwoPair* isTwoPair = p1.checkPlayerTwoPair(tableDeck);
    // if (isTwoPair != nullptr){
    //     isTwoPair->print();
    // }
    tableDeck.print();
    Straight* isStraight = p1.checkPlayerStraight(tableDeck);
    if (isStraight != nullptr){
        isStraight->print();
    }
}