#pragma once
#include "tools.h"
#include <unordered_map>
// Parsed data struct
enum class CommandType { forward, down, up, error };
struct Command {
  CommandType cmnd;
  int value;
};
// simplified Turtle Pose in 3-d space
// -X - horizontal  (front and back), Z- depth where down is + Z or positive
// depth Can be edited later to prope xyz cartesian, eucledian or quaternion
// aim of the sub: + aim in the + depth or down z directions (+ z by our defs)
struct Pose {
  int x;
  int z;
  int aim;
};
class Turtle {
public:
  Turtle();
  ~Turtle(){};
  Turtle(std::string name) : name_{name}, currentPose_{0, 0, 0} {};
  Turtle(Pose initialPose)
      : currentPose_{initialPose}, name_{"Default Turtle"} {};
  Turtle(Pose initialPose, std::string name)
      : name_{name}, currentPose_{initialPose} {};

  void move(const Command &cmd);
  Pose currentPose() const { return currentPose_; };
  // ostream
  friend std::ostream &operator<<(std::ostream &os, const Turtle &sub);
  CommandType CommandLookUp(std::string cmnd);
  // enum map
  std::unordered_map<std::string, CommandType> const string_to_cmnd = {
      {"forward", CommandType::forward},
      {"down", CommandType::down},
      {"up", CommandType::up},
      {"error", CommandType::error}};
  // std::unordered_map<std::string, CommandType> const string_to_cmnd;
  // Parsing turtle mocement command data file
  std::vector<Command> ParseCommands(std::string data_file, int data_points);

private:
  Pose currentPose_ = {0, 0, 0};
  std::string name_ = {"Default Turtle"};
};