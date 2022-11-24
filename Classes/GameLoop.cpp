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
        // Runs some related and required code.
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