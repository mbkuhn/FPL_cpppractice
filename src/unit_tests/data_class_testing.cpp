#include "../player.h"
#include "gtest/gtest.h"
// Set up class just for populating a fake team
class sample : public team
{
public:
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
    DEFs[i].update_attr("played",true);
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
};

// Write google tests in namespace
namespace{
  // Test values after player is constructed but not populated
  // Test update_attr
  TEST(SampleTeamTest, empty_player)
  {
    // Construct player
    player empty;
    // Get and compare initial values
    EXPECT_EQ(empty.get_attr_str("name"),"empty");
    empty.update_attr("name","test");
    EXPECT_EQ(empty.get_attr_str("name"),"test");

    EXPECT_EQ(empty.get_attr_str("team"),"empty");
    empty.update_attr("team","test");
    EXPECT_EQ(empty.get_attr_str("team"),"test");

    EXPECT_EQ(empty.get_attr_str("position"),"empty");
    empty.update_attr("position","test");
    EXPECT_EQ(empty.get_attr_str("position"),"test");

    EXPECT_EQ(empty.get_attr_int("points"),0);
    empty.update_attr("points",100);
    EXPECT_EQ(empty.get_attr_int("points"),100);

    EXPECT_EQ(empty.get_attr_int("value"),0);
    empty.update_attr("value",100);
    EXPECT_EQ(empty.get_attr_int("value"),100);

    EXPECT_EQ(empty.get_attr_bool("played"),false);
    empty.update_attr("played",true);
    EXPECT_EQ(empty.get_attr_bool("played"),true);
  }
  // Test values after sample team
  // Test both functions for getting points and choosing captain
  TEST(SampleTeamTest, sample_team)
  {
    // Construct team
    sample steam = sample();
    // Populate team with sample values
    steam.sample_team();
    // Check variety of properties from sample values
    EXPECT_EQ(steam.GKs[0].get_attr_str("team"),"Everton");
    EXPECT_EQ(steam.GKs[1].get_attr_str("name"),"Zack Steffen");
    EXPECT_EQ(steam.DEFs[0].get_attr_int("points"),5);
    EXPECT_EQ(steam.DEFs[1].get_attr_int("value"),65);
    EXPECT_EQ(steam.DEFs[2].get_attr_str("team"),"Barcelona");
    EXPECT_EQ(steam.DEFs[3].get_attr_bool("played"),true);
    EXPECT_EQ(steam.DEFs[4].get_attr_str("position"),"DEF");
    EXPECT_EQ(steam.MIDs[0].get_attr_int("points"),3);
    EXPECT_EQ(steam.MIDs[1].get_attr_int("value"),60);
    EXPECT_EQ(steam.MIDs[2].get_attr_str("team"),"Chelsea");
    EXPECT_EQ(steam.MIDs[3].get_attr_str("position"),"MID");
    EXPECT_EQ(steam.MIDs[4].get_attr_bool("played"),true);
    EXPECT_EQ(steam.FWDs[0].get_attr_int("points"),7);
    EXPECT_EQ(steam.FWDs[1].get_attr_int("value"),100);
    EXPECT_EQ(steam.FWDs[2].get_attr_str("team"),"Barnsley");

    // Check the use of the roster pointer
    EXPECT_EQ((*steam.roster[ 0]).get_attr_str("position"),"GK");
    EXPECT_EQ((*steam.roster[ 1]).get_attr_str("position"),"GK");
    EXPECT_EQ((*steam.roster[ 2]).get_attr_str("position"),"DEF");
    EXPECT_EQ((*steam.roster[ 3]).get_attr_str("position"),"DEF");
    EXPECT_EQ((*steam.roster[ 4]).get_attr_str("position"),"DEF");
    EXPECT_EQ((*steam.roster[ 5]).get_attr_str("position"),"DEF");
    EXPECT_EQ((*steam.roster[ 6]).get_attr_str("position"),"DEF");
    EXPECT_EQ((*steam.roster[ 7]).get_attr_str("position"),"MID");
    EXPECT_EQ((*steam.roster[ 8]).get_attr_str("position"),"MID");
    EXPECT_EQ((*steam.roster[ 9]).get_attr_str("position"),"MID");
    EXPECT_EQ((*steam.roster[10]).get_attr_str("position"),"MID");
    EXPECT_EQ((*steam.roster[11]).get_attr_str("position"),"MID");
    EXPECT_EQ((*steam.roster[12]).get_attr_str("position"),"FWD");
    EXPECT_EQ((*steam.roster[13]).get_attr_str("position"),"FWD");
    EXPECT_EQ((*steam.roster[14]).get_attr_str("position"),"FWD");

    // Get points, which chooses captain
    int score = steam.get_points();
    // Get name of captain
    std::string captain = (*steam.capt).get_attr_str("name");
    // Check both with known values
    EXPECT_EQ(score,77);
    EXPECT_EQ(captain,"Weston McKennie");

    // Get best points, which chooses who plays and captain
    score = steam.get_points_best();
    // Get name of captain
    std::string captain2 = (*steam.capt).get_attr_str("name");
    // Check both with known values
    EXPECT_EQ(score,90);
    EXPECT_EQ(captain2,"Clint Dempsey");

    // Change points so that single forward rule is used
    (*steam.roster[9]).update_attr("points",5);
    (*steam.roster[2]).update_attr("points",2);
    (*steam.roster[3]).update_attr("points",2);
    (*steam.roster[4]).update_attr("points",2);
    score = steam.get_points_best();

    // Check number of defenders in played team, also total players
    int defs_in = 0; int plys_in = 0;
    for (int i=0; i<15; ++i) {
      if ((*steam.roster[i]).get_attr_bool("played")) {
        ++plys_in;
        if ((*steam.roster[i]).get_attr_str("position")=="DEF") {
          ++defs_in;
        }
      }
    }
    EXPECT_EQ(defs_in,3);
    EXPECT_EQ(plys_in,11);

    // Change points so that single forward rule is used
    (*steam.roster[12]).update_attr("points",1);
    (*steam.roster[13]).update_attr("points",1);
    (*steam.roster[14]).update_attr("points",1);
    score = steam.get_points_best();

    // Check number of forwards in played team, also total players
    int fwds_in = 0; plys_in = 0;
    for (int i=0; i<15; ++i) {
      if ((*steam.roster[i]).get_attr_bool("played")) {
        ++plys_in;
        if ((*steam.roster[i]).get_attr_str("position")=="FWD") {
          ++fwds_in;
        }
      }
    }
    EXPECT_EQ(fwds_in,1);
    EXPECT_EQ(plys_in,11);
  }

  // Test values after sample team
  // Test both functions for getting points and choosing captain
  TEST(SampleTeamTest, read_player) {
    // Construct player
    player empty;
    // Read player attributes from file

    // Check new player attributes against default
    EXPECT_NE(empty.get_attr_str("name"),"empty");
    EXPECT_NE(empty.get_attr_str("team"),"empty");
    EXPECT_NE(empty.get_attr_str("position"),"empty");
    EXPECT_NE(empty.get_attr_int("value"),0);
  }
}
