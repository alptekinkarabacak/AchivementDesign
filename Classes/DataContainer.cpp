#include "DataContainer.h"

#include "AchievementDefinition.h"

namespace Data
{
    // Some other related code.
    const std::vector<const Achievement::AchievementDefinition*>& DataContainer::GetAchievementDefinitions()const
    {
        return achievementDefs;
    }
    const void DataContainer::SetAchievementDefinitions(std::vector<const Achievement::AchievementDefinition *> achivements) {
        this->achievementDefs = achivements;
    }

    void DataContainer::AchivementsOrdinalParser(std::vector<const Achievement::AchievementDefinition *>& achievementDefs) {
      Achievement::AchievementDefinition *achievementDefinition = new Achievement::AchievementDefinition();
      for (auto  ach : achievementDefs) {
          *achievementDefinition = *ach;

      }



        for (int i{0}; i<achievementDefs.size(); ++i) {
            for(int j{0}; j<achievementDefs.at(0)->RewardTypes.size(); ++j) {
                size_t position = achievementDefs.at(i)->RewardTypes.at(j).find("First");
                if (position != std::string::npos) {
                  achievementDefinition->RewardTypes.emplace_back("1st");
                } else {
                    position = achievementDefs.at(i)->RewardTypes.at(j).find("Second");
                    if (position != std::string::npos) {
                      achievementDefinition->RewardTypes.emplace_back("2st");
                    } else {
                        position = achievementDefs.at(i)->RewardTypes.at(j).find("Second");
                        if (position != std::string::npos) {
                          achievementDefinition->RewardTypes.emplace_back("1st");
                        }
                    }
                }

                achievementDefinition->RewardAmount.emplace_back(achievementDefs.at(i)->RewardAmount.at(j));
                achievementDefs.emplace_back(achievementDefinition);
            }
        }

        delete achievementDefinition;




    }

    // Some other related code.
}