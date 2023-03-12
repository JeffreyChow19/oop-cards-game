#ifndef _VALUABLE_HPP_
#define _VALUABLE_HPP_

#include <bits/stdc++.h>

class Valuable {
    public:
        virtual ~Valuable();
        virtual float getValue() = 0;
};

#endif