#pragma once

#include <vector>
#include "PlayerDataHandler.h"

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
        // Some other related code.
        const std::vector<const Achievement::AchievementDefinition*>& GetAchievementDefinitions();
        const void SetAchievementDefinitions(std::vector<const Achievement::AchievementDefinition*>);
        PlayerDataHandler m_player_data_handler;
        PlayerDataHandler m_opponent_data_handler;
        
        // Some other related code.
        
        private:
        std::vector<const Achievement::AchievementDefinition*> achievementDefs;
        // Some other related code.
    };
}