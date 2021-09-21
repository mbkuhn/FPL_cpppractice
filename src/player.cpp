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
  std::string name,team,position,kickoff_time;
  double xP,creativity,ict_index,influence,threat;
  int assists,bonus,bps,clean_sheets,element,fixture,goals_conceded,goals_scored,minutes,opponent_team,own_goals,penalties_missed,penalties_saved,red_cards,round,saves,selected,team_a_score,team_h_score,total_points,transfers_balance,transfers_in,transfers_out,value,yellow_cards;
  bool was_home,played;

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
    if (attr=="element")
      return element;
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
    if (attr=="element")
      element=val;
  }
  void update_attr(const std::string attr, const std::string val)
  {
    if (attr=="name") {
      //name.replace(0,val.size(),val);
      team.resize(val.size());
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
      team.resize(val.size());
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
      if (i==2||i==7||i==11)
        std::cout<<"\n";
      // Get player synopsis
      (*roster[i]).synopsis();
    }
  }

  // Make a sample team for testing
  void sample_team()
  {
    // List of attributes currently used:
    // name, position, value, points, team
    int i = 0;
    GKs[i].update_attr("name","Tim Howard");
    GKs[i].update_attr("position","GK");
    GKs[i].update_attr("value",50);
    GKs[i].update_attr("points",8);
    GKs[i].update_attr("team","Everton");
    GKs[i].update_attr("played",true);
    bank = bank - 50;
    ++i;
    GKs[i].update_attr("name","Zack Steffen");
    GKs[i].update_attr("position","GK");
    GKs[i].update_attr("value",60);
    GKs[i].update_attr("points",4);
    GKs[i].update_attr("team","Man City");
    bank = bank - 60;
    //
    i = 0;
    DEFs[i].update_attr("name","Antonee Robinson");
    DEFs[i].update_attr("position","DEF");
    DEFs[i].update_attr("value",45);
    DEFs[i].update_attr("points",5);
    DEFs[i].update_attr("team","Fulham");
    DEFs[i].update_attr("played",true);
    bank = bank - 45;
    ++i;
    DEFs[i].update_attr("name","John Brooks");
    DEFs[i].update_attr("position","DEF");
    DEFs[i].update_attr("value",65);
    DEFs[i].update_attr("points",10);
    DEFs[i].update_attr("team","Wolfsburg");
    DEFs[i].update_attr("played",true);
    bank = bank - 65;
    ++i;
    DEFs[i].update_attr("name","Sergino Dest");
    DEFs[i].update_attr("position","DEF");
    DEFs[i].update_attr("value",70);
    DEFs[i].update_attr("points",9);
    DEFs[i].update_attr("team","Barcelona");
    bank = bank - 70;
    ++i;
    DEFs[i].update_attr("name","DeAndre Yedlin");
    DEFs[i].update_attr("position","DEF");
    DEFs[i].update_attr("value",45);
    DEFs[i].update_attr("points",2);
    DEFs[i].update_attr("team","Newcastle FC");
    DEFs[i].update_attr("played",true);
    bank = bank - 45;
    ++i;
    DEFs[i].update_attr("name","Tim Ream");
    DEFs[i].update_attr("position","DEF");
    DEFs[i].update_attr("value",50);
    DEFs[i].update_attr("points",2);
    DEFs[i].update_attr("team","Fulham");
    bank = bank - 50;
    //
    i = 0;
    MIDs[i].update_attr("name","Michael Bradley");
    MIDs[i].update_attr("position","MID");
    MIDs[i].update_attr("value",60);
    MIDs[i].update_attr("points",3);
    MIDs[i].update_attr("team","AS Roma");
    MIDs[i].update_attr("played",true);
    bank = bank - 60;
    ++i;
    MIDs[i].update_attr("name","Weston McKennie");
    MIDs[i].update_attr("position","MID");
    MIDs[i].update_attr("value",60);
    MIDs[i].update_attr("points",11);
    MIDs[i].update_attr("team","Juventus");
    MIDs[i].update_attr("played",true);
    bank = bank - 60;
    ++i;
    MIDs[i].update_attr("name","Christian Pulisic");
    MIDs[i].update_attr("position","MID");
    MIDs[i].update_attr("value",90);
    MIDs[i].update_attr("points",1);
    MIDs[i].update_attr("team","Chelsea");
    MIDs[i].update_attr("played",true);
    bank = bank - 90;
    ++i;
    MIDs[i].update_attr("name","Kellyn Acosta");
    MIDs[i].update_attr("position","MID");
    MIDs[i].update_attr("value",60);
    MIDs[i].update_attr("points",3);
    MIDs[i].update_attr("team","MLS");
    bank = bank - 60;
    ++i;
    MIDs[i].update_attr("name","Giovanni Reyna");
    MIDs[i].update_attr("position","MID");
    MIDs[i].update_attr("value",85);
    MIDs[i].update_attr("points",3);
    MIDs[i].update_attr("team","BVB Dortnmund");
    MIDs[i].update_attr("played",true);
    bank = bank - 85;
    //
    i = 0;
    FWDs[i].update_attr("name","Josh Sargent");
    FWDs[i].update_attr("position","FWD");
    FWDs[i].update_attr("value",60);
    FWDs[i].update_attr("points",7);
    FWDs[i].update_attr("team","Norwich FC");
    FWDs[i].update_attr("played",true);
    bank = bank - 60;
    ++i;
    FWDs[i].update_attr("name","Clint Dempsey");
    FWDs[i].update_attr("position","FWD");
    FWDs[i].update_attr("value",100);
    FWDs[i].update_attr("points",12);
    FWDs[i].update_attr("team","Fulham");
    FWDs[i].update_attr("played",true);
    bank = bank - 100;
    ++i;
    FWDs[i].update_attr("name","Darryl Dike");
    FWDs[i].update_attr("position","FWD");
    FWDs[i].update_attr("value",75);
    FWDs[i].update_attr("points",7);
    FWDs[i].update_attr("team","Barnsley");
    FWDs[i].update_attr("played",true);
    bank = bank - 75;
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

};

//#endif
