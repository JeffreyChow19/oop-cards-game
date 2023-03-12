#include "../Ability.hpp"
#include "../../Set/Set.hpp"

class Switch : public Ability
{
public:
    void activate(Set &);
    string getCommandName();
};