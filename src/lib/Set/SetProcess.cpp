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

        if (this->round_ != 6)
        {
            // keep tracker of player
            for (auto &p : listOfPlayer_)
            {
                p.setHasPlayed(false);
            }
            currPlayerIdx = firstPlayerIdx_;
            printSetInfo();
            int playerMoved = 0;
            while (playerMoved < listOfPlayer_.size())
            {
                Player &currPlayer = listOfPlayer_[currPlayerIdx];
                if (!currPlayer.getHasPlayed())
                {
                    cout << "It's " << currPlayer.getNickname() << "'s turn" << endl
                         << endl;
                    if (this->round_ != 1)
                    {
                        allowedCommands.push_back(currPlayer.getAbility());
                    }
                    askCommand(allowedCommands, currPlayer);
                    // printSetInfo();
                    if (this->round_ != 1)
                    {
                        allowedCommands.pop_back();
                    }
                    currPlayer.setHasPlayed(true);
                }
                currPlayerIdx = (currPlayerIdx + 1) % listOfPlayer_.size();
                playerMoved++;
            }

            if (this->round_ == 1)
            {
                cout << "Shuffling abilities... " << endl;
                random_shuffle(abilities.begin(), abilities.end());
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
}

void SetProcess::askCommand(vector<string> &allowedCommands, Player &currPlayer)
{
    bool commandSet = false;
    while (!commandSet)
    {
        try
        {
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
                    break;
                }
            }
            commandSet = true;
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
