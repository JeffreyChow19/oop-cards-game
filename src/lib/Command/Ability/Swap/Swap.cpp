#include "Swap.hpp"

void Swap::activate(Set &set)
{
    vector<Player>& listOfPlayer = set.getListOfPlayers();
    cout << listOfPlayer[set.getCurrPlayerIdx()].getNickname() << " melakukan SWAPCARD\n";
    cout << "Silahkan pilih pemain yang kartunya ingin Anda tukar: ";
    int no = 1;
    for (int i = 0; i < listOfPlayer.size(); i++)
    {
        if (i == set.getCurrPlayerIdx())
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
    try
    {
        cout << "> ";
        int opt;
        cin >> opt;
        if (cin.fail())
        {
            throw IntegerException();
        }
        else if (opt < 1 || opt > 6)
        {
            throw OptionException();
        }
        int idxFirstPlayer = opt <= set.getCurrPlayerIdx() ? opt - 1 : opt;
        cout << "Silahkan pilih pemain yang kartunya ingin Anda tukar: ";
        no = 1;
        for (int i = 0; i < listOfPlayer.size(); i++)
        {
            if (i == set.getCurrPlayerIdx() || i == idxFirstPlayer)
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
        cout << "> ";
        cin >> opt;
        if (cin.fail())
        {
            throw IntegerException();
        }
        else if (opt < 1 || opt > 5)
        {
            throw OptionException();
        }
        int idxSecondPlayer = opt <= set.getCurrPlayerIdx() ? opt - 1 : opt;
        cout << "Silahkan pilih  kartu kanan/kiri " << listOfPlayer[idxFirstPlayer].getNickname() << ": \n";
        cout << "1. Kanan\n 2. Kiri\n> ";
        cin >> opt;
        if (cin.fail())
        {
            throw IntegerException();
        }
        else if (opt < 1 || opt > 2)
        {
            throw OptionException();
        }
        int idxCardFirstPlayer = 2 - opt;
        cout << "Silahkan pilih  kartu kanan/kiri " << listOfPlayer[idxSecondPlayer].getNickname() << ": \n";
        cout << "1. Kanan\n 2. Kiri\n> ";
        cin >> opt;
        if (cin.fail())
        {
            throw IntegerException();
        }
        else if (opt < 1 || opt > 2)
        {
            throw OptionException();
        }
        int idxCardSecondPlayer = 2 - opt;
        ColorCard tempFirst = listOfPlayer[idxFirstPlayer].getPlayerDeck()[idxCardFirstPlayer];
        ColorCard tempSecond = listOfPlayer[idxSecondPlayer].getPlayerDeck()[idxCardSecondPlayer];
        set.getListOfPlayers()[idxFirstPlayer].removePlayerCard(tempFirst);
        set.getListOfPlayers()[idxFirstPlayer].addPlayerCard(tempSecond);
        set.getListOfPlayers()[idxSecondPlayer].removePlayerCard(tempSecond);
        set.getListOfPlayers()[idxSecondPlayer].addPlayerCard(tempFirst);
    }
    catch (IntegerException &e)
    {
        e.what();
    }
    catch (OptionException &e)
    {
        e.what();
    }
}

string Swap::getCommandName()
{
    return "SWAP";
}