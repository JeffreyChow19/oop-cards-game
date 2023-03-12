#include "Command.hpp"
#include <bits/stdc++.h>

using namespace std;

class Next : public Command
{
public:
    void activate(Set &set);
    string getCommandName();
};