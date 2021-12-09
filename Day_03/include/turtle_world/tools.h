#pragma once
// most  needed libs
#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
// Program related libs
#include "Turtle.h"
using std::cerr;
using std::cout;
using std::endl;
// Parsing
std::vector<int> ParseInput(std::string data_file, int data_points);

int PowerConsumption(const std::string &diagnostic_file,
                     const int &data_points);
int GammaRate(const std::vector<int> &bit_count, int data_points);
int EpsilonaRate(const std::vector<int> &bit_count, int data_points);
