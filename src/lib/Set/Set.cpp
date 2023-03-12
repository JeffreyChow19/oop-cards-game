#include "Set.hpp"
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
#include <bits/stdc++.h>

using namespace std;

Set::Set(vector<Player> &listOfPlayer, int currPlayerIdx)
{
    this->listOfPlayer_ = listOfPlayer;
    this->points_ = 64;
    this->round_ = 1;
    this->mainDeck_ = MainDeck();
    this->tableDeck_ = TableDeck();
    this->currPlayerIdx_ = currPlayerIdx;
}

void Set::startRound()
{
    cout << "Welcome to round_ " << this->round_ << endl;
    cout << "In this round_, " << endl;
    vector<Command *> allowedCommands = {new Next(), new Double(), new Half()};
    vector<Ability *> abilities = {new Abilityless()};
    while (this->round_ != 6)
    {
        if (round_ != 1)
        {
            allowedCommands.push_back(listOfPlayer_[currPlayerIdx_].getAbility());
        }
        else
        {
        }
        cout << " you can use these commands: ";
        for (int i = 0; i < allowedCommands.size(); i++)
        {
            cout << "[" << i + 1 << "] " << allowedCommands[i]->getCommandName() << endl;
        }
        // askCommand(allowedCommands);
    }
}

void Set::advanceRound()
{
    if (this->round_ < 6)
    {
        this->round_++;
        // ubah urutan player
    }
}

void Set::askCommand(vector<string> allowedCommands)
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

string Set::inputCommand(vector<string> allowedCommands)
{
    string command;
    cin >> command;
    if (cin.fail() || find(allowedCommands.begin(), allowedCommands.end(), command) == allowedCommands.end())
    {
        throw CommandException();
    }
    return command;
}

void Set::setPoint(float multiplier)
{
    this->points_ *= multiplier;
}