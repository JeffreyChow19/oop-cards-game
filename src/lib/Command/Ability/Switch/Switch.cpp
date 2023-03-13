#include "Switch.hpp"

void Switch::activate(Set &set)
{
    vector<Player> listOfPlayer = set.getListOfPlayers();
    cout << listOfPlayer[set.getCurrPlayerIdx()].getNickname() << " melakukan switch!\n";
    cout << "Kartumu sekarang adalah: \n";
    listOfPlayer[set.getCurrPlayerIdx()].getPlayerDeck()[0].printInfo();
    cout << " && ";
    listOfPlayer[set.getCurrPlayerIdx()].getPlayerDeck()[1].printInfo();
    cout << "\nSilahkan pilih pemain yang kartunya ingin Anda tukar: \n";
    int no = 1;
    for (int i = 0; i < listOfPlayer.size(); i++)
    {
        if (i == set.getCurrPlayerIdx())
        {
            continue;
        }
        else
        {
            cout << no << ".  " << listOfPlayer[i].getNickname() << endl;
            no++;
        }
    }
    try {
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
        int idxPlayerSwap = opt <= set.getCurrPlayerIdx() ? opt - 1 : opt;
        vector<ColorCard> tempDeck = listOfPlayer[idxPlayerSwap].getPlayerDeck();
        set.getListOfPlayers()[idxPlayerSwap].setPlayerDeck(listOfPlayer[set.getCurrPlayerIdx()].getPlayerDeck());
        set.getListOfPlayers()[set.getCurrPlayerIdx()].setPlayerDeck(tempDeck);    
        cout << "Kedua kartu "<<listOfPlayer[set.getCurrPlayerIdx()].getNickname() << " telah ditukar dengan " << listOfPlayer[idxPlayerSwap].getNickname() <<"!\n";
        cout << "Kartumu sekarang adalah: \n";
        listOfPlayer[set.getCurrPlayerIdx()].getPlayerDeck()[0].printInfo();
        cout << " && ";
        listOfPlayer[set.getCurrPlayerIdx()].getPlayerDeck()[1].printInfo();
        cout << "\nSilahkan pilih pemain yang kartunya ingin Anda tukar: \n";
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

string Switch::getCommandName()
{
    return "SWITCH";
}