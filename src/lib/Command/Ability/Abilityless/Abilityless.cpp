#include "Abilityless.hpp"

void Abilityless::activate(Set &set)
{
    bool targetSet = false;
    while (!targetSet)
    {
        try
        {
            getTarget(set.getListOfPlayers());
        }
        catch (NicknameException &e)
        {
            cout << e.what();
        }
    }
    cout << "Enter the nickname of the player to deactivate their ability: " << endl;
}

void Abilityless::getTarget(vector<Player> &listOfPlayer)
{
    cout << "You can deactivate the abilities of one of the players" << endl;
    for (int i = 0; i < listOfPlayer.size(); i++)
    {
        cout << "[" << i + 1 << "] " << listOfPlayer[i].getNickname() << " - " << listOfPlayer[i].getAbility() << endl;
    }
    cout << "Enter the nickname of the player to deactivate their ability: " << endl;
    string nickname;
    cin >> nickname;
    for (auto &p : listOfPlayer)
    {
        if (p.getNickname() == nickname)
        {
            cout << "Successfully deactivated " << p.getNickname() << "'s ability!" << endl;
            p.setAbilityStatus(false);
        }
    }
    throw NicknameException();
}

string Abilityless::getCommandName()
{
    return "ABILITYLESS";
}