#include "../CandyPlayer.hpp"

int main()
{
    TableDeck tableDeck;
    CandyPlayer p1("Rachel");
    p1.setPoint(1000);
    p1.setAbility("ReRoll");
    cout << "Player Point " << p1.getPoint() << endl;
    cout << "Player Ability " << p1.getAbility() << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << "Kartu player (format: Warna Angka) mis: Red 5" << endl;
        string warna;
        int angka;
        cin >> warna >> angka;
        if (warna == "Red")
        {
            ColorCard red(Color::Red, angka);
            p1.addPlayerCard(red);
        }
        if (warna == "Green")
        {
            ColorCard green(Color::Green, angka);
            p1.addPlayerCard(green);
        }
        if (warna == "Blue")
        {
            ColorCard blue(Color::Blue, angka);
            p1.addPlayerCard(blue);
        }
        if (warna == "Yellow")
        {
            ColorCard yellow(Color::Yellow, angka);
            p1.addPlayerCard(yellow);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "Kartu Table Deck (format: Warna Angka) mis: Red 5" << endl;
        string warna;
        int angka;
        cin >> warna >> angka;
        if (warna == "Red")
        {
            ColorCard red(Color::Red, angka);
            tableDeck + red;
        }
        if (warna == "Green")
        {
            ColorCard green(Color::Green, angka);
            tableDeck + green;
        }
        if (warna == "Blue")
        {
            ColorCard blue(Color::Blue, angka);
            tableDeck + blue;
        }
        if (warna == "Yellow")
        {
            ColorCard yellow(Color::Yellow, angka);
            tableDeck + yellow;
        }
    }
    p1.printCards();
    tableDeck.print();
    Combo *combo = p1.checkPlayerCombo(tableDeck);
    if (combo != nullptr)
    {
        combo->print();
        cout << combo->getValue() << endl;
    }
    delete combo;
}