#include "Swap.hpp"

void Swap::activate(Set &set)
{
    vector<Player>& listOfPlayer = set.getListOfPlayers();
    int currPlayerIdx = set.getCurrPlayerIdx();
    cout << listOfPlayer[currPlayerIdx].getNickname() << " is using SWAPCARD!\n";
    cout << "Please choose a player to swap their card: \n";
    int no = 1;
    for (int i = 0; i < listOfPlayer.size(); i++)
    {
        if (i == currPlayerIdx)
        {
            continue;
        }
        else
        {
            cout << "[" << no << "]  ";
            listOfPlayer[i].print();
            no++;
        }
    }
    bool success = false;
    while (!success) {
        try
        {
            int opt = inputOption(6);
            int idxFirstPlayer = opt <= currPlayerIdx ? opt - 1 : opt;
            cout << "Please choose a player to swap their card: \n";
            no = 1;
            for (int i = 0; i < listOfPlayer.size(); i++)
            {
                if (i == currPlayerIdx || i == idxFirstPlayer)
                {
                    continue;
                }
                else
                {
                    cout << "[" << no << "]  ";
                    listOfPlayer[i].print();
                    no++;
                }
            }
            opt = inputOption(5);
            int idxMax = max(idxFirstPlayer, currPlayerIdx);
            int idxMin = min(idxFirstPlayer, currPlayerIdx);
            int idxSecondPlayer = opt <= idxMin ? opt - 1 : opt >= idxMax ? opt + 1 : opt;
            cout << "Please choose right/left for " << listOfPlayer[idxFirstPlayer].getNickname() << "\'s cards: \n";
            cout << "[1] Right\n[2] Left\n";
            opt = inputOption(2);
            int idxCardFirstPlayer = 2 - opt;
            cout << "Please choose right/left for " << listOfPlayer[idxSecondPlayer].getNickname() << "\'s cards: \n";
            cout << "[1] Right\n[2] Left\n";
            opt = inputOption(2);
            int idxCardSecondPlayer = 2 - opt;
            ColorCard tempFirst = listOfPlayer[idxFirstPlayer].getPlayerDeck()[idxCardFirstPlayer];
            ColorCard tempSecond = listOfPlayer[idxSecondPlayer].getPlayerDeck()[idxCardSecondPlayer];
            set.getListOfPlayers()[idxFirstPlayer].removePlayerCard(tempFirst);
            set.getListOfPlayers()[idxFirstPlayer].addPlayerCard(tempSecond);
            set.getListOfPlayers()[idxSecondPlayer].removePlayerCard(tempSecond);
            set.getListOfPlayers()[idxSecondPlayer].addPlayerCard(tempFirst);
            success = true;
        }
        catch (IntegerException &e)
        {
            cout << e.what();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
        catch (OptionException &e)
        {
            cout << e.what();
        }
    }
    
}

int Swap::inputOption(int sumOpt) {
    int opt;
    cout << "> ";
    cin >> opt;
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

string Swap::getCommandName()
{
    return "SWAP";
}