#pragma once

#include <vector>
#include <string>
#include "PlayerDataHandler.h"
#include <map>


namespace Achievement
{
    class AchievementDefinition;
}

namespace Data
{
    // A dedicated data-container class holding all the required game data
    class DataContainer
    {
        public:
        DataContainer();
        /**
         *@brief Constant for keeping how many taps need to get a score
         **/
        static constexpr int k_number_of_taps_to_score{5};
        /**
         *@brief Constant for keeping how many scores need to get a win
         **/
        static constexpr int k_number_of_scores_to_win{3};
        // Some other related code.
        const std::vector<const Achievement::AchievementDefinition*>& GetAchievementDefinitions()const ;
        const void SetAchievementDefinitions(std::vector<const Achievement::AchievementDefinition*>);
        std::vector<Achievement::AchievementDefinition*>& GetParsedAchivementDefinitions();
        /**
         *@brief This function converts First, Second, and Third onto 1st, 2nd, 3rd
         *@param achievementDefs Achivements to be parsed.
         **/
        void AchivementsOrdinalParser(std::vector<const Achievement::AchievementDefinition*>& achievementDefs);
        /**
         *@brief This Function Parse achivements onto maps which are TapRewards, ScoreRewards and WinRewards.
         */
        void AchivementParser();
        /**
         *@brief This function counts currencies
         *@param amount Amount of Reward.
         *@param rewardType Type of Reward.
         **/
        void RewardCounter(int amount, std::map<int, std::string> rewardType);

        Achievement::AchievementDefinition *achievementDefinition;
        PlayerDataHandler m_player_data_handler;
        std::map<int, std::string> TapRewards;
        std::map<int, std::string> ScoreRewards;
        std::map<int, std::string> WinRewards;

        
        // Some other related code.
        
        private:
        std::vector<const Achievement::AchievementDefinition*> achievementDefs;
        std::vector<Achievement::AchievementDefinition*> parsedAchievementDefs;
        // Some other related code.
    };
}