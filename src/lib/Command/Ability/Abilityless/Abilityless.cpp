#include "Abilityless.hpp"

void Abilityless::activate(Set &set)
{
    vector<Player>& listOfPlayer = set.getListOfPlayers();
    int currPlayerIdx = set.getCurrPlayerIdx();
    cout << listOfPlayer[currPlayerIdx].getNickname() << " will deactivate the abilities of one of the players" << endl;
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
                cout << listOfPlayer[idxPlayerDeact].getNickname() << " has used their ability before. Your ability were in vain :( \n";
            }
            else {
                cout << "Successfully deactivated " << listOfPlayer[idxPlayerDeact].getNickname() << "'s ability!" << endl;
                listOfPlayer[idxPlayerDeact].setAbilityStatus(false);
            }
            targetSet = true;
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

// void Abilityless::getTarget(vector<Player> &listOfPlayer)
// {
//     cout << "You can deactivate the abilities of one of the players" << endl;
//     for (int i = 0; i < listOfPlayer.size(); i++)
//     {
//         cout << "[" << i + 1 << "] " << listOfPlayer[i].getNickname() << " - " << listOfPlayer[i].getAbility() << endl;
//     }
//     cout << "Enter the nickname of the player to deactivate their ability: " << endl;
//     string nickname;
//     bool found = false;
//     cin >> nickname;
//     for (auto &p : listOfPlayer)
//     {
//         if (p.getNickname() == nickname)
//         {
//             cout << "Successfully deactivated " << p.getNickname() << "'s ability!" << endl;
//             p.setAbilityStatus(false);
//             found = true;
//         }
//     }
//     if (!found) {
//         throw NicknameException();
//     }
// }

int Abilityless::inputOption(int sumOpt) {
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

string Abilityless::getCommandName()
{
    return "ABILITYLESS";
}