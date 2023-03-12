#include "../Ability.hpp"
#include "../../Set/Set.hpp"

class ReRoll : public Ability
{
public:
    void activate(Set &);
    string getCommandName();
};