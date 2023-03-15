#ifndef _ABILITY_HPP_
#define _ABILITY_HPP_

#include "../Command.hpp"
#include "../../Set/Set.hpp"

class Ability : public Command
{
public:
    /**
     * @brief Construct a new Ability object
     *
     */
    Ability();

    /**
     * @brief Activate Ability
     *
     */
    virtual void activate(Set &) = 0;

    virtual string getCommandName() = 0;

    int inputOption(int);
};

#endif