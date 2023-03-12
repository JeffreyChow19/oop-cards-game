#include "../Ability.hpp"
#include "../../Set/Set.hpp"

class Quadruple : public Ability
{
public:
    void activate(Set &);
    string getCommandName();
};