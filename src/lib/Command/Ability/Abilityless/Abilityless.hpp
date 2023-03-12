#include "../Ability.hpp"
#include "../../../Set/Set.hpp"

class Abilityless : public Ability
{
public:
    void activate(Set &);
    string getCommandName();
    void getTarget(vector<Player> &listOfPlayer);
};