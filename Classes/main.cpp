#include "GameLoop.h"
#include "DataContainer.h"
#include "AchievementDefinition.h"
#include "iostream"

int main()
{
    Game::GameLoop gameLoop;
    Data::DataContainer theWholeData;
    Achievement::AchievementDefinition *achievementDefinition = new Achievement::AchievementDefinition();
    std::vector<const Achievement::AchievementDefinition*> achivements;
    achievementDefinition->ImagePath = "asdad";
    achievementDefinition->RewardTypes.emplace_back("First tap");
    achievementDefinition->RewardAmount.emplace_back("500 diamonds and 500 golds");
    achievementDefinition->RewardTypes.emplace_back("100th tap");
    achievementDefinition->RewardAmount.emplace_back("500 gold");
    achievementDefinition->RewardTypes.emplace_back("First score");
    achievementDefinition->RewardAmount.emplace_back("500 gold and 5 Diamonds");
    achievementDefinition->RewardTypes.emplace_back("First win");
    achievementDefinition->RewardAmount.emplace_back("15 Diamonds");
    achivements.emplace_back(achievementDefinition);
    theWholeData.SetAchievementDefinitions(achivements);
    gameLoop.ReceiveData(theWholeData);
    
    gameLoop.Run();

    return 0;
}
