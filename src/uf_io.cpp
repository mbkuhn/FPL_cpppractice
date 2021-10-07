#include "uf_io.h"
#include <filesystem>

// == Member functions for class - user_input == //
// Constructor
user_input::user_input() {
  // Arguments:
  // - initial condition: week to choose the best 11 (between 1 and 38)
  // - number of transfers permitted each week
  // - which season to consider (selects data directory)
  init_gw = 1;
  tr_gw = 1;
  myseason = "2021-22";
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
        case 3: {std::string sbuf; ss >> sbuf;
          if (sbuf=="2020-2021" || sbuf=="2020" || sbuf=="2020-21") {
            myseason = "2020-21";
          } else { if (sbuf=="2021-2022" || sbuf=="2021" || sbuf=="2021-22") {
            myseason = "2021-22";
          } else {
            std::cout << "Faulty inputs, quitting program. Supply an available season.\n";
            exit (EXIT_FAILURE);
          } }
        break;}
      }
    } catch (...) {
      std::cout << "Faulty inputs, quitting program. Supply 1 to 3 arguments.\n";
      exit (EXIT_FAILURE);
    }
  }
  // Find and save the number of gameweeks
  save_numGW(myseason);
  // Check bounds of initial gameweek
  if (init_gw < 1) {
    init_gw = 1;
    std::cout << "Initial gameweek rounded up.\n";
  }
  if (init_gw > total_gw) {
    init_gw = total_gw;
    std::cout << "Initial gameweek rounded down.\n";
  }
  std::cout << "Parameters: initial gameweek " << init_gw << ", " << tr_gw << " transfer(s) each gameweek. " << myseason <<"\n" ;
}
// Find and save number of gameweeks in specified season
void user_input::save_numGW(std::string season) {
  std::stringstream sbuf;
  total_gw = 0;
  // src_dir is defined using cmake macro
  sbuf << src_dir << "/../data/" << season << "/gws/";
  int nskip = (sbuf.str()).size();
  for (const auto & entry : std::filesystem::directory_iterator(sbuf.str())) {
    std::string fpath = entry.path();
    // Check if file begins with gw
    if (fpath[nskip  ]!='g') continue;
    if (fpath[nskip+1]!='w') continue;
    // If it does, increment counter
    ++total_gw;
  }
}
// Getters
int user_input::get_initGW() {
  return init_gw;
}
int user_input::get_trPerGW() {
  return tr_gw;
}
int user_input::get_numGW() {
  return total_gw;
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
  // Extract only header line and put into stringstream
  std::getline(is,tmp);
  std::stringstream ss(tmp);
  // Go through header line to get number of entries
  while (std::getline(ss,tmp,',')) {
    ++key_length;
  }
  // Clear flags and return to the beginning of the line
  ss.clear();
  ss.seekg(std::ios::beg);
  // Give the correct length to the key
  key_csv = std::make_unique<int[]>(key_length);
  // Step through the array to assign correct values to key
  for (int i=0; i<key_length; ++i) {
    if (i<key_length-1) {
      // Look for delimiter
      std::getline(ss,tmp,',');
    } else {
      // Look for newline
      std::getline(ss,tmp);
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
  // transfer information from key_csv to other function
  int* int_tmp = new int[key_length];
  for (int i=0; i<key_length; ++i) {
    int_tmp[i] = key_csv[i];
  }
  return int_tmp;
}
// Read file to populate player
void user_input::read_player_attr_var(std::istream& is, std::string& name,
std::string& position, std::string& team, int& points, int& value) {
  std::string tmp;
  // Extract only a single line (i.e., a single player)
  std::getline(is,tmp);
  std::stringstream ss(tmp);
  // Go through key to determine when to read
  for (int i=0; i<key_length; ++i) {
    if (i<key_length-1) {
      // Look for delimiter
      std::getline(ss,tmp,',');
    } else {
      // Look for newline
      std::getline(ss,tmp);
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
// Read and embed player attributes in player class directly
// key_csv must be initialized before using these!
player user_input::read_player_new(std::istream& is) {
  std::string name, position, team;
  int points, value;
  read_player_attr_var(is,name,position,team,points,value);
  return player(name,position,team,points,value);
}
void user_input::read_player_copy(std::istream& is, player& p_in) {
  std::string name, position, team;
  int points, value;
  read_player_attr_var(is,name,position,team,points,value);
  p_in.update_player(name,position,team,points,value);
}
