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
#include "../Util/Coloring.hpp"
#include "../Exception/Exception.hpp"

#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <unistd.h>

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
    SetProcess(vector<CandyPlayer> &listOfPlayer, int currPlayerIdx);

    /**
     * @brief try to call inputCommand if succeeds activate the command
     *
     * @param allowedCommands
     */
    void askCommand(vector<string> &allowedCommands, CandyPlayer &currCandy);

    /**
     * @brief asks for command input
     *
     * @param allowedCommands
     * @return string
     */
    string inputCommand(vector<string> &allowedCommands, CandyPlayer &currPlayer);
    ~SetProcess();

    void calculateCombo();
};