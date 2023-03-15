#include "Command.hpp"

using namespace std;

class Half : public Command
{
public:
    void activate(Set &set);
    string getCommandName();
};