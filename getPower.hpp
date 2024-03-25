/* File: getPower.hpp
 *
 * Author: Jacob Meadows
 *
 * Header file for getPower.cpp
 */
#ifndef GETPOWER_HPP
#define GETPOWER_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

constexpr const char* POWER_SUPPLY_DIR = "/sys/class/power_supply/BAT0/";
constexpr const char* CURRENT_CHARGE_FILE = "charge_now";
constexpr const char* FULL_CHARGE_FILE = "charge_full";

void getFileData(std::string*, const std::string);

#endif /* GETPOWER_HPP */
