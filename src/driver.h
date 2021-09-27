#ifndef DRIVER_H
#define DRIVER_H

#include <sstream>
#include <iostream>

class user_input {
private:
  int init_gw, tr_gw;

public:
  user_input();
  void interpret(int argc,char* argv[]);
  // Getters
  int get_initGW();
  int get_trPerGW();
  // Get filename
  std::string get_filename(int gw, std::string season);
};

#endif
