#include "../Ability.hpp"
#include "../../../Set/Set.hpp"

class Swap : public Ability
{
public:
    void activate(Set &);
    string getCommandName();
};