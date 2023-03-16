#ifndef _COMBO_HPP_
#define _COMBO_HPP_

#include "../Valuable.hpp"
#include "../Card/ColorCard/ColorCard.hpp"
using namespace std;

class Combo : public Valuable
{
protected:
    static const float HIGH_CARD_MAX;
    static const float PAIR_MAX;
    static const float TWO_PAIR_MAX;
    static const float THREE_KIND_MAX;
    static const float STRAIGHT_MAX;
    static const float FLUSH_MAX;

    static const float FULL_HOUSE_MAX;
    static const float FOUR_KIND_MAX;
    static const float STRAIGHT_FLUSH_MAX;

public:
    /**
     * @brief Construct a new Combo object
     *
     */
    Combo();
    /**
     * @brief Destroy the Combo object
     *
     */
    virtual ~Combo();
    /**
     * @brief virtual function get the value of a Combo
     *
     * @return float
     */
    virtual float getValue() const = 0;
    /**
     * @brief virtual procedure prints the combo
     *
     */
    virtual void print() = 0;

    /**
     * @brief Get the Combo Name object
     * 
     * @return string 
     */
    virtual string getComboName() const = 0;
};

#endif