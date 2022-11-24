#include "DataContainer.h"

#include "AchievementDefinition.h"

namespace Data
{
    // Some other related code.
    const std::vector<const Achievement::AchievementDefinition*>& DataContainer::GetAchievementDefinitions()
    {
        return achievementDefs;
    }
    // Some other related code.
}