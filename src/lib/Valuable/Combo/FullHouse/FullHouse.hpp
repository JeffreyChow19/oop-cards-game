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
     * @brief Construct a new FullHouse object
     *
     * @param deck
     */
    FullHouse(vector<ColorCard> deck);

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