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
int OxGenRating(const std::string &diagnostic_file, int bit_length);
int CO2GenRating(const std::string &diagnostic_file, int bit_length);
std::unordered_map<int, std::string>
ParseToMap(const std::string &diagnostic_file);
int OnOffBitCount(const int &bit_on,
                  const std::unordered_map<int, std::string> &map,
                  const int &pos);

int ReduceMap(std::unordered_map<int, std::string> &map, const int &pos,
              const int &remove_val);