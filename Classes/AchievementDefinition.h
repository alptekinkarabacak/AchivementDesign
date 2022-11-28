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
        std::map<int, std::string> TapRewards;
        std::map<int, std::string> ScoreRewards;
        std::map<int, std::string> WindRewards;

        inline void OrdinalParser() {
            for (auto & reward: RewardTypes) {
                size_t position = reward.find("First");
                if (position != std::string::npos) {
                    size_t  position_of_space = reward.find(" ");
                    reward.erase(0, position_of_space);
                    reward.insert(0, "1st");
                } else {
                    position = reward.find("Second");
                    if (position != std::string::npos) {
                        size_t  position_of_space = reward.find(" ");
                        reward.erase(0, position_of_space);
                        reward.insert(0, "2st");
                    } else{
                        position = reward.find("Third");
                        if (position != std::string::npos) {
                            size_t  position_of_space = reward.find(" ");
                            reward.erase(0, position_of_space);
                            reward.insert(0, "3st");
                        }
                    }
                }
            }
        }

        inline void AchivementParser() {
            for (int i{0}; i < RewardTypes.size(); ++i) {
                size_t position = RewardTypes.at(i).find("tap");
                if (position != std::string::npos) {
                    std::pair<int, std::string> tapReward;
                    tapReward.first = std::stoi(RewardTypes.at(i).substr(0, position - 3));
                    tapReward.second = RewardAmount.at(i);
                    TapRewards.insert(tapReward);
                } else {
                    position = RewardTypes.at(i).find("score");
                    if (position != std::string::npos) {
                        std::pair<int, std::string> scoreReward;
                        scoreReward.first = std::stoi(RewardTypes.at(i).substr(0, position - 3));
                        scoreReward.second = RewardAmount.at(i);
                        ScoreRewards.insert(scoreReward);
                    } else {
                        position = RewardTypes.at(i).find("win");
                        if (position != std::string::npos) {
                            std::pair<int, std::string> winReward;
                            winReward.first = std::stoi(RewardTypes.at(i).substr(0, position - 3));
                            winReward.second = RewardAmount.at(i);
                            WindRewards.insert(winReward);
                        }
                    }
                }
            }
        }
    };
}