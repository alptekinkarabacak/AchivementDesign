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



    // Some other related code.
}