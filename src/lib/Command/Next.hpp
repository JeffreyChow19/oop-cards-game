#include "Command.hpp"
#include "../Set/Set.hpp"
#include <bits/stdc++.h>

using namespace std;

class Next : public Command
{
public:
    Next();
    void activate(Set &set);
    string getCommandName();
};