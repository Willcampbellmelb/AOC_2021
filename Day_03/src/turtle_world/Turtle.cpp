#include "Turtle.h"

using std::cerr;
using std::cout;
using std::endl;
/**
 * @brief overloader opperator for streaming turtle position
 *
 * @param os
 * @param ttl
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &os, const Turtle &ttl) {

  os << "---- Current Pose for  " << ttl.name_ << " Turtle ---------\n"
     << "---- Horizontal X: " << ttl.currentPose_.x << endl
     << "---- Depth Z: " << ttl.currentPose_.z << endl
     << "---- aim about y: " << ttl.currentPose_.aim << endl;

  return os;
}
/**
 * @brief move sub based on input movement commands
 *
 * @param cmd struct of Given type with value for the sub
 */
void Turtle::move(const Command &cmd) {
  cout << " -------- Turtle Movement -------\n";

  switch (cmd.cmnd) {
  case CommandType::forward:
    cout << " Moving in X +" << cmd.value << endl;
    currentPose_.x += cmd.value;
    currentPose_.z += (cmd.value * currentPose_.aim);
    break;
  case CommandType::down:
    // currentPose_.z += cmd.value; // old part 1 idea
    currentPose_.aim += cmd.value;
    break;
  case CommandType::up:
    // currentPose_.z -= cmd.value; old part 1 idea
    currentPose_.aim -= cmd.value;
    break;
  default:
    cerr << "Can't make movement \n";
  }
  cout << " -------- End of Turtle Movement -------\n";
}
/**
 * @brief Function to lookup CommandType from a stored lookup table from input
 * string
 *
 * @param cmnd
 * @return CommandType
 */
CommandType Turtle::CommandLookUp(std::string cmnd) {
  auto it = string_to_cmnd.find(cmnd);
  if (it != string_to_cmnd.end()) {
    return it->second;
  } else {
    std::cerr << cmnd << "  not found in table" << std::endl;
    return CommandType::error;
  }
}

/**
 * @brief Parse movement command inputs into a vector of commands
 *
 * @param data_file
 * @param data_points
 * @return std::vector<Command>
 */
std::vector<Command> Turtle::ParseCommands(std::string data_file,
                                           int data_points) {
  std::vector<Command> data;
  std::ifstream myfile(data_file, std::ios_base::in);
  if (!myfile)
    std::cerr << "Could not open the file!" << std::endl;
  else {
    std::string read_data;
    std::stringstream ss;
    data.reserve(data_points); // known data file size

    while (getline(myfile, read_data)) {
      std::string cmnd_type_s;
      int cmnd_value;
      ss.clear();
      ss << read_data;
      ss >> cmnd_type_s >> cmnd_value;
      cout << " Read in cmnd type:" << cmnd_type_s << " "
           << "with value: " << cmnd_value << endl;
      Command input = {CommandLookUp(cmnd_type_s), cmnd_value};
      data.emplace_back(input);
    }
  }
  return data;
}
