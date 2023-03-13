#ifndef _CARD_HPP_
#define _CARD_HPP_

class Card
{
protected:
    int value_;

public:
    Card();
    Card(int value);
    virtual double getValue() const = 0;
    ~Card();
    friend bool compareByValue(const Card &, const Card &);
};

#endif