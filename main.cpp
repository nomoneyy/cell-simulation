#include "sim.h"
#include <iostream>
#include <limits>

int main() {
  int c{};

  while (true) {
    std::cout << cls;
    std::cout << "1. Start Simulation\n";
    std::cout << "2. Help\n\n";
    std::cout << r << "0. Exit" << res << "\n\n";
    std::cout << "Choose an option: ";

    if (!(std::cin >> c)) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (c == 0) {
      std::cout << cls;
      return 0;
    } else if (c == 1) {
      sim();
    } else if (c == 2) {
      help();
    }
  }
}