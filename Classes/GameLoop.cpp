#include "GameLoop.h"

namespace Game
{
    void GameLoop::ReceiveData(Data::DataContainer& data)
    {
      this->m_data_container = data;
      std::vector<const Achievement::AchievementDefinition*> achievementDefs;
      achievementDefs = m_data_container.GetAchievementDefinitions();
      m_data_container.AchivementsOrdinalParser(achievementDefs);
      m_data_container.AchivementParser();
    }

    void GameLoop::Run()
    {
        Interaction::Tap tap;
        this->OnTap(tap);
        while(true) {


        }
    }
        
    void GameLoop::OnTap(const Interaction::Tap& tap)
    {
         ++m_data_container.m_player_data_handler.tap_count;
         m_data_container.TapRewardCounter(m_data_container.m_player_data_handler);


    }
    void GameLoop::OnScore(const int score, const GameTypes::eGameSide)
    {
        
    }
    void GameLoop::OnMatchResult(const GameTypes::eGameSide)
    {
        
    }
}