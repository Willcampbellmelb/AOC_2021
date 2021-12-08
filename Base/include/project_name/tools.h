#pragma once
// most  needed libs
#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>
using std::cerr;
using std::cout;
using std::endl;
// parsing single file int
std::vector<int> ParseInput(std::string data_file, int data_points);