#pragma once
#include "tools.h"
// Parsed data struct
enum class CommandType { forward, down, up };
struct Command {
  CommandType cmnd;
  int value;
};
// simplified Turtle Pose in 3-d space
// -X - horizontal  (front and back), Z- depth (or vertical)
// Can be edited later to prope xyz cartesian, eucledian or quaternion
struct Pose {
  int x;
  int z;
};
class Turtle {
public:
  Turtle();
  ~Turtle(){};
  Turtle(std::string name) : name_{name}, currentPose_{0, 0} {};
  Turtle(Pose initialPose) : currentPose_{0, 0}, name_{"Default Turtle"} {};
  Turtle(Pose initialPose, std::string name)
      : name_{name}, currentPose_{0, 0} {};

  void move(const Command &cmd);
  Pose currentPose() const { return currentPose_; };
  // ostream
  friend std::ostream &operator<<(std::ostream &os, const Turtle &sub);

private:
  Pose currentPose_ = {0, 0};
  std::string name_ = {"Default Turtle"};
};