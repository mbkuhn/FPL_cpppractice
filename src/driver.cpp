#include <sstream>
#include <iostream>
#include "player.cpp"

class user_input {
private:
  int init_gw, tr_gw;

public:
  user_input() {
    // Arguments:
    // - initial condition: week to choose the best 11 (between 1 and 38)
    // - number of transfers permitted each week
    init_gw = 1;
    tr_gw = 1;
  }
  void interpret(int argc,char* argv[]) {
  // Initialize if specified
  for (int i=1; i<argc; ++i) {
    // initialize stream and enable exceptions
    std::stringstream ss(argv[i]);
    ss.exceptions(std::ios_base::badbit | std::ios_base::failbit);
    try{
      switch (i) {
        case 1: {ss >> init_gw; break;}
        case 2: {ss >> tr_gw; break;}
      }
    } catch (...) {
      std::cout << "Faulty inputs, quitting program. Supply 1 or 2 integer arguments.\n";
      exit (EXIT_FAILURE);
    }
  }
  std::cout << "Parameters: initial gameweek " << init_gw << ", " << tr_gw << " transfer(s) each gameweek.\n" ;
  }
  // Getters
  int get_initGW() {
    return init_gw;
  }
  int get_trPerGW() {
    return tr_gw;
  }
  // Get filename
  std::string get_filename(int gw, std::string season) {
      std::stringstream sbuf;
      // src_dir is defined using cmake macro
      sbuf << src_dir << "/../data/" << season << "/gws/gw" << gw << ".csv";
      return sbuf.str();
  }
};

// Find the best team possible given the parameters
int main(int argc, char* argv[])
{
  // Check if number of inputs is within allowed amount
  if (argc>3) {
    std::cout << "Faulty inputs, quitting program. Supply 1 or 2 integer arguments.\n";
    exit (EXIT_FAILURE);
  }
  // Construct class
  user_input ui = user_input();
  // Interpret inputs to main
  ui.interpret(argc,argv);

  return 0;
}
