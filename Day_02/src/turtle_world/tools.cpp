#include "tools.h"
/**
 * @brief Parse movement command inputs into a vector of commands
 *
 * @param data_file
 * @param data_points
 * @return std::vector<Command>
 */
std::vector<Command> ParseCommands(std::string data_file, int data_points) {
  int read_data; // turn into string stream and parse lines
  std::vector<Command> data;
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