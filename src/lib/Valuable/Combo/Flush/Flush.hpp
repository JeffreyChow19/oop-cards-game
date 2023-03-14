#ifndef _FLUSH_HPP_
#define _FLUSH_HPP_

#include "../Combo.hpp"

class Flush : public Combo
{
private:
    vector<ColorCard> flushHand_;

public:
    /**
     * @brief Construct a new Flush object
     *
     */
    Flush(vector<ColorCard> cards);

    /**
     * @brief Destroy the Flush object
     *
     */
    virtual ~Flush();

    /**
     * @brief Get the Value object
     *
     * @return float
     */
    float getValue();
};

#endif