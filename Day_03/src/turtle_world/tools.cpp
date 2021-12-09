#include "tools.h"

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
// parse diagnostic data , calculate values and create report findings
/**
 * @brief parses an input diagnostic file and calculates the power consumption
 * for the given machine that input the file
 * Power consumption = gamma_rate * epsilon rate
 *
 * @param diagnostic_file output
 * @param data_points
 * @return power consumption for input diagnostic file
 */
int PowerConsumption(const std::string &diagnostic_file,
                     const int &data_points) {
  // parse input line by line
  // determine size of data input (x number of bits) by reading first line
  std::string read_data;
  std::vector<int> count;
  // read in depth measure data into vector
  std::ifstream input(diagnostic_file, std::ios_base::in);
  if (!input)
    std::cerr << "Could not open the file!" << std::endl;
  else {
    // create dynamically sized count vector with initial vals;
    input >> read_data;
    count.reserve(read_data.size());
    std::for_each(read_data.begin(), read_data.end(),
                  [&count](const char &c) { count.emplace_back(c - '0'); });
    while (input >> read_data) {
      // count.emplace_back(read_data);
      for (int i = 0; i < count.size(); ++i) {
        count[i] += (read_data[i] - '0');
        cout << count[i] << " ";
      }
      cout << endl;
    }
  }
  return (GammaRate(count, data_points) * EpsilonaRate(count, data_points));
}
/**
 * @brief gamma rate: for data with x bits per line: each bit is the
 * most common bit in the corresponding position of all numbers in the
 * diagnostic report.
 *
 * @param bit_count vector of counts of 1 bits for each position in the nput
 file
 * @param data_points in input file

 * @return int
 */
int GammaRate(const std::vector<int> &bit_count, int data_points) {
  std::string bin_string;
  for (auto count : bit_count) {
    if (count > (data_points / 2)) {
      bin_string += std::string("1");
    } else {
      bin_string += std::string("0");
    }
  }
  int g = stoi(bin_string, 0, 2);
  cout << "bit gamma rate : " << bin_string << " decimal: " << g << endl;
  return g;
}

/**
 * @brief Epsilon rate : for data with x bits per line: each bit is the
 * least common bit in the corresponding position of all numbers in the
 * diagnostic report: Or the opposite bits of the gamma rate
 *
 * @param bit_count vector of bit counts
 * @param data_points in input file
 * @return int
 */
int EpsilonaRate(const std::vector<int> &bit_count, int data_points) {
  std::string bin_string;
  for (auto count : bit_count) {
    if (count > (data_points / 2)) {
      bin_string += std::string("0");
    } else {
      bin_string += std::string("1");
    }
  }
  int eps = stoi(bin_string, 0, 2);
  cout << "bit eps rate   : " << bin_string << " decimal: " << eps << endl;

  return eps;
}
/**
 * @brief
 *
 * @param unorderd_map used for decreasing cost of deleting by random access
 * int key does not really matter - just need one, we will be using iterators.
 * NOTE: This may be better with another data stuct, even just a vector, but i
 * am experimenting.
 */
int OxGenRating(std::unordered_map<int, std::string>);
// test logic
