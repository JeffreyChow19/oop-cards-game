#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include <bits/stdc++.h>
using namespace std;

struct NumericException : public exception {
    const char* what() const throw() {
        return "Numeric input not valid.\nPlease input only integers.";
    }
};

struct TextFileException : public exception {
    const char* what() const throw() {
        return "TextFile input not valid.\nPlease input correct txt file.";
    }
};

struct CommandException : public exception {
    const char* what() const throw() {
        return "Command input not valid.\nPlease input the right command";
    }
};


#endif