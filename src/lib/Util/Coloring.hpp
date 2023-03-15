#ifndef _COLORING_HPP_
#define _COLORING_HPP_

#include <iostream>
class Coloring{
    public:
        void red(bool bold = false);
        void green(bool bold = false);
        void blue(bool bold = false);
        void yellow(bool bold = false);
        void lgreen(bool bold = false);
        void pink(bool bold = false); 
        void white(bool bold = false);
        void reset();
};

#endif