#include "Command.hpp"

using namespace std;

class Double : public Command
{
public:
    void activate(Set &set);
    string getCommandName();
};