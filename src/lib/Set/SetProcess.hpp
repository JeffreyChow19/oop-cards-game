#include "Set.hpp"

class SetProcess : public Set{
    public :
        void startRound();
        void advanceRound();
        void askCommand(vector<string> allowedCommands);
        string inputCommand(vector<string> allowedCommands);
        // void (float multiplier);
};