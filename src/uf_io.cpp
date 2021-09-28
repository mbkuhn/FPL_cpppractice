#include "uf_io.h"

// == Member functions for class - user_input == //
// Constructor
user_input::user_input() {
  // Arguments:
  // - initial condition: week to choose the best 11 (between 1 and 38)
  // - number of transfers permitted each week
  init_gw = 1;
  tr_gw = 1;
}
// Destructor
user_input::~user_input(){
  delete key_csv;
}
void user_input::interpret(int argc,char* argv[]) {
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
int user_input::get_initGW() {
  return init_gw;
}
int user_input::get_trPerGW() {
  return tr_gw;
}
// Get filename
std::string user_input::get_filename(int gw, std::string season) {
  std::stringstream sbuf;
  // src_dir is defined using cmake macro
  sbuf << src_dir << "/../data/" << season << "/gws/gw" << gw << ".csv";
  return sbuf.str();
}
// Read file header to determine location of player attributes
void user_input::read_player_attr_header(std::istream& is) {
  std::string tmp;
  key_length = 0;
  // Go through header line to get number of entries
  while (std::getline(is,tmp,',')) {
    ++key_length;
  }
  // Clear flags and return to the beginning of the line
  is.clear();
  is.seekg(std::ios::beg);
  // Give the correct length to the key
  key_csv = new int(key_length);
  // Step through the array to assign correct values to key
  for (int i=0; i<key_length; ++i) {
    if (i<key_length-1) {
      // Look for delimiter
      std::getline(is,tmp,',');
    } else {
      // Look for newline
      std::getline(is,tmp);
    }
    if (tmp=="name") {
      key_csv[i]=1;
    } else {
    if (tmp=="position") {
      key_csv[i]=2;
    } else {
    if (tmp=="team") {
      key_csv[i]=3;
    } else {
    if (tmp=="total_points") {
      key_csv[i]=4;
    } else {
    if (tmp=="value") {
      key_csv[i]=5;
    } else {
      key_csv[i]=0;
    } } } } }
  }
}
int* user_input::output_player_attr_header() {
  return key_csv;
}
// Read file to populate player
void user_input::read_player_attr_var(std::istream& is, std::string& name,
std::string& position, std::string& team, int& points, int& value) {
  std::string tmp;
  // Go through key to determine when to read
  for (int i=0; i<key_length; ++i) {
    if (i<key_length-1) {
      // Look for delimiter
      std::getline(is,tmp,',');
    } else {
      // Look for newline
      std::getline(is,tmp);
    }
    switch (key_csv[i]) {
    case 1:
      name = tmp; break;
    case 2:
      position = tmp; break;
    case 3:
      team = tmp; break;
    case 4:
      points = std::stoi(tmp); break;
    case 5:
      value = std::stoi(tmp); break;
    }
  }
}
