#include "sim.h"
#include <iostream>
#include <limits>
#include <string>

void sim() {
  const int n{6};
  int val[n]{};
  int nval[n]{};
  int left{};
  int right{};

  std::cout << cls;

  std::cout << "Enter 6 integers " << gr << "(sample: 1 2 3 4 5 6)" << res
            << ": ";

  for (int j{0}; j < 6; j++) {
    std::cin >> val[j];
    nval[j] = val[j];
  }

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  int step = 0;

  while (true) {
    std::cout << cls;
    std::cout << "Step: " << step << "\n\n";

    for (int i{0}; i < 6; ++i) {
      std::cout << val[i] << " ";
    }
    std::cout << "\n\nPress " << g << "[Enter]" << res
              << " for next step (or 'q' to " << r << "exit" << res << "): ";

    std::string input;
    std::getline(std::cin, input);
    if (input == "q" || input == "Q") {
      break;
    }

    for (int j{0}; j < 6; ++j) {
      nval[j] = val[j];
    }

    for (int j{0}; j < 6; ++j) {
      if (j > 0) {
        left = val[j - 1];
      } else {
        left = 0;
      }
      if (j < n - 1) {
        right = val[j + 1];
      } else {
        right = 0;
      }

      if (val[j] == 0) {
        if (left >= 3 || right >= 3) {
          nval[j] = 1;
        } else {
          nval[j] = 0;
        }
      }

      else if (left == val[j] && right == val[j]) {
        nval[j] = val[j] - 1;
      }

      else if (left > val[j] || right > val[j]) {
        nval[j] = val[j] - 1;
      }

      else if (val[j] >= left && val[j] >= right) {
        if (val[j] < 9) {
          nval[j] = val[j] + 1;
        } else {
          nval[j] = 9;
        }
      }
    }

    for (int i{0}; i < 6; ++i) {
      val[i] = nval[i];
    }

    step++;
  }
}