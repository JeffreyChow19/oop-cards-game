#include "../Ability.hpp"
#include "../../../Set/Set.hpp"

class Swap : public Ability
{
public:
    void activate(Set &);
    int inputOption(int);
    string getCommandName();
};