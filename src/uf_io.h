#ifndef UF_IO_H
#define UF_IO_H

#include <sstream>
#include <iostream>

class user_input {
private:
  int init_gw, tr_gw;
  int key_length;
  int *key_csv;

public:
  user_input();
  ~user_input();
  void interpret(int argc,char* argv[]);
  // Getters
  int get_initGW();
  int get_trPerGW();
  // Get filename
  std::string get_filename(int gw, std::string season);
  // Read header
  void read_player_attr_header(std::istream& is);
  // Output header (for the sake of testing)
  int* output_player_attr_header();
  // Read file to populate player
  void read_player_attr_var(std::istream& is, std::string& name,
    std::string& position, std::string& team, int& points, int& value);
};

#endif
