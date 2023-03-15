#ifndef _MAIN_DECK_HPP_
#define _MAIN_DECK_HPP_

#include "../InventoryHolder.hpp"
#include "../../Exception/Exception.hpp"
#include "../../Valuable/Card/ColorCard/ColorCard.hpp"
#include "../../Util/Coloring.hpp"

#include <limits>
#include <random>
#include <fstream>
#include <sstream>
#include <ctime>

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
    ~MainDeck();
    void fillDeck();
    void randomizeCard();
    void readCard();
    ColorCard getFromMainDeck();
    void addCard(ColorCard card);
    MainDeck &
    operator=(const MainDeck &other);
    void print();
    Color stringToColor(const string &color);
};

#endif