<div align="center">

# 🧬 Discrete 1D Cellular Automaton

**A lightweight, interactive terminal-based simulation of spatial resource competition and population dynamics.**

[![C++ Standard](https://img.shields.io/badge/C%2B%2B-17%2F20-00599C?style=flat-square&logo=c%2B%2B&logoColor=white)](https://en.wikipedia.org/wiki/C%2B%2B)
[![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20macOS%20%7C%20Windows-555555?style=flat-square)]()
[![License](https://img.shields.io/badge/License-MIT-brightgreen?style=flat-square)](LICENSE)

[Overview](#-overview) • [Core Mechanics](#-core-mechanics) • [Getting Started](#-getting-started) • [Project Structure](#-project-structure) • [License](#-license)

</div>

---

## 📌 Overview

This project implements a deterministic **1D Cellular Automaton** CLI application in modern C++. It models ecological dynamics, dominance, and resource competition across a discrete grid of 6 interacting cells.

Each cell has a discrete state value (HP / Energy) bounded in the range $[0, 9]$. State updates occur synchronously on every discrete time step based on strictly defined deterministic neighborhood rules.
Step: 4
[ 0 ] [ 3 ] [ 8 ] [ 9 ] [ 2 ] [ 0 ]
Press [Enter] for next step (or 'q' to exit):
code
Code
---

## ⚙️ Core Mechanics & Transition Rules

The grid consists of $N = 6$ cells. At each tick, the state of cell $i$ is synchronously updated to $HP_{next}$ based on its current value ($HP$) and its immediate spatial neighbors ($L = \text{val}[i-1]$ and $R = \text{val}[i+1]$).

> **Boundary Condition:** Zero-flux / Fixed boundary ($L = 0$ for $i=0$, and $R = 0$ for $i=N-1$).

### Rule Priority Matrix

| # | Phase / Rule | Condition | Mechanism | State Transition |
| :--- | :--- | :--- | :--- | :--- |
| **1** | **Revival** | $HP = 0 \land (L \ge 3 \lor R \ge 3)$ | Sufficient external energy restores life | $HP_{next} = 1$ |
| — | *Inertia* | $HP = 0 \land L < 3 \land R < 3$ | Remains dead | $HP_{next} = 0$ |
| **2** | **Equal Competition** | $HP > 0 \land L = HP \land R = HP$ | Mutual resource depletion under equal pressure | $HP_{next} = \max(0, HP - 1)$ |
| **3** | **Predation / Damage** | $HP > 0 \land (L > HP \lor R > HP)$ | Cell is overwhelmed by a dominant neighbor | $HP_{next} = \max(0, HP - 1)$ |
| **4** | **Dominance & Growth** | $HP > 0 \land HP \ge L \land HP \ge R$ | Local dominance enables energy accumulation | $HP_{next} = \min(9, HP + 1)$ |

---

## 🚀 Getting Started

### Prerequisites

* Any modern C++ compiler supporting **C++17** or higher (`g++`, `clang++`, or `MSVC`).
* ANSI-compatible terminal (Linux/macOS native terminal, Windows Terminal).

### Build & Run

1. **Clone the repository:**
   ```bash
   git clone https://github.com/your-username/cellular-automaton-1d.git
   cd cellular-automaton-1d
Compile with optimization:
code
Bash
# Using GCC / G++
g++ -std=c++17 -O2 main.cpp sim.cpp help.cpp -o sim

# Or using Clang
clang++ -std=c++17 -O2 main.cpp sim.cpp help.cpp -o sim
Run the executable:
code
Bash
./sim
(On Windows, you can compile via g++ -std=c++17 main.cpp sim.cpp help.cpp -o sim.exe and run sim.exe).

# 🎮 Usage Example
Launch the program and select option 1 to start the simulation.
Provide an initial configuration of 6 integers (e.g., 1 2 3 4 5 6 or 0 4 0 0 5 1).
Press Enter to step through iterations one by one.
Press q followed by Enter at any time to break the simulation and return to the main menu.

# 📁 Project Structure
code
Text
.
├── sim.h        // Global declarations, ANSI color constants, and function prototypes
├── main.cpp     // CLI entry point and menu event loop
├── sim.cpp      // Synchronous simulation engine and state transition logic
├── help.cpp     // Interactive documentation and manual renderer
└── README.md    // Project documentation

# 🛠 Architectural Highlights
Pure Standard C++: Zero external dependencies; uses standard I/O streams and memory bounds.
Double Buffering: Employs an auxiliary buffer (nval[]) during updates to avoid step-order race conditions in cellular state evaluations.
ANSI Terminal Escapes: Clean terminal rendering and color coding without heavy third-party UI libraries like ncurses.

# 📄 License
This project is open-source and available under the MIT License.
