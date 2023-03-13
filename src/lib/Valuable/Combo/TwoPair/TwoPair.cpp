#include "TwoPair.hpp"
#include <bits/stdc++.h>
using namespace std;
TwoPair::TwoPair(Pair firstPair, Pair secondPair):firstPair_(firstPair), secondPair_(secondPair){}
TwoPair::~TwoPair(){}
float TwoPair::getValue(){
    return 4.14 + max(firstPair_.getValue(), secondPair_.getValue());
}