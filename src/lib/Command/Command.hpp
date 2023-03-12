#ifndef _COMMAND_HPP_
#define _COMMAND_HPP_

#include "../Set/Set.hpp"
#include <bits/stdc++.h>

using namespace std;

class Command
{
public:
    Command();
    virtual void activate(Set&) = 0;

    virtual string getCommandName() = 0;
};

#endif