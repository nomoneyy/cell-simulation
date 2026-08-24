#ifndef SIM_H
#define SIM_H

#include <string>

inline const std::string res = "\033[0m";
inline const std::string r = "\033[1;31m";
inline const std::string g = "\033[1;32m";
inline const std::string gr = "\033[1;90m";
inline const std::string cls = "\033[2J\033[H";

void sim();

void help();

#endif