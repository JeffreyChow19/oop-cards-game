#include "MainDeck/MainDeck.hpp"
#include "TableDeck/TableDeck.hpp"

int main() {
    MainDeck main_;

    cout << "First main deck constructed:\n";
    main_.printDeck();

    main_.randomizeCard();
    cout << "Main deck after shuffled:\n";
    main_.printDeck();

    TableDeck table;
    table.addCard(main_);
    table.addCard(main_);
    // ColorCard a = main_.getFromMainDeck();
    // ColorCard b = main_.getFromMainDeck();
    cout << "Main deck after picked two cards:\n";
    main_.printDeck();
    // table.addCard(a);
    // table.addCard(b);
    cout << "Table deck:\n";
    table.printDeck();

    return 0;
}