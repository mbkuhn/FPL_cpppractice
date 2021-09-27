//#include "player.h"
//#ifndef PLAYER_H
//#define PLAYER_H
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
  bool was_home,played;
  // Currently unused attributes
  //std::string kickoff_time;
  //double xP,creativity,ict_index,influence,threat;
  //int assists,bonus,bps,clean_sheets,element,fixture,goals_conceded,
  // goals_scored,minutes,opponent_team,own_goals,penalties_missed,
  // penalties_saved,red_cards,round,saves,selected,team_a_score,team_h_score,
  // transfers_balance,transfers_in,transfers_out,yellow_cards;
  //bool was_home;

public:

  // Constructor
  player()
  {
    name = "empty";
    team = "empty";
    position = "empty";
    total_points = 0;
    value = 0;
    played = false;
  }
  // Data getters
  int get_attr_int(const std::string attr)
  {
    if (attr=="points")
      return total_points;
    if (attr=="value")
      return value;
    return -1;
  }
  std::string get_attr_str(const std::string attr)
  {
    if (attr=="name")
      return name;
    if (attr=="team")
      return team;
    if (attr=="position")
      return position;
    return "error";
  }
  bool get_attr_bool(const std::string attr)
  {
    if (attr=="played")
      return played;
    return false;
  }
  // Data setters
  void update_attr(const std::string attr, const int val)
  {
    if (attr=="points")
      total_points=val;
    if (attr=="value")
      value=val;
  }
  void update_attr(const std::string attr, const std::string val)
  {
    if (attr=="name") {
      //name.replace(0,val.size(),val);
      name.resize(val.size());
      name=val; }
    if (attr=="team") {
      team.resize(val.size());
	    team=val; }
    if (attr=="position") {
      position.resize(val.size());
      position=val; }
  }
  // Avoid the use of this char overload. useful for sample team, though
  void update_attr(const std::string attr, const char* cval)
  {
    int n = std::strlen(cval);
    std::string val(cval,n);
    if (attr=="name") {
      name.resize(val.size());
      name=val; }
    if (attr=="team") {
      team.resize(val.size());
      team=val; }
    if (attr=="position") {
      position.resize(val.size());
      position=val; }
  }
  void update_attr(const std::string attr, const bool val)
  {
    if (attr=="played")
      played=val;
  }
  // Output to screen
  void synopsis()
  {
    std::cout<<position<<": "<<name;
    std::cout<<",  "<<float (value/10.0)<< " million\n";
    if (played) {
      std::cout<<total_points<<" pts  --";}
    else {
      std::cout<<"("<<total_points<<") pts  --";}
    std::cout<<"  "<<team<<"\n";
  }
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
  team()
  {
    // Amount of spending money available
    bank = 1'000; // 100 mil - units of .1 mil
    // Players on team (number according to rules)
    GKs = new player[2];
    DEFs = new player[5];
    MIDs = new player[5];
    FWDs = new player[3];
    // Construct ptr for whole roster
    roster = new player*[15];
    int n = -1;
    for (int i= 0; i < 2; ++i) {
      ++n;
      roster[n] = &GKs[i]; }
    for (int i= 0; i < 5; ++i) {
      ++n;
      roster[n] = &DEFs[i]; }
    for (int i= 0; i < 5; ++i) {
      ++n;
      roster[n] = &MIDs[i]; }
    for (int i= 0; i < 3; ++i) {
      ++n;
      roster[n] = &FWDs[i]; }
    // Only one captain, not chosen yet
    capt = new player;
    capt = nullptr;

  }
  // Copy constructor for new gameweek
  team(const team& told)
  {
    // Same amount of spending money
    bank = told.bank;
    // Initialize pointers
    GKs = new player[2];
    DEFs = new player[5];
    MIDs = new player[5];
    FWDs = new player[3];
    // Copy pointers
    for (int i= 0; i < 2; ++i)
      GKs[i] = told.GKs[i];
    for (int i= 0; i < 5; ++i)
      DEFs[i] = told.DEFs[i];
    for (int i= 0; i < 5; ++i)
      MIDs[i] = told.MIDs[i];
    for (int i= 0; i < 3; ++i)
      FWDs[i] = told.FWDs[i];
    // Copy roster pointer

    // Only one captain, not chosen yet
    capt = new player;
    capt = nullptr;
  }
  // Output synopsis of team
  void synopsis()
  {
    // Cycle through all players on roster
    for (int i=0; i<15; ++i) {
      if (i==2||i==7||i==12)
        std::cout<<"\n";
      // Get player synopsis
      (*roster[i]).synopsis();
    }
  }

  // Get team point total, given current selection
  // Assume captain is the one with the most points
  int get_points()
  {
    int tmp;
    int pts = 0;
    int maxp = 0;
    // Cycle through all players on roster
    for (int i=0; i<15; ++i) {
      // Check if player played
      if ((*roster[i]).get_attr_bool("played")) {
        // Contribute points
        tmp = (*roster[i]).get_attr_int("points");
        pts += tmp;
        // Look for captain
        maxp = std::max(tmp,maxp);
        if (tmp == maxp)
          // Assign captain if max points is true
          capt = roster[i];
      }
    }
    // Add additional points from captain
    pts += (*capt).get_attr_int("points");
    return pts;
  }

  // Get team point total, best possible, and change who plays
  int get_points_best()
  {
    int tmp;
    int rank_pts[12] = {0};
    int rank_ind[12] = {0};
    int defs_in = 0;
    int mids_in = 0;
    int fwds_in = 0;

    // Cycle through goalies, pick best
    tmp = GKs[0].get_attr_int("points");
    if (tmp > GKs[1].get_attr_int("points")) {
      GKs[0].update_attr("played",true);
      GKs[1].update_attr("played",false);
    } else {
      GKs[1].update_attr("played",true);
      GKs[0].update_attr("played",false);
    }
    // Cycle through all field players on roster
    // to rank points scored by team
    for (int i=2; i<15; ++i) {
      // Get points of current field player
      tmp = (*roster[i]).get_attr_int("points");
      // Traverse ranked list of players' points
      for (int ii=0; ii<i-1; ++ii) {
        if (rank_pts[ii]<tmp){
          // Move other elements to the right
          for (int iii=i-2; iii>ii; --iii) {
            rank_pts[iii] = rank_pts[iii-1];
            rank_ind[iii] = rank_ind[iii-1];
          }
          // Populate array with current value
          rank_pts[ii] = tmp;
          rank_ind[ii] = i;
          // Exit ii loop
          break;
        }
      }
    }
    // Cycle through all field players on roster
    // to select which players should play
    for (int i=2; i<15; ++i) {
      // Look in ranked list of indices
      tmp = rank_ind[i-2];
      // Check constraints on lineup
      if (defs_in+mids_in+fwds_in == 10) {
        // No players can be admitted, team is full
        (*roster[tmp]).update_attr("played",false);
      } else { if (mids_in+fwds_in == 7) {
        // Only defenders can be admitted, to enforce >= 3 defender limit
        if ((*roster[tmp]).get_attr_str("position")=="DEF") {
          (*roster[tmp]).update_attr("played",true);
        } else {
          (*roster[tmp]).update_attr("played",false);
        }
      } else { if (defs_in + mids_in == 9) {
        // Only forwards can be admitted, to enforce >= 1 forward limit
        if ((*roster[tmp]).get_attr_str("position")=="FWD") {
          (*roster[tmp]).update_attr("played",true);
        } else {
          (*roster[tmp]).update_attr("played",false);
        }
      } else {
        // None of the constraints apply, simply add player
        (*roster[tmp]).update_attr("played",true);
      } } }
      // If current player is included, add to position tally
      if ((*roster[tmp]).get_attr_bool("played")) {
        std::string pos = (*roster[tmp]).get_attr_str("position");
        if (pos=="DEF") ++defs_in;
        if (pos=="MID") ++mids_in;
        if (pos=="FWD") ++fwds_in;
      }
    }
    // Call basic get points now that players have been chosen
    tmp = get_points();
    return tmp;
  }

};

//#endif
