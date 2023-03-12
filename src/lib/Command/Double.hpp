#include "Command.hpp"
#include <bits/stdc++.h>

using namespace std;

class Double : public Command
{
public:
    void activate(Set &set);
    string getCommandName();
};