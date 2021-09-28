#include "../player.h"
#include "../uf_io.h"
#include "gtest/gtest.h"
// Write google tests in namespace
namespace {

// Set up class to assist testing of reading info
class FileReadTest : public testing::Test {
protected:
  std::istringstream is_head{"name,blank,position,value,not,0,total_points,2000,team,extra\n"};
  const int is_length = 10;
  const int key_ref[10] = {1,0,2,5,0,0,4,0,3,0};
  const std::string name_ref = "Alan Shearer";
  const std::string pos_ref = "FWD";
  const std::string team_ref = "Blackburn Rovers";
  const int pts_ref = 9;
  const int value_ref = 120;
  std::istringstream is_data{"Alan Shearer,0.0,FWD,120,2,true,9,00:00:11,Blackburn Rovers,8.1\n"};

};

  // Test ability of key maker to correctly interpret header stream
  TEST_F(FileReadTest, ReadKey) {
    // Defined in class:
    // * pre-populated header stream  (is_head)
    // * length of input stream       (is_length)
    // * A priori reference key       (key_ref)

    // Construct user_input class
    user_input ui = user_input();
    // Call function to generate key_csv
    ui.read_player_attr_header(is_head);
    // Output key for the sake of testing
    int *key_csv_out = ui.output_player_attr_header();
    // Cycle through integer lists for direct testing
    for (int i=0; i<is_length; ++i) {
      EXPECT_EQ(key_csv_out[i],key_ref[i]);
    }
  }

  // Test ability of key maker to correctly interpret data stream
  // Depends on success of functionality tested above
  TEST_F(FileReadTest, ReadDataLine) {
    // Defined in class:
    // * pre-populated data stream    (is_data)
    // * length of input stream       (is_length)
    // * A priori reference key       (key_ref)
    // * data variable references     (*_ref)

    // Attribute variables to write to
    std::string name, position, team;
    int points, value;

    // Construct user_input class
    user_input ui = user_input();
    // Call function to generate key_csv
    ui.read_player_attr_header(is_head);
    // With key populated, read in data
    ui.read_player_attr_var(is_data,name,position,team,points,value);
    // Check values
    std::string tmp;
    for (int i=0; i<is_length; ++i) {
      switch (key_ref[i]) {
      case 1:
        EXPECT_EQ(name,name_ref); break;
      case 2:
        EXPECT_EQ(position,pos_ref); break;
      case 3:
        EXPECT_EQ(team,team_ref); break;
      case 4:
        EXPECT_EQ(points,pts_ref); break;
      case 5:
        EXPECT_EQ(value,value_ref); break;
      }
    }
  }

  // Test both functions for getting points and choosing captain
  TEST_F(FileReadTest, ReadPlayer) {
    // Attribute variables to write to
    std::string name, position, team;
    int points, value;

    // Construct user_input class
    user_input ui = user_input();
    // Call function to generate key_csv
    ui.read_player_attr_header(is_head);
    // With key populated, read in data
    ui.read_player_attr_var(is_data,name,position,team,points,value);
    // With data, construct player
    // Construct player
    player alan = player(name,position,team,points,value);
    // Check new player attributes against default
    EXPECT_EQ(alan.get_attr_str("name"),name_ref);
    EXPECT_EQ(alan.get_attr_str("team"),team_ref);
    EXPECT_EQ(alan.get_attr_str("position"),pos_ref);
    EXPECT_EQ(alan.get_attr_int("points"),pts_ref);
    EXPECT_EQ(alan.get_attr_int("value"),value_ref);
  }

}
