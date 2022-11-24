#pragma once

#include <vector>

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
        
        // Some other related code.
        
        private:
        std::vector<const Achievement::AchievementDefinition*> achievementDefs;
        // Some other related code.
    };
}