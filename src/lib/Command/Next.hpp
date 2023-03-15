#include "Command.hpp"
#include "../Set/Set.hpp"

using namespace std;

class Next : public Command
{
public:
    Next();
    void activate(Set &set);
    string getCommandName();
};