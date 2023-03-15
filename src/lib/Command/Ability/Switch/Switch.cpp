#include "Switch.hpp"

void Switch::activate(Set &set)
{
    Coloring clr;

    vector<CandyPlayer> &listOfPlayer = set.getListOfPlayers();

    clr.white();
    cout << listOfPlayer[set.getCurrPlayerIdx()].getNickname();
    clr.reset();
    
    cout << " is using SWITCH!\n";
    cout << "Here is your cards: \n";
    int currPlayerIdx = set.getCurrPlayerIdx();
    ColorCard::printGroup(listOfPlayer[currPlayerIdx].getPlayerDeck());
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

            cout << "Both of "; 

            clr.white(true);
            cout << listOfPlayer[currPlayerIdx].getNickname(); 
            clr.reset();

            cout << "\'s cards are switched with "; 

            clr.white(true);
            cout << listOfPlayer[idxPlayerSwap].getNickname(); 
            clr.reset();

            cout << "\'s cards!\n";

            cout << "Here is your cards: \n";
            ColorCard::printGroup(listOfPlayer[currPlayerIdx].getPlayerDeck());
            cout << endl;
            success = true;
        }
        catch (IntegerException &e)
        {
            clr.red();
            cout << e.what();
            clr.reset();
            
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
        catch (OptionException &e)
        {
            clr.red();
            cout << e.what();
            clr.reset();
        }
    }
}

int Switch::inputOption(int sumOpt)
{
    Coloring clr;

    int opt;

    cout << "Input option ";

    clr.lgreen();
    cin >> opt;
    clr.reset();

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