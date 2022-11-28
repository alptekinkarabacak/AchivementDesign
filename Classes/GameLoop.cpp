#include "GameLoop.h"

namespace Game
{
    void GameLoop::ReceiveData(Data::DataContainer& data)
    {
      this->m_data_container = data;
        // Triggers some related code to get and set the game data
    }

    void GameLoop::Run()
    {
        while(true) {
            m_tap.WhoIsTapped();
            if(m_tap.m_who_is_tapped != GameTypes::eGameSide::UNDEFINIED) {
                OnTap(m_tap);
            }
        }
    }
        
    void GameLoop::OnTap(const Interaction::Tap& tap)
    {
        if(tap.m_who_is_tapped == GameTypes::eGameSide::PLAYER) {
            ++m_data_container.m_player_data_handler.tap_count;
        } else if(tap.m_who_is_tapped == GameTypes::eGameSide::OPPONENT) {
            std::cout<<"Opponent has tapped\n";
            ++m_data_container.m_opponent_data_handler.tap_count;
        }

    }
    void GameLoop::OnScore(const int score, const GameTypes::eGameSide)
    {
        
    }
    void GameLoop::OnMatchResult(const GameTypes::eGameSide)
    {
        
    }
}