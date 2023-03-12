#include "Command.hpp"
#include <bits/stdc++.h>

using namespace std;

class Half : public Command
{
public:
    void activate(Set &set);
    string getCommandName();
};