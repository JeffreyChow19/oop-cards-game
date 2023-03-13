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
        return "File configuration is invalid. Make sure the configuration format is [Color] [Number] and use the valid Color or Number\n";
    }
};

struct CommandException : public exception
{
    const char *what() const throw()
    {
        return "Command input not valid.\nPlease input the right command";
    }
};

struct StringException : public exception
{
    const char *what() const throw()
    {
        return "Input is invalid.\n Try input a valid string";
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

struct FilenameException : public exception{
    const char *what() const throw(){
        return "File not found. Please input the correct file and follow this format [filename].txt\n";
    }
};

#endif