#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include <bits/stdc++.h>
using namespace std;

struct NumericException : public exception
{
    const char *what() const throw()
    {
        return "Numeric input not valid.\nPlease input only integers.";
    }
};

struct TextFileException : public exception
{
    const char *what() const throw()
    {
        return "TextFile input not valid.\nPlease input correct txt file.";
    }
};

struct CommandException : public exception
{
    const char *what() const throw()
    {
        return "Command input not valid.\nPlease input the right command";
    }
};

struct CommandInactiveException : public exception
{
    const char *what() const throw()
    {
        return "Ability was deactivated by another player.\n";
    }
};

struct StringException : public exception
{
    const char *what() const throw()
    {
        return "Input is invalid. Try input a valid string\n";
    }
};

struct IntegerException : public exception
{
    const char *what() const throw()
    {
        return "Input is invalid. Try input a valid integer\n";
    }
};

struct OptionException : public exception
{
    const char *what() const throw()
    {
        return "Option is not found. Try input an available option \n";
    }
};

struct NicknameException : public exception
{
    const char *what() const throw()
    {
        return "No player with that nickname is found.\n";
    }
};

struct PointException : public exception
{
    const char *what() const throw()
    {
        return "The set point is already 1 so it cant be changed.\n";
    }
};

#endif