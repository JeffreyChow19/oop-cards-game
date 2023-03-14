#ifndef _CARD_HPP_
#define _CARD_HPP_

class Card
{
protected:
    int value_;

public:
    Card();
    Card(int value);
    virtual float getValue() const = 0;
    ~Card();
    static bool compareByValue(const Card &, const Card &);
};

#endif