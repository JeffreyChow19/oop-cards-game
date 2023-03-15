#include "Abilityless.hpp"

void Abilityless::activate(Set &set)
{
    Coloring clr;
    vector<Player> &listOfPlayer = set.getListOfPlayers();

    int currPlayerIdx = set.getCurrPlayerIdx();

    bool usedAll = true;
    for (int i = 0;i<listOfPlayer.size(); i++) {
        if (i == currPlayerIdx) {
            continue;
        }
        else if (listOfPlayer[i].getAbilityUse()) {
            usedAll = false;
            break;
        }
    }
    if (usedAll) {
        clr.red();
        cout << "Every player has used their abilities! Oopsie you got your own ability affected to yourself HAHAHAHA :o\n";
        clr.reset();
    }
    else {
        clr.white(true);
        cout << listOfPlayer[currPlayerIdx].getNickname();
        clr.reset();

        cout << " will deactivate the abilities of one of the players" << endl;

        cout << "Choose one player to deactivate the ability: " << endl;
        int no = 1;
        for (int i = 0; i < listOfPlayer.size(); i++)
        {
            if (i == currPlayerIdx)
            {
                continue;
            }
            else
            {
                cout << "[" << no << "] " << listOfPlayer[i].getNickname() << endl;
                no++;
            }
        }

        bool targetSet = false;
        while (!targetSet)
        {
            try
            {
                int opt = inputOption(6);
                int idxPlayerDeact = opt <= currPlayerIdx ? opt - 1 : opt;
                if (!listOfPlayer[idxPlayerDeact].getAbilityUse())
                {
                    clr.white(true);
                    cout << listOfPlayer[idxPlayerDeact].getNickname();
                    clr.reset();
                    cout << " has used their ability before. Your ability were in vain :( \n";
                }
                else
                {
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

    
}

string Abilityless::getCommandName()
{
    return "ABILITYLESS";
}