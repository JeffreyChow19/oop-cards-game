#include "../MainDeck/MainDeck.hpp"
#include "../TableDeck/TableDeck.hpp"

int main() {
    MainDeck main_;

    // cout << "First main deck constructed:\n";
    // main_.print();

    // main_.randomizeCard();
    cout << "Main deck after shuffled:\n";
    main_.fillDeck();
    main_.print();

    TableDeck table;
    table.addCard(main_);
    table.addCard(main_);
    // ColorCard a = main_.getFromMainDeck();
    // ColorCard b = main_.getFromMainDeck();
    cout << "Main deck after picked two cards:\n";
    main_.print();
    // table.addCard(a);
    // table.addCard(b);
    cout << "Table deck:\n";
    table.print();

    return 0;
}