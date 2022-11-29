#include "gtest/googletest/include/gtest/gtest.h"
#include "DataContainer.h"
#include "AchievementDefinition.h"



class DataContainerTest : public testing::Test {
public:
    void SetUp() override {
        achievementDefinition =  new Achievement::AchievementDefinition();
    }

    void TearDown() {
        delete achievementDefinition;
    }

    Achievement::AchievementDefinition *achievementDefinition;
    Data::DataContainer dataContainer;
};

TEST_F(DataContainerTest, AchivementsOrdinalParserTest)
{
    std::vector<const Achievement::AchievementDefinition *> achievementDefs;
    achievementDefinition->RewardTypes.emplace_back("First tap");
    achievementDefinition->RewardAmount.emplace_back("10 diamonds and 500 golds");
    achievementDefinition->RewardTypes.emplace_back("123123rd tap");
    achievementDefinition->RewardAmount.emplace_back("10 diamonds and 500 golds");
    achievementDefinition->RewardTypes.emplace_back("First score");
    achievementDefinition->RewardAmount.emplace_back("10 diamonds and 500 golds");
    achievementDefinition->RewardTypes.emplace_back("First win");
    achievementDefinition->RewardAmount.emplace_back("10 diamonds and 500 golds");
    achievementDefinition->RewardTypes.emplace_back("Second win");
    achievementDefinition->RewardAmount.emplace_back("10 diamonds and 500 golds");
    achievementDefinition->RewardTypes.emplace_back("Third win");
    achievementDefinition->RewardAmount.emplace_back("10 diamonds and 500 golds");
    achievementDefs.emplace_back(achievementDefinition);
    dataContainer.SetAchievementDefinitions(achievementDefs);
    std::vector<const Achievement::AchievementDefinition*> ach;
    ach = dataContainer.GetAchievementDefinitions();

    dataContainer.AchivementsOrdinalParser(ach);
    std::vector<Achievement::AchievementDefinition*> parsedAchievementDefs = dataContainer.GetParsedAchivementDefinitions();
    ASSERT_EQ(parsedAchievementDefs.at(0)->RewardTypes.at(0), "1st tap");
    ASSERT_EQ(parsedAchievementDefs.at(0)->RewardTypes.at(1), "123123rd tap");
    ASSERT_EQ(parsedAchievementDefs.at(0)->RewardTypes.at(2), "1st score");
    ASSERT_EQ(parsedAchievementDefs.at(0)->RewardTypes.at(3), "1st win");
    ASSERT_EQ(parsedAchievementDefs.at(0)->RewardTypes.at(4), "2nd win");
    ASSERT_EQ(parsedAchievementDefs.at(0)->RewardTypes.at(5), "3rd win");
}

TEST_F(DataContainerTest, AchivementParserTest) {
    std::vector<const Achievement::AchievementDefinition *> achievementDefs;
    achievementDefinition->RewardTypes.emplace_back("First tap");
    achievementDefinition->RewardAmount.emplace_back("10 diamonds and 500 golds");
    achievementDefinition->RewardTypes.emplace_back("4th tap");
    achievementDefinition->RewardAmount.emplace_back("1111 diamonds and 500 golds");
    achievementDefinition->RewardTypes.emplace_back("First score");
    achievementDefinition->RewardAmount.emplace_back("1999 diamonds and 9876 golds");
    achievementDefinition->RewardTypes.emplace_back("First win");
    achievementDefinition->RewardAmount.emplace_back("1231231 diamonds and 500 golds");
    achievementDefinition->RewardTypes.emplace_back("Second win");
    achievementDefinition->RewardAmount.emplace_back("9877789 diamonds and 500 golds");
    achievementDefinition->RewardTypes.emplace_back("Third win");
    achievementDefinition->RewardAmount.emplace_back("10 diamonds and 9877789 golds");
    achievementDefs.emplace_back(achievementDefinition);
    dataContainer.SetAchievementDefinitions(achievementDefs);
    std::vector<const Achievement::AchievementDefinition*> ach;
    ach = dataContainer.GetAchievementDefinitions();
    dataContainer.AchivementsOrdinalParser(ach);
    dataContainer.AchivementParser();
    ASSERT_EQ(dataContainer.TapRewards[1], "10 diamonds and 500 golds");
    ASSERT_EQ(dataContainer.TapRewards[4], "1111 diamonds and 500 golds");
    ASSERT_EQ(dataContainer.ScoreRewards[1], "1999 diamonds and 9876 golds");
    ASSERT_EQ(dataContainer.WinRewards[1], "1231231 diamonds and 500 golds");
    ASSERT_EQ(dataContainer.WinRewards[2], "9877789 diamonds and 500 golds");
    ASSERT_EQ(dataContainer.WinRewards[3], "10 diamonds and 9877789 golds");
}

TEST_F(DataContainerTest, RewardCounterTest) {
  std::vector<const Achievement::AchievementDefinition *> achievementDefs;
  achievementDefinition->RewardTypes.emplace_back("First tap");
  achievementDefinition->RewardAmount.emplace_back("10 diamonds and 500 golds");
  achievementDefinition->RewardTypes.emplace_back("4th tap");
  achievementDefinition->RewardAmount.emplace_back("120 golds and 100 diamonds");
  achievementDefinition->RewardTypes.emplace_back("First score");
  achievementDefinition->RewardAmount.emplace_back("120 diamonds and 110 golds");
  achievementDefinition->RewardTypes.emplace_back("5th score");
  achievementDefinition->RewardAmount.emplace_back("90000 diamonds and 900000 golds");
  achievementDefinition->RewardTypes.emplace_back("First win");
  achievementDefinition->RewardAmount.emplace_back("1000 diamonds and 1000 golds");
  achievementDefinition->RewardTypes.emplace_back("Second win");
  achievementDefinition->RewardAmount.emplace_back("10000 diamonds and 10000 golds");
  achievementDefinition->RewardTypes.emplace_back("Third win");
  achievementDefinition->RewardAmount.emplace_back("100000 diamonds and 100000 golds");
  achievementDefs.emplace_back(achievementDefinition);
  dataContainer.SetAchievementDefinitions(achievementDefs);
  std::vector<const Achievement::AchievementDefinition*> ach;
  ach = dataContainer.GetAchievementDefinitions();
  dataContainer.AchivementsOrdinalParser(ach);
  dataContainer.AchivementParser();
  dataContainer.m_player_data_handler.tap_count = 1;
  dataContainer.RewardCounter(dataContainer.m_player_data_handler.tap_count, dataContainer.TapRewards);
  ASSERT_EQ(dataContainer.m_player_data_handler.total_gold, 500);
  ASSERT_EQ(dataContainer.m_player_data_handler.total_diamond, 10);
  dataContainer.m_player_data_handler.tap_count = 4;
  dataContainer.RewardCounter(dataContainer.m_player_data_handler.tap_count, dataContainer.TapRewards);
  ASSERT_EQ(dataContainer.m_player_data_handler.total_gold, 620);
  ASSERT_EQ(dataContainer.m_player_data_handler.total_diamond, 110);
  dataContainer.m_player_data_handler.score_count = 1;
  dataContainer.RewardCounter(dataContainer.m_player_data_handler.score_count, dataContainer.ScoreRewards);
  ASSERT_EQ(dataContainer.m_player_data_handler.total_gold, 730);
  ASSERT_EQ(dataContainer.m_player_data_handler.total_diamond, 230);
  dataContainer.m_player_data_handler.score_count = 5;
  dataContainer.RewardCounter(dataContainer.m_player_data_handler.score_count, dataContainer.ScoreRewards);
  ASSERT_EQ(dataContainer.m_player_data_handler.total_gold, 900730);
  ASSERT_EQ(dataContainer.m_player_data_handler.total_diamond, 90230);
  dataContainer.m_player_data_handler.win_count = 1;
  dataContainer.RewardCounter(dataContainer.m_player_data_handler.win_count, dataContainer.WinRewards);
  ASSERT_EQ(dataContainer.m_player_data_handler.total_gold, 901730);
  ASSERT_EQ(dataContainer.m_player_data_handler.total_diamond, 91230);
  dataContainer.m_player_data_handler.win_count = 2;
  dataContainer.RewardCounter(dataContainer.m_player_data_handler.win_count, dataContainer.WinRewards);
  ASSERT_EQ(dataContainer.m_player_data_handler.total_gold, 911730);
  ASSERT_EQ(dataContainer.m_player_data_handler.total_diamond, 101230);
  dataContainer.m_player_data_handler.win_count = 3;
  dataContainer.RewardCounter(dataContainer.m_player_data_handler.win_count, dataContainer.WinRewards);
  ASSERT_EQ(dataContainer.m_player_data_handler.total_gold, 1011730);
  ASSERT_EQ(dataContainer.m_player_data_handler.total_diamond, 201230);
}