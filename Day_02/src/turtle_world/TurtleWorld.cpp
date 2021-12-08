#include "Turtle.h"
#include "tools.h"
using std::cout;
using std::endl;
int main() {
  Turtle yellow("yellow");
  auto aoc_data = yellow.ParseCommands("../data/Input.txt", 1000);
  cout << yellow;
  for (auto val : aoc_data) {
    yellow.move(val);
  }
  cout << "---- Final position ---- \n" << yellow;
  Pose now = yellow.currentPose();
  cout << "Position multiplicative: " << now.x * now.z << endl;
  ;
  // testing 123
  // Turtle yellow("yellow");
  // cout << yellow;
  // Command mvmnt = {CommandType::forward, 10};
  // Command mvmnt2 = {CommandType::down, 5};
  // Command mvmnt3 = {CommandType::forward, 8};
  // Command mvmnt4 = {CommandType::up, 3};

  // yellow.move(mvmnt);
  // cout << yellow;
  // yellow.move(mvmnt2);
  // yellow.move(mvmnt3);
  // cout << yellow;
  // yellow.move(mvmnt4);
  // cout << yellow;
  return 0;
}