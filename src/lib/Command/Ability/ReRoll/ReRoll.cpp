#include "ReRoll.hpp"

void ReRoll::activate(Set &set)
{
    cout << "Melakukan pembuangan kartu yang sedang dimiliki\n";

    // Ambil dua kartu baru
    vector<ColorCard> newPlayerDeck;
    ColorCard add1 = set.getMainDeck().getFromMainDeck();
    ColorCard add2 = set.getMainDeck().getFromMainDeck();

    // Set kartu player dengan dua kartu baru
    set.getListOfPlayers()[set.getCurrPlayerIdx()].setPlayerDeck(newPlayerDeck);

    cout << "Kamu mendapatkan 2 kartu baru yaitu:\n";
    cout << "1. "; 
    set.getListOfPlayers()[set.getCurrPlayerIdx()].getPlayerDeck()[0].printInfo();
    cout << "\n2. "; 
    set.getListOfPlayers()[set.getCurrPlayerIdx()].getPlayerDeck()[1].printInfo();
    cout << endl;
}

string ReRoll::getCommandName()
{
    return "RE-ROLL";
}