#include "Switch.hpp"

void Switch::activate(Set &set)
{
    vector<Player> &listOfPlayer = set.getListOfPlayers();
    cout << listOfPlayer[set.getCurrPlayerIdx()].getNickname() << " is using SWITCH!\n";
    cout << "Here is your cards: \n";
    int currPlayerIdx = set.getCurrPlayerIdx();
    listOfPlayer[currPlayerIdx].getPlayerDeck()[0].printInfo();
    cout << " && ";
    listOfPlayer[currPlayerIdx].getPlayerDeck()[1].printInfo();
    cout << "\nPlease choose a player to switch your card: \n";
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
            int idxPlayerSwap = opt <= currPlayerIdx ? opt - 1 : opt;
            vector<ColorCard> tempDeck = listOfPlayer[idxPlayerSwap].getPlayerDeck();
            set.getListOfPlayers()[idxPlayerSwap].setPlayerDeck(listOfPlayer[currPlayerIdx].getPlayerDeck());
            set.getListOfPlayers()[currPlayerIdx].setPlayerDeck(tempDeck);
            cout << "Both of " << listOfPlayer[currPlayerIdx].getNickname() << "\'s cards are switched with " << listOfPlayer[idxPlayerSwap].getNickname() << "\'s cards!\n";
            cout << "Here is your cards: \n";
            listOfPlayer[currPlayerIdx].getPlayerDeck()[0].printInfo();
            cout << " && ";
            listOfPlayer[currPlayerIdx].getPlayerDeck()[1].printInfo();
            cout << endl;
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

int Switch::inputOption(int sumOpt)
{
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

string Switch::getCommandName()
{
    return "SWITCH";
}