#include "lib/InventoryHolder/MainDeck/MainDeck.hpp"

int main(){
    // HEADER
    cout << "\n=========================================\n";
    cout << "WELCOME TO CANDY KINGDOM CARD COMPETITION\n";
    cout << "=========================================\n\n";

    // INITIALIZE RANDOM MAINDECK
    MainDeck firstDeck;
    firstDeck.printDeck();

    MainDeck secondDeck;
    secondDeck.printDeck();
}