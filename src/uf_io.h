#ifndef UF_IO_H
#define UF_IO_H

#include <sstream>
#include <iostream>
#include <fstream>
#include <memory>
#include "player.h"

class user_input {
private:
  int init_gw, tr_gw, total_gw;
  int key_length;
  std::unique_ptr<int[]> key_csv;

public:
  user_input();
  void interpret(int argc,char* argv[]);
  // Find and save number of gameweeks
  void save_numGW(std::string season);
  // Getters
  int get_initGW();
  int get_trPerGW();
  int get_numGW();
  // Get filename
  std::string get_filename(int gw, std::string season);

  // Read header
  void read_player_attr_header(std::istream& is);
  // Output header (for the sake of testing)
  int* output_player_attr_header();
  // Read file to populate player
  void read_player_attr_var(std::istream& is, std::string& name,
    std::string& position, std::string& team, int& points, int& value);
  player read_player_new(std::istream& is);
  void read_player_copy(std::istream& is, player& p_in);
};

#endif
