#include "Combo.hpp"
#include <bits/stdc++.h>
using namespace std;

const float Combo::HIGH_CARD_MAX = 1.39;
const float Combo::PAIR_MAX = 4.14;
const float Combo::TWO_PAIR_MAX = 8.3;
const float Combo::THREE_KIND_MAX = 11;
const float Combo::STRAIGHT_MAX = 12.5;
const float Combo::FLUSH_MAX = 17.6;

/* chore: FULLHOUSE and above max */
const float Combo::FULL_HOUSE_MAX = 0;
const float Combo::FOUR_KIND_MAX = 0;
const float Combo::STRAIGHT_FLUSH_MAX = 0;

Combo::Combo()
{
}

Combo::~Combo() {}
