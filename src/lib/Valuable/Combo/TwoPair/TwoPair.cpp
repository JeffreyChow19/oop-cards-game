#include "TwoPair.hpp"
#include <bits/stdc++.h>
using namespace std;
TwoPair::TwoPair(Pair firstPair, Pair secondPair):firstPair_(firstPair), secondPair_(secondPair){}
TwoPair::~TwoPair(){}
float TwoPair::getValue(){
    float res = 4.14;   /* maximum pair value */

    res += max(firstPair_.getValue(), secondPair_.getValue());       /* highest pair in the combination */
    
    return res;
}