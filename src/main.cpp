#include "lib/InventoryHolder/MainDeck/MainDeck.hpp"

int main(){
    // HEADER
    cout << "WELCOME TO CANDY KINGDOM CARD COMPETITION\n";
    cout << "===========================================================\n\n";

    // INITIALIZE RANDOM MAINDECK
    MainDeck random_;
    cout << "Random deck constructed:\n";
    random_.randomizeCard();
    random_.printDeck();

    cout << endl << endl;

    // INITIALIZE CONFIG MAINDECK
    MainDeck config_;
    cout << "Config deck constructed:\n";
    config_.readCard();
    config_.printDeck();
}