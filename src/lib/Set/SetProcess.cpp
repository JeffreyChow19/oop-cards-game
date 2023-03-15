#include "SetProcess.hpp"

using namespace std;

SetProcess::SetProcess(vector<Player> &listOfPlayer, int firstPlayerIdx) : Set(listOfPlayer, firstPlayerIdx)
{
    Coloring clr;

    // Initialize commands and abilities
    vector<string> allowedCommands = {"NEXT", "HALF", "DOUBLE"};
    vector<string> abilities = {"RE-ROLL", "SWITCH", "SWAP", "QUARTER", "REVERSE", "QUADRUPLE", "ABILITYLESS"};
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
        clr.cyan();
        cout << "\n**************************************" << endl;
        cout << "          Welcome to round " << this->round_ << endl;
        cout << "**************************************" << endl
             << endl;
        clr.reset();

        // keep tracker of player
        for (auto &p : listOfPlayer_)
        {
            p.setHasPlayed(false);
            if (round_ != 1)
            {
                p.setAbilityStatus(true);
            }
        }

        if (this->round_ != 6)
        {
            this->tableDeck_.addCard(this->mainDeck_);

            clr.white(true);
            cout << "Table Deck :" << endl;
            clr.reset();

            ColorCard::printGroup(this->tableDeck_.getDeck());

            sleep(1);

            currPlayerIdx = firstPlayerIdx_;

            int playerMoved = 0;
            while (playerMoved < listOfPlayer_.size())
            {
                allowedCommands = {"NEXT", "HALF", "DOUBLE"};

                Player &currPlayer = listOfPlayer_[currPlayerIdx];
                if (!currPlayer.getHasPlayed())
                {
                    cout << endl;
                    printSetInfo();

                    sleep(1);

                    cout << endl
                         << "It's ";

                    clr.white(true);
                    cout << currPlayer.getNickname();
                    clr.reset();

                    cout << "'s turn" << endl
                         << endl;

                    clr.white(true);
                    cout << "Table cards : " << endl;
                    clr.reset();

                    ColorCard::printGroup(this->tableDeck_.getDeck());

                    clr.white(true);
                    cout << "\nPlayer's cards : " << endl;
                    clr.reset();

                    currPlayer.printCards();

                    if (this->round_ != 1 && currPlayer.getAbilityStatus())
                    {
                        allowedCommands.push_back(currPlayer.getAbility());
                    }
                    askCommand(allowedCommands, currPlayer);
                    listOfPlayer_[currPlayerIdx].setHasPlayed(true);
                    playerMoved++;
                }
                currPlayerIdx = (currPlayerIdx + 1) % listOfPlayer_.size();
            }

            if (this->round_ == 1)
            {
                clr.red(true);
                cout << "\n=== End of round ";
                cout << this->round_;
                cout << " ===" << endl
                     << endl;
                clr.reset();

                sleep(0.5);

                clr.lgreen(true);
                cout << "Shuffling abilities... " << endl
                     << endl;
                clr.reset();

                sleep(1);

                // Shuffle the abilities
                srand(time(NULL));
                random_shuffle(abilities.begin(), abilities.end());
                for (int i = 0; i < this->listOfPlayer_.size(); i++)
                {
                    clr.blue(true);
                    cout << listOfPlayer_[i].getNickname();
                    clr.reset();

                    cout << " got ";

                    clr.yellow(true);
                    cout << abilities[i];
                    clr.reset();

                    cout << " ability" << endl;

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
    Coloring clr;

    float highestValue = 0;
    Player *win = &listOfPlayer_[0];

    clr.white(true);
    cout << "Table Deck :" << endl;
    clr.reset();

    ColorCard::printGroup(this->tableDeck_.getDeck());

    for (auto &p : listOfPlayer_)
    {
        Combo *combo = p.checkPlayerCombo(tableDeck_);

        clr.lgreen(true);
        cout << "\n===============================================" << endl;

        clr.white(true);
        cout << "               " << p.getNickname() << "'s" << endl;

        clr.blue(true);
        cout << "Cards :" << endl;
        clr.reset();

        p.printCards();

        clr.blue(true);
        cout << "\nCombo :";
        cout << combo->getComboName() << endl;
        clr.reset();

        combo->print();

        clr.lgreen(true);
        cout << "\n===============================================" << endl;
        clr.reset();

        if (combo->getValue() > highestValue)
        {
            highestValue = combo->getValue();
            win = &p;
        }
        delete combo;
    }

    clr.yellow(true);
    cout << "\nThe winner for this round is ";

    clr.blue(true);
    cout << win->getNickname() << endl;

    cout << win->getNickname();

    clr.yellow(true);
    cout << " wins ";

    clr.blue(true);
    cout << points_;

    clr.yellow(true);
    cout << " points!" << endl;
    clr.reset();

    win->addPoint(points_);
}

void SetProcess::askCommand(vector<string> &allowedCommands, Player &currPlayer)
{
    Coloring clr;

    bool commandSet = false;
    bool afterReverse = false;
    while (!commandSet)
    {
        try
        {
            if (afterReverse)
            {
                allowedCommands.pop_back();
                afterReverse = false;
            }

            clr.white(true);
            cout << endl
                 << "The allowed commands are : " << endl;
            clr.reset();

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
                    commandSet = true;
                    break;
                }
            }
            if (command != "NEXT" && command != "DOUBLE" && command != "HALF")
            {
                this->listOfPlayer_[currPlayerIdx].setAbilityStatus(false);
            }
            if (command != "REVERSE")
            {
                commandSet = true;
            }
            else
            {
                commandSet = false;
                afterReverse = true;
            }
        }
        catch (CommandException &err)
        {
            clr.red();
            cout << err.what();
            clr.reset();
        }
        catch (CommandInactiveException &err)
        {
            clr.red();
            cout << err.what();
            clr.reset();
        }
        catch (StringException &err)
        {
            clr.red();
            cout << err.what();
            clr.reset();
        }
    }
}

string SetProcess::inputCommand(vector<string> &allowedCommands, Player &currPlayer)
{
    Coloring clr;

    string command;

    clr.lgreen();
    cin >> command;
    clr.reset();

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
