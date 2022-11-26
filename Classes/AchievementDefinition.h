#pragma once

#include <string>
#include <vector>
#include <map>
#include <sstream>

namespace Achievement
{
    // A data class holding the definition of an achievement.
    class AchievementDefinition
    {
        public:
        std::string ImagePath = "";
        std::string Title = "";
        std::string Text = "";
        // RewardTypes and RewardAmounts map one to one, which means
        // RewardTypes[0] has its reward amount at RewardAmount[0],
        // RewardTypes[1] has its reward amount at RewardAmount[1],
        // and so on.
        std::vector<std::string> RewardTypes;
        std::vector<std::string> RewardAmount;
        std::map<std::string, int> m_AchivementLookUpTable{{"First", 1}, {"Second", 2}, {"Third", 3}};
        std::vector<std::tuple<int, int, GameTypes::eCurrencyType>> m_rewards;

        inline std::tuple<int, int, GameTypes::eCurrencyType> ParseRewards(){
            std::istringstream reward;
            for(auto rewards : RewardTypes) {
                reward = rewards.front();

            }
            reward = RewardTypes
        }

    };
}