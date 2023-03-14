#include "TwoPair.hpp"
#include <bits/stdc++.h>
using namespace std;
TwoPair::TwoPair(Pair firstPair, Pair secondPair) : firstPair_(firstPair), secondPair_(secondPair) {}
TwoPair::~TwoPair() {}
float TwoPair::getValue() const
{
    float res = PAIR_MAX; /* maximum pair value */

    res += max(firstPair_.getValue(), secondPair_.getValue());         /* highest pair in the combination */
    res += 0.001 * min(firstPair_.getValue(), secondPair_.getValue()); /* 0.001 * lowest pair in the combination */

    return res;
}

void TwoPair::print()
{
    this->firstPair_.print();
    this->secondPair_.print();
}