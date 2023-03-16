#ifndef _FULLHOUSE_HPP_
#define _FULLHOUSE_HPP_

#include "../Combo.hpp"
#include "../Pair/Pair.hpp"
#include "../ThreeOfAKind/ThreeOfAKind.hpp"

class FullHouse : public Combo
{
private:
    Pair pair_;
    ThreeOfAKind tris_;

public:
    /**
     * @brief Construct a new Full House object
     * 
     * @param threes 
     * @param twos 
     */
    FullHouse(vector<ColorCard> threes, vector<ColorCard> twos);

    /**
     * @brief Destroy FullHouse object
     *
     */
    virtual ~FullHouse();

    /**
     * @brief Get the Value object
     *
     * @return float
     */
    float getValue() const;

    void print();

    string getComboName() const;
};

#endif