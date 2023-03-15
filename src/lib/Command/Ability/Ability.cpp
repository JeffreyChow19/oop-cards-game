#include "Ability.hpp"

Ability::Ability() {}

int Ability::inputOption(int sumOpt) {
    Coloring clr;
    int opt;
    cout << "Input option: ";

    clr.lgreen();
    cin >> opt;
    clr.reset();

    if (cin.fail())
    {
        throw IntegerException();
    }
    else if (opt < 1 || opt > sumOpt)
    {
        throw OptionException();
    }
    return opt;
}