#include "../Ability.hpp"
#include "../../Set/Set.hpp"

class Reverse : public Ability
{
public:
    void activate(Set &);
    string getCommandName();
};