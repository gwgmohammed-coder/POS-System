#include "../Headers/Helpers.h"
#include <iostream>

// Keep input handling in one place so the menus can reuse it.
double input(std::string text)
{
  double op;
  while (true) {
    std::cout << text;
    std::cin >> op;
    if(std::cin.good())
    {
      std::cin.ignore(20, '\n');
      return op;
    }
    std::cin.clear();
    std::cout <<"\nIncorrect input entered. Try Again.\n";
    std::cin.ignore(20, '\n');
  }
}
