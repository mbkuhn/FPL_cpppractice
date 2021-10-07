#include "uf_io.h"

// Find the best team possible given the parameters
int main(int argc, char* argv[])
{
  // Check if number of inputs is within allowed amount
  if (argc>4) {
    std::cout << "Faulty inputs, quitting program. Supply 1 to 3 arguments.\n";
    exit (EXIT_FAILURE);
  }
  // Construct class
  user_input ui = user_input();
  // Interpret inputs to main
  ui.interpret(argc,argv);

  return 0;
}
