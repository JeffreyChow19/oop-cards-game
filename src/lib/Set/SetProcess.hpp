#include "Set.hpp"
#include "../Command/Command.hpp"
#include "../Command/Next.hpp"
#include "../Command/Double.hpp"
#include "../Command/Half.hpp"
#include "../Command/Ability/Abilityless/Abilityless.hpp"
#include "../Command/Ability/Quadruple/Quadruple.hpp"
#include "../Command/Ability/Quarter/Quarter.hpp"
#include "../Command/Ability/ReRoll/ReRoll.hpp"
#include "../Command/Ability/Reverse/Reverse.hpp"
#include "../Command/Ability/Swap/Swap.hpp"
#include "../Command/Ability/Switch/Switch.hpp"

class SetProcess : public Set
{
private:
    vector<Command *> commands_;

public:
    /**
     * @brief Construct SetProcess
     *
     * @param listOfPlayer
     * @param currPlayerIdx
     */
    SetProcess(vector<Player> &listOfPlayer, int currPlayerIdx);

    /**
     * @brief try to call inputCommand if succeeds activate the command
     *
     * @param allowedCommands
     */
    void askCommand(vector<string> &allowedCommands, Player &currPlayer);

    /**
     * @brief asks for command input
     *
     * @param allowedCommands
     * @return string
     */
    string inputCommand(vector<string> &allowedCommands, Player &currPlayer);
    ~SetProcess();
    // void (float multiplier);
};