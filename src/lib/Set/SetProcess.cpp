#include "SetProcess.hpp"
#include "../Exception/Exception.hpp"

SetProcess::SetProcess(vector<Player> &listOfPlayer, int firstPlayerIdx) : Set(listOfPlayer, firstPlayerIdx)
{
    vector<string> allowedCommands = {"NEXT", "HALF", "DOUBLE"};
    vector<string> abilities = {"RE-ROLL", "REVERSE", "SWITCH", "SWAP", "QUARTER", "QUADRUPLE", "ABILITYLESS"};
    commands_ = {new Next(),
                 new Double(),
                 new Half(),
                 new Abilityless(),
                 new Quadruple(),
                 new Quarter(),
                 new ReRoll(),
                 new Reverse(),
                 new Swap(),
                 new Switch()};
    // ROUND 1 - 5 take commands
    while (this->round_ <= 6)
    {
        cout << "**************************************" << endl;
        cout << "          Welcome to round " << this->round_ << endl;
        cout << "**************************************" << endl
             << endl;

        cout << endl;
        // keep tracker of player
        for (auto &p : listOfPlayer_)
        {
            p.setHasPlayed(false);
            if (round_ != 1)
            {
                p.setAbilityStatus(true);
            }
        }

        allowedCommands = {"NEXT", "HALF", "DOUBLE"};

        if (this->round_ != 6)
        {
            this->tableDeck_.addCard(this->mainDeck_);
            cout << "Table Deck :" << endl;
            ColorCard::printGroup(this->tableDeck_.getDeck());
            currPlayerIdx = firstPlayerIdx_;
            int playerMoved = 0;
            while (playerMoved < listOfPlayer_.size())
            {
                Player &currPlayer = listOfPlayer_[currPlayerIdx];
                if (!currPlayer.getHasPlayed())
                {
                    cout << endl;
                    printSetInfo();
                    cout << endl
                         << "It's " << currPlayer.getNickname() << "'s turn" << endl;
                    cout << "Player's cards : " << endl;
                    currPlayer.printCards();

                    if (this->round_ != 1)
                    {
                        allowedCommands.push_back(currPlayer.getAbility());
                    }
                    askCommand(allowedCommands, currPlayer);
                    if (this->round_ != 1)
                    {
                        allowedCommands.pop_back();
                    }
                    listOfPlayer_[currPlayerIdx].setHasPlayed(true);
                    playerMoved++;
                }
                currPlayerIdx = (currPlayerIdx + 1) % listOfPlayer_.size();
            }

            if (this->round_ == 1)
            {
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<> dis(0, abilities.size() - 1);
                // to do : make wait disinii jadi nunggu
                cout << "Shuffling abilities... " << endl;
                // Shuffle the abilities
                for (int i = 0; i < abilities.size(); ++i)
                {
                    swap(abilities[i], abilities[dis(gen)]);
                }
                for (int i = 0; i < this->listOfPlayer_.size(); i++)
                {
                    cout << listOfPlayer_[i].getNickname() << " got " << abilities[i] << " ability" << endl;
                    this->listOfPlayer_[i].setAbility(abilities[i]);
                    this->listOfPlayer_[i].setAbilityStatus(true);
                }
            }

            firstPlayerIdx_ = (firstPlayerIdx_ + 1) % this->listOfPlayer_.size();
        }
        round_++;
    }
    calculateCombo();
}

void SetProcess::calculateCombo()
{
    float highestValue = 0;
    Player &win = listOfPlayer_[0];
    cout << "Table Deck :" << endl;
    ColorCard::printGroup(this->tableDeck_.getDeck());
    for (auto &p : listOfPlayer_)
    {
        Combo *combo = p.checkPlayerCombo(tableDeck_);
        cout << combo->getValue() << endl;
        cout << "**************************************" << endl;
        cout << "           " << p.getNickname() << "'s cards: " << endl;
        cout << "**************************************" << endl;
        p.printCards();
        cout << "**************************************" << endl;
        cout << "           " << p.getNickname() << "'s combo: " << endl;
        cout << "**************************************" << endl;
        combo->print();
        if (combo->getValue() > highestValue)
        {
            cout << "?" << endl;
            highestValue = combo->getValue();
            win = p;
        }
    }
    cout << "The winner for this round is " << win.getNickname() << endl;
    cout << win.getNickname() << " wins " << points_ << " points!" << endl;
    win.addPoint(points_);
}

void SetProcess::askCommand(vector<string> &allowedCommands, Player &currPlayer)
{
    bool commandSet = false;
    while (!commandSet)
    {
        try
        {
            // if (afterReverse) {
            //     allowedCommands.pop_back();
            //     afterReverse = false;
            // }
            cout << endl
                 << "The allowed commands are : " << endl;
            for (int i = 0; i < allowedCommands.size(); i++)
            {
                cout << "[-] " << allowedCommands[i] << endl;
            }

            cout << "Input command : ";
            string command = inputCommand(allowedCommands, currPlayer);
            for (auto &c : commands_)
            {
                if (c->getCommandName() == command)
                {
                    c->activate(*this);
                    // to do make wait disini supaya bisa dibaca dulu efek dari activate nya
                    commandSet = true;
                    break;
                }
            }
            // if (command != "NEXT" && command != "DOUBLE" && command != "HALF")
            // {
            //     this->listOfPlayer_[currPlayerIdx].setAbilityStatus(false);
            // }
            // if (command != "REVERSE") {
            //     commandSet = true;
            // }
            // else {
            //     afterReverse = true;
            // }
        }
        catch (CommandException &err)
        {
            cout << err.what();
        }
        catch (CommandInactiveException &err)
        {
            cout << err.what();
        }
        catch (StringException &err)
        {
            cout << err.what();
        }
    }
}

string SetProcess::inputCommand(vector<string> &allowedCommands, Player &currPlayer)
{
    string command;
    cin >> command;
    if (cin.fail())
    {
        throw StringException();
    }
    for (auto &c : allowedCommands)
    {
        if (c == command)
        {
            if (currPlayer.getAbilityStatus() || command == "NEXT" || command == "HALF" || command == "DOUBLE")
            {
                return c;
            }
            throw CommandInactiveException();
        }
    }
    throw CommandException();
}

SetProcess::~SetProcess()
{
    for (auto &c : commands_)
    {
        delete c;
    }
    commands_.clear();
}
