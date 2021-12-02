#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>
using std::cout;
using std::endl;
int NumIncreases(const std::vector<int> &data);
int SlidingIncrease(const std::vector<int> &data, const int &window_size);
std::vector<int> ParseInput(std::string data_file, int data_points);
int main() {
  // part 1
  cout << "-------------part 1 ---------------" << endl;
  //   std::vector<int> dataA = {199, 200, 208, 210, 200,
  //                             207, 240, 269, 260, 263};    // 2 times
  //   std::vector<int> dataB = {1, 5, 3, 6, 4, 7, 5, 8, 10}; // 5 times

  //   if (NumIncreases(dataA) != 7) {
  //     cout << " dataA has 7 increases! - something is wrong" << endl;
  //   }
  //   if (NumIncreases(dataB) != 5) {
  //     cout << " dataA has 5 increases! - something is wrong" << endl;
  //   } else if (NumIncreases(dataA) == 7 && NumIncreases(dataB) == 5) {
  //     cout << "things seem to be working.. but check other corner cases
  //     ->write "
  //             "them down "
  //          << endl;
  //   }
  auto aoc_data = ParseInput("../data/input.txt", 2000);
  cout << "AOC increments: " << NumIncreases(aoc_data) << endl;

  // part 2
  cout << "-------------part 2 ---------------" << endl;
  //
  // testing 2,1,2,3
  //   std::vector<int> dataC = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> dataD = {199, 200, 208, 210, 200, 207, 240, 269, 260, 263};
  if (SlidingIncrease(dataD, 3) == 5) {
    cout << "very good!" << endl;
  } else {
    cout << "sumtin is up" << endl;
    cout << "we got:" << SlidingIncrease(dataD, 3) << " increases" << endl;
  }
  cout << "AOC sliding window increments: " << SlidingIncrease(aoc_data, 3)
       << endl;
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
std::vector<int> ParseInput(std::string data_file, int data_points) {
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

int NumIncreases(const std::vector<int> &data) {
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
int SlidingIncrease(const std::vector<int> &data, const int &window_size) {
  auto first = data.begin();
  auto compare = data.begin() + 1;
  auto end = data.end() - window_size;
  int count = 0;
  while (compare < end + 1) {
    int first_sum = std::accumulate(first, first + window_size, 0);
    int scnd_sum = std::accumulate(compare, compare + window_size, 0);
    if (scnd_sum > first_sum)
      count++;
    first++;
    compare++;
  }
  return count;
}
