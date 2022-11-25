#include "DataContainer.h"

#include "AchievementDefinition.h"

namespace Data
{
    // Some other related code.
    const std::vector<const Achievement::AchievementDefinition*>& DataContainer::GetAchievementDefinitions()
    {
        return achievementDefs;
    }
    const void DataContainer::SetAchievementDefinitions(
        std::vector<const Achievement::AchievementDefinition *>) {
      return;
    }

    // Some other related code.
}