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
  std::string read_data;
  std::vector<int> count;
  std::ifstream input(diagnostic_file, std::ios_base::in);
  if (!input)
    std::cerr << "Could not open the file!" << std::endl;
  else {
    input >> read_data;
    count.reserve(read_data.size());
    std::for_each(read_data.begin(), read_data.end(),
                  [&count](const char &c) { count.emplace_back(c - '0'); });
    while (input >> read_data) {
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
int OxGenRating(const std::string &diagnostic_file, int bit_length) {

  // parse input data into an unordered_map
  auto Map = ParseToMap(diagnostic_file);
  int data_points = Map.size();
  // count nmumber of occurences of an on bit in bit x in all of the provided
  // bitwise values
  int bit = 0;
  while (Map.size() > 1) {
    auto numba = OnBitCount(Map, bit);
    if (Map.size() % 2 == 0) {
      if (numba >= (Map.size() / 2)) {
        ReduceMap(Map, bit, 0);
      } else {

        ReduceMap(Map, bit, 1);
      }
    } else {
      if (numba > (Map.size() / 2)) {
        ReduceMap(Map, bit, 0);
      } else {
        ReduceMap(Map, bit, 1);
      }
    }
    ++bit;
  }
  auto itr = Map.begin();
  // convert to int and return
  return stoi((*itr).second, 0, 2);
}
/**
 * @brief
 *
 * @param map
 * @param pos
 * @param remove_val
 * @return number of values removed from map
 */
int ReduceMap(std::unordered_map<int, std::string> &map, const int &pos,
              const int &remove_val) {
  std::vector<int> remove_keys;
  for (auto val : map) {
    if ((val.second[pos] - '0') == remove_val) {
      remove_keys.emplace_back(val.first);
    }
  }
  for (auto val : remove_keys) {
    map.erase(val);
  }
  return remove_keys.size();
}
int OnBitCount(const std::unordered_map<int, std::string> &map,
               const int &pos) {
  int on_count = 0;
  for (auto val : map) {
    if ((val.second[pos] - '0') == 1)
      on_count++;
  }

  return on_count;
}
std::unordered_map<int, std::string>
ParseToMap(const std::string &diagnostic_file) {
  std::unordered_map<int, std::string> data;
  std::string read_data;
  std::ifstream input(diagnostic_file, std::ios_base::in);
  if (!input)
    std::cerr << "Could not open the file!" << std::endl;
  else {
    int count = 0;
    while (input >> read_data) {

      data[count] = read_data;
      ++count;
    }
  }
  return data;
}

int OxGenRating(const std::string &diagnostic_file, int bit_length) {

  // parse input data into an unordered_map
  auto Map = ParseToMap(diagnostic_file);
  int data_points = Map.size();
  // count nmumber of occurences of an on bit in bit x in all of the provided
  // bitwise values
  int bit = 0;
  while (Map.size() > 1) {
    auto numba = OnBitCount(Map, bit);
    if (Map.size() % 2 == 0) {
      if (numba >= (Map.size() / 2)) {
        ReduceMap(Map, bit, 0);
      } else {

        ReduceMap(Map, bit, 1);
      }
    } else {
      if (numba > (Map.size() / 2)) {
        ReduceMap(Map, bit, 0);
      } else {
        ReduceMap(Map, bit, 1);
      }
    }
    ++bit;
  }
  auto itr = Map.begin();
  // convert to int and return
  return stoi((*itr).second, 0, 2);
  ;
}