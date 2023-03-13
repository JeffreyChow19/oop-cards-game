#include "SetProcess.hpp"
#include "../Exception/Exception.hpp"

SetProcess::SetProcess(vector<Player> &listOfPlayer, int firstPlayerIdx) : Set(listOfPlayer, firstPlayerIdx)
{
    srand(unsigned(time(0)));
    vector<string> allowedCommands = {"NEXT", "HALF", "DOUBLE"};
    vector<string> abilities = {"RE-ROLL", "REVERSE", "SWITCH", "SWAP", "QUARTER", "QUADRUPLE", "ABILITYLESS"};
    while (this->round_ != 6)
    {
        cout << "Welcome to round " << this->round_ << endl
             << endl;
        int playerMoved = 0;
        for (auto &p : listOfPlayer_)
        {
            p.setHasPlayed(false);
        }
        // int currPlayerIdx = firstPlayerIdx_;
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
                askCommand(allowedCommands);
                printSetInfo();
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
        round_++;
    }
}

void SetProcess::askCommand(vector<string> &allowedCommands)
{
    vector<Command *> commands = {new Next(), new Double(), new Half(), new Abilityless(), new Quadruple(), new Quarter(), new ReRoll(), new Reverse(), new Swap(), new Switch()};
    bool commandSet = false;
    while (!commandSet)
    {
        try
        {
            cout << "The allowed commands are : " << endl;
            for (int i = 0; i < allowedCommands.size(); i++)
            {
                cout << "[" << i + 1 << "] " << allowedCommands[i] << endl;
            }
            cout << "Input command : ";
            string command = inputCommand(allowedCommands);
            for (auto &c : commands)
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
        catch (StringException &err)
        {
            cout << err.what();
        }
    }
}

string SetProcess::inputCommand(vector<string> &allowedCommands)
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
            return c;
        }
    }
    throw CommandException();
}

SetProcess::~SetProcess()
{
}
// void SetProcess::(float multiplier)
// {
//     this->points_ *= multiplier;
// }