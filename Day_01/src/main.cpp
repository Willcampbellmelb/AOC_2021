#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using std::cout;
using std::endl;
int numIncreases(const std::vector<int> &data);
std::vector<int> parseInput(std::string data_file, int data_points);
int main() {
  // part 1
  std::vector<int> dataA = {199, 200, 208, 210, 200,
                            207, 240, 269, 260, 263};    // 2 times
  std::vector<int> dataB = {1, 5, 3, 6, 4, 7, 5, 8, 10}; // 5 times

  if (numIncreases(dataA) != 7) {
    cout << " dataA has 7 increases! - something is wrong" << endl;
  }
  if (numIncreases(dataB) != 5) {
    cout << " dataA has 5 increases! - something is wrong" << endl;
  } else if (numIncreases(dataA) == 7 && numIncreases(dataB) == 5) {
    cout << "things seem to be working.. but check other corner cases ->write "
            "them down "
         << endl;
  }
  auto aoc_data = parseInput("../data/input.txt", 2000);
  cout << "AOC increments: " << numIncreases(aoc_data) << endl;

  // part 2
  // do it with GTEST NOW
  return 0;
}
/**
 * @brief parse text file single line input to a vector of ints
 *
 * @param data_file
 * @param data_points
 * @return std::vector<int>
 */
std::vector<int> parseInput(std::string data_file, int data_points) {
  int read_data;
  std::vector<int> data;
  // read in depth measure data into vector
  std::ifstream input(data_file, std::ios_base::in);
  if (!input)
    std::cerr << "Could not open the file!" << std::endl;
  else {
    data.reserve(data_points); // known data file size
    while (input >> read_data) {
      data.emplace_back(read_data);
    }
  }
  return data;
}

/**
 * @brief count the number of times a depth measurement increases from the
 * previous measuremen
 *
 * @param data
 * @return int
 */
// count the number of times a depth measurement increases from the previous
// measurement

int numIncreases(const std::vector<int> &data) {
  int last = std::numeric_limits<int>::max();
  int count = 0;
  for (auto val : data) {
    if (val > last) {
      count++;
    }
    last = val;
  }
  return count;
}
