#include "Turtle.h"
#include "tools.h"
using std::cout;
using std::endl;
int main() {

  // cout << PowerConsumption("../data/input.txt", 1000) << endl;

  cout << "OxGenRating: " << OxGenRating("../data/testInput.txt", 5) << endl;
  cout << "C02 GenRating: " << CO2GenRating("../data/testInput.txt", 5) << endl;

  return 0;
}