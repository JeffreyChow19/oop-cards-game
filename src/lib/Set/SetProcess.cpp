#include "SetProcess.hpp"
#include "../Exception/Exception.hpp"
#include "../Command/Command.hpp"
#include "../Command/Next.hpp"
#include "../Command/Double.hpp"
#include "../Command/Half.hpp"
#include "../Command/Ability/Abilityless/Abilityless.hpp"
#include "../Command/Ability/Quadruple/Quadruple.hpp"
#include "../Command/Ability/Quarter/Quarter.hpp"
#include "../Command/Ability/ReRoll/ReRoll.hpp"
#include "../Command/Ability/Reverse/Reverse.hpp"
#include "../Command/Ability/Swap/Swap.hpp"
#include "../Command/Ability/Switch/Switch.hpp"

void SetProcess::startRound()
{
    cout << "Welcome to round_ " << this->round_ << endl;
    cout << "In this round_, " << endl;
    vector<Command *> allowedCommands = {new Next(), new Double(), new Half()};
    vector<Ability *> abilities = {new Abilityless()};
    while (this->round_ != 6)
    {
    }
}

void SetProcess::advanceRound()
{
    if (this->round_ < 6)
    {
        this->round_++;
        // ubah urutan player
    }
}

void SetProcess::askCommand(vector<string> allowedCommands)
{
    string command = "none";
    while (command == "none")
    {
        try
        {
            cout << "Input command : ";
            cin >> command;
        }
        catch (CommandException &err)
        {
        }
    }
}

string SetProcess::inputCommand(vector<string> allowedCommands)
{
    string command;
    cin >> command;
    if (cin.fail() || find(allowedCommands.begin(), allowedCommands.end(), command) == allowedCommands.end())
    {
        throw CommandException();
    }
    return command;
}

// void SetProcess::(float multiplier)
// {
//     this->points_ *= multiplier;
// }