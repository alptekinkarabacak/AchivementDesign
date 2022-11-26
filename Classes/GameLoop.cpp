#include "GameLoop.h"

#include "DataContainer.h"
#include "Tap.h"

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
            GameTypes::eGameSide a = GameTypes::eGameSide::UNDEFINIED;
            if (m_tap.WhoIsTapped() == GameTypes::eGameSide::PLAYER)
            {
                ++m_data_container.m_opponent_data_handler.tap_count;
                        std::cout<<"Player Pressed\n";

            } else if (m_tap.WhoIsTapped() == GameTypes::eGameSide::OPPONENT)
            {
                ++m_data_container.m_opponent_data_handler.tap_count;
                std::cout<<"Opponent Pressed\n";
            } else {
                continue;
            }


        }
    }
        
    void GameLoop::OnTap(const Interaction::Tap& tap)
    {

        
    }
    void GameLoop::OnScore(const int score, const GameTypes::eGameSide)
    {
        
    }
    void GameLoop::OnMatchResult(const GameTypes::eGameSide)
    {
        
    }
}