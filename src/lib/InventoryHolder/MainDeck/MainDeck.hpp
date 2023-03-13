#ifndef _MAIN_DECK_HPP_
#define _MAIN_DECK_HPP_

#include <bits/stdc++.h>
#include "../InventoryHolder.hpp"
#include "../../Exception/Exception.hpp"
#include "../../Valuable/Card/ColorCard/ColorCard.hpp"

using namespace std;

class MainDeck : public InventoryHolder<ColorCard>
{
    private:
    public:
        /**
         * @brief Construct a new Main Deck object
         *
         */
        MainDeck();
        void randomizeCard();
        void readCard();
        ColorCard getFromMainDeck();
        MainDeck& operator=(const MainDeck& other);
        void printDeck();
        Color stringToColor(const string& color);
};

#endif