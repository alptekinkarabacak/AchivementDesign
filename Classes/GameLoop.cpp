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
        // For Testing
        this->OnTap(tap);
        this->OnTap(tap);
        this->OnTap(tap);
        this->OnTap(tap);
        this->OnTap(tap);
        this->OnTap(tap);
        this->OnTap(tap);
        this->OnTap(tap);
        this->OnTap(tap);
        this->OnTap(tap);
        this->OnTap(tap);
        this->OnTap(tap);
        this->OnTap(tap);
        this->OnTap(tap);
        this->OnTap(tap);
        this->OnTap(tap);
    }
        
    void GameLoop::OnTap(const Interaction::Tap& tap)
    {
         ++(m_data_container.m_player_data_handler.tap_count);
         if(m_data_container.m_player_data_handler.tap_count % m_data_container.k_number_of_taps_to_score == 0) {
             OnScore(m_data_container.m_player_data_handler.score_count, GameTypes::eGameSide::PLAYER);
         }

         m_data_container.RewardCounter(m_data_container.m_player_data_handler.tap_count, m_data_container.TapRewards);
    }
    void GameLoop::OnScore(const int score, const GameTypes::eGameSide)
    {
        ++(m_data_container.m_player_data_handler.score_count);
        if(m_data_container.m_player_data_handler.score_count % m_data_container.k_number_of_scores_to_win == 0) {
            OnMatchResult(GameTypes::eGameSide::PLAYER);
        }

        m_data_container.RewardCounter(m_data_container.m_player_data_handler.score_count, m_data_container.ScoreRewards);

    }
    void GameLoop::OnMatchResult(const GameTypes::eGameSide)
    {
        ++(m_data_container.m_player_data_handler.win_count);
        m_data_container.RewardCounter(m_data_container.m_player_data_handler.win_count, m_data_container.WinRewards);
        std::cout<<"**** Game is Finished ****\n";
        std::cout<<"The Total Gold of the Player is: ";
        std::cout<<m_data_container.m_player_data_handler.total_gold<<"\n";
        std::cout<<"The Total Diamond of the Player is: ";
        std::cout<<m_data_container.m_player_data_handler.total_diamond<<"\n";
    }
}