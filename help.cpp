#include "sim.h"
#include <iostream>
#include <string>

void help() {
  std::cout << "\033[2J\033[H";
  std::cout << "[?] Rules:\n\n";

  std::cout << R"(Cell Update Rules (Single Cell Processing)

First, evaluate the states of the left and right neighbors. If a cell is at the boundary (edge), assume the missing neighbor has a value of 0.

1. Revival Check
    | Condition: Current cell is dead (HP == 0).
    | Rule: If left >= 3 OR right >= 3, the cell revives with HP = 1. Otherwise, it remains dead (HP = 0).
    | Note: Processing for this cell ends immediately. Skip remaining steps.

2. Equal Competition
    | Condition: Cell is alive (HP > 0) AND left == HP AND right == HP.
    | Effect: Depletion due to competition.
    | Rule: New HP = max(0, HP - 1).

3. Stronger Neighbor Attack
    | Condition: left > HP OR right > HP.
    | Effect: Damage from stronger neighbors.
    | Rule: New HP = max(0, HP - 1).

4. Feeding & Dominance 
    | Condition: HP >= left AND HP >= right (triggers if Steps 2 and 3 do not apply).
    | Effect: Dominance and resource accumulation.
    | Rule: New HP = min(9, HP + 1))"
            << "\n\n";

  std::cout << "Press " << g << "[Enter]" << res << " to return to menu...";

  std::string dummy;
  std::getline(std::cin, dummy);
}