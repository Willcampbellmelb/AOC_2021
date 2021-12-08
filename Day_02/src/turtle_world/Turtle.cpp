#include "Turtle.h"

using std::cerr;
using std::cout;
using std::endl;
std::ostream &operator<<(std::ostream &os, const Turtle &ttl) {

  os << "---- Current Pose for  " << ttl.name_ << " Turtle ---------\n"
     << "---- Horizontal X: " << ttl.currentPose_.x << endl
     << "---- Depth Z: " << ttl.currentPose_.z << endl;
  return os;
}

void Turtle::move(const Command &cmd) {
  cout << " -------- Turtle Movement -------\n";

  switch (cmd.cmnd) {
  case CommandType::forward:
    cout << " Moving in X +" << cmd.value << endl;
    currentPose_.x += cmd.value;
    break;
  case CommandType::down:
    cout << " Moving up in Z +" << cmd.value << endl;
    currentPose_.z += cmd.value;
    break;
  case CommandType::up:
    cout << " Moving down in Z +" << cmd.value << endl;
    currentPose_.z += cmd.value;
    break;
  default:
    cerr << "Can't make movement \n";
  }
  cout << " -------- End of Turtle Movement -------\n";
}
