#include "../Ability.hpp"
#include "../../../Set/Set.hpp"

class Quarter : public Ability
{
public:
    void activate(Set &);
    string getCommandName();
};