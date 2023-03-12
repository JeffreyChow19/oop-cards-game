#include "../Ability.hpp"

class Switch : public Ability {
    public:
        void activate();
        string getAbilityName();
};