#include <sstream>
#include <iostream>
#include "player.cpp"
//#include "player.h"

int main(int argc, char* argv[])
{
  // Find the best team possible given the parameters
  // Arguments:
  // - initial condition: week to choose the best 11 (between 1 and 38)
  // - number of transfers permitted each week

  // Declare parameters with defaults of 1
  int init_gw = 1;
  int tr_gw = 1;

  // Initialize if specified
  for (int i=1; i<argc; ++i) {
    std::stringstream ss(argv[i]);
    int x;
    switch (i) {
    case 1: {ss >> init_gw; break;}
    case 2: {ss >> tr_gw; break;}
    default: {
      std::cout << "Faulty inputs, quitting program. Supply 1 or 2 integer arguments.\n";
      return 1; }
    }
  }

  std::cout << "Parameters: initial gameweek " << init_gw << ", " << tr_gw << " transfer(s) each gameweek.\n" ;

  // Sample commands
  team sample = team();
  sample.sample_team();
  sample.synopsis();
  int score = sample.get_points();
  // Print captain
  std::string captain = (*sample.capt).get_attr_str("name");

  std::cout << "\nSample point total: " << score << ", Team captain is " << captain << ".\n";

  return 0;

}
