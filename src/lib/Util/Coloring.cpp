#include "Coloring.hpp"
using namespace std;

void Coloring::red(bool bold)
{
  if (bold){
    cout << "\033[1;31m";
  }
  else{
    cout << "\033[0;31m";
  }
}

void Coloring::green(bool bold)
{
  if (bold) {
    cout << "\033[1;32m";
  }
  else{
    cout << "\033[0;32m";
  }
}

void Coloring::blue(bool bold)
{
  if (bold){
    cout << "\033[1;34m";
  }
  else{
    cout << "\033[0;34m";
  }
}

void Coloring::yellow(bool bold)
{
  if (bold){
    cout << "\033[1;33m";
  }
  else{
    cout << "\033[0;33m";
  }
}

void Coloring::lgreen(bool bold){
  if (bold){
    cout << "\033[1;92m";
  }
  else{
    cout << "\033[0;92m";
  }
}

void Coloring::pink(bool bold){
  if (bold){
    cout << "\033[1;95m";
  }
  else{
    cout << "\033[0;95m";
  }
}

void Coloring::white(bool bold){
   if (bold){
    cout << "\033[1;97m";
  }
  else{
    cout << "\033[0;97m";
  }
}

void Coloring::reset()
{
    cout << "\033[0m";
}