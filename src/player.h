#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include <cstring>

// Define player class
class player
{
private:

  // Player attributes
  std::string name,team,position;
  int total_points,value;
  bool played;
  // Currently unused attributes
  //std::string kickoff_time;
  //double xP,creativity,ict_index,influence,threat;
  //int assists,bonus,bps,clean_sheets,element,fixture,goals_conceded,
  // goals_scored,minutes,opponent_team,own_goals,penalties_missed,
  // penalties_saved,red_cards,round,saves,selected,team_a_score,team_h_score,
  // transfers_balance,transfers_in,transfers_out,yellow_cards;
  //bool was_home;

public:

  // Constructors
  player();
  player(const std::string name_in, const std::string pos_in,
    const std::string team_in, const int tot_pts_in, const int value_in);
  // Data getters
  int get_attr_int(const std::string attr);
  std::string get_attr_str(const std::string attr);
  bool get_attr_bool(const std::string attr);
  // Data setters
  void update_attr(const std::string attr, const int val);
  void update_attr(const std::string attr, const std::string val);
  void update_attr(const std::string attr, const char* cval);
  void update_attr(const std::string attr, const bool val);
  void update_player(const std::string name_in, const std::string pos_in,
    const std::string team_in, const int tot_pts_in, const int value_in);
  void update_player(player p_in);
  // Output to screen
  void synopsis();
};


// Define team class
class team
{
public:
  // Contents are public
  int bank;
  player* GKs;
  player* DEFs;
  player* MIDs;
  player* FWDs;
  // ptr to captain, always meant to be shared
  player* capt;
  // ptr to all players on team, meant to be shared
  player** roster;

  // Constructor for initial gameweek
  team();
  // Copy constructor for new gameweek
  team(const team& told);

  // Output synopsis of team
  void synopsis();

  // Get team point total, given current selection
  int get_points();
  // Get team point total, best possible, and change who plays
  int get_points_best();

};

#endif
