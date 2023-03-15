#include "Abilityless.hpp"

void Abilityless::activate(Set &set)
{
    Coloring clr;
    vector<Player>& listOfPlayer = set.getListOfPlayers();

    int currPlayerIdx = set.getCurrPlayerIdx();

    clr.white(true);
    cout << listOfPlayer[currPlayerIdx].getNickname(); 
    clr.reset();

    cout << " will deactivate the abilities of one of the players" << endl;

    cout << "Choose one player to deactivate the ability: " << endl;
    int no = 1;
    for (int i = 0; i < listOfPlayer.size(); i++)
    {
        if (i == currPlayerIdx) {
            continue;
        }
        else {
            cout << "[" << no << "] " << listOfPlayer[i].getNickname() << " - " << listOfPlayer[i].getAbility() << endl;
            no++;
        }
    }

    bool targetSet = false;
    while (!targetSet)
    {
        try
        {
            int opt = inputOption(6);
            int idxPlayerDeact = opt <= currPlayerIdx ? opt - 1 : opt;;
            if (!listOfPlayer[idxPlayerDeact].getAbilityStatus()) {
                clr.white(true);
                cout << listOfPlayer[idxPlayerDeact].getNickname(); 
                clr.reset();
                cout << " has used their ability before. Your ability were in vain :( \n";
            }
            else {
                cout << "Successfully deactivated ";

                clr.white(true);
                cout << listOfPlayer[idxPlayerDeact].getNickname(); 
                clr.reset();

                cout << "'s ability!" << endl;
                listOfPlayer[idxPlayerDeact].setAbilityStatus(false);
            }
            targetSet = true;
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

int Abilityless::inputOption(int sumOpt) {
    Coloring clr;
    int opt;
    cout << "Input option: ";

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

string Abilityless::getCommandName()
{
    return "ABILITYLESS";
}