#include "DataContainer.h"

#include "AchievementDefinition.h"

namespace Data
{
    // Some other related code.
    DataContainer::DataContainer()
    {
        achievementDefinition =  new Achievement::AchievementDefinition();
    }

    const std::vector<const Achievement::AchievementDefinition*>& DataContainer::GetAchievementDefinitions()const
    {
        return achievementDefs;
    }
    const void DataContainer::SetAchievementDefinitions(std::vector<const Achievement::AchievementDefinition *> achivements) {
        this->achievementDefs = achivements;
    }

    void DataContainer::AchivementsOrdinalParser(std::vector<const Achievement::AchievementDefinition *>& achievementDefs) {
      for (auto  achivements : achievementDefs)
      {
          int amount_index{0};
          size_t  position_of_space;
          for (auto reward : achivements->RewardTypes)
          {
              std::string whole_string;
              position_of_space = reward.find(" ");
              size_t position = reward.find("First");
              if (position != std::string::npos)
              {
                  whole_string.insert(0, "1st");
                  whole_string.append(reward.substr(position_of_space, reward.length()-1));
                  achievementDefinition->RewardTypes.emplace_back(whole_string);
              } else {
                  position = reward.find("Second");
                  if (position != std::string::npos)
                  {
                      whole_string.insert(0, "2nd");
                      whole_string.append(reward.substr(position_of_space, reward.length()-1));
                      achievementDefinition->RewardTypes.emplace_back(whole_string);
                  } else {
                      position = reward.find("Third");
                      if (position != std::string::npos)
                      {
                          whole_string.insert(0, "3rd");
                          whole_string.append(reward.substr(position_of_space, reward.length()-1));
                          achievementDefinition->RewardTypes.emplace_back(whole_string);
                      } else {
                          achievementDefinition->RewardTypes.emplace_back(reward);
                      }
                  }
              }

              achievementDefinition->RewardAmount.emplace_back(achivements->RewardAmount.at(amount_index++));
          }
      }

      parsedAchievementDefs.emplace_back(achievementDefinition);
    }

    void DataContainer::AchivementParser() {
        for (auto achivement : parsedAchievementDefs) {
            int amount_index{0};
            for (auto reward : achivement->RewardTypes) {
                size_t position = reward.find("tap");
                if (position != std::string::npos) {
                    std::pair<int, std::string> tapReward;
                    tapReward.first = std::stoi(reward.substr(0, position - 3));
                    tapReward.second = achivement->RewardAmount.at(amount_index++);
                    TapRewards.insert(tapReward);
                } else {
                    position = reward.find("score");
                    if (position != std::string::npos) {
                        std::pair<int, std::string> scoreReward;
                        scoreReward.first = std::stoi(reward.substr(0, position - 3));
                        scoreReward.second = achivement->RewardAmount.at(amount_index++);
                        ScoreRewards.insert(scoreReward);
                    } else {
                        position = reward.find("win");
                        if (position != std::string::npos) {
                            std::pair<int, std::string> winReward;
                            winReward.first = std::stoi(reward.substr(0, position - 3));
                            winReward.second = achivement->RewardAmount.at(amount_index++);
                            WindRewards.insert(winReward);
                        }
                    }
                }
            }
        }

        delete achievementDefinition;
    }

    PlayerDataHandler DataContainer::TapRewardCounter(PlayerDataHandler playerDataHandler) {
        std::string reward = TapRewards.at(playerDataHandler.tap_count);
        size_t gold_position = reward.find("gold");
        size_t amount_position{0};
        std::string amount_of_gold_str;
        int amount_of_gold;
        if (gold_position != std::string::npos)
        {
            amount_position = reward.rfind(' ', gold_position-2);
            if(amount_position != std::string::npos)
            {
                 amount_of_gold_str = reward.substr(amount_position, gold_position-2);
                 amount_of_gold = std::stoi(amount_of_gold_str);
            } else{
                amount_of_gold_str = reward.substr(0, gold_position-1);
                amount_of_gold = std::stoi(amount_of_gold_str);
            }

        }

        return PlayerDataHandler();
    }
}