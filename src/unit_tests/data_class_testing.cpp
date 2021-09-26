#include "../player.cpp"
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
};

// Write google tests in namespace
namespace{
  // Test values after player is constructed but not populated
  TEST(SampleTeamTest, empty_player)
  {
    // Construct player
    player empty;
    // Get and compare initial values
    EXPECT_EQ(empty.get_attr_str("name"),"empty");
  }
}
