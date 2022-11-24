#pragma once

#include "SimpleGameTypes.h"
#include "DataContainer.h"

namespace Data
{
    class DataContainer;
}

namespace Interaction
{
    class Tap;
}

namespace Game
{
    class GameLoop
    {
        public:
        // Some other related code.
        
        void ReceiveData(Data::DataContainer& data);
        void Run(); // Starts the game loop
        
        void OnTap(const Interaction::Tap& tap); // Called when a tapping event happens
        void OnScore(const int score, const GameTypes::eGameSide); // Called when one of the sides scores
        void OnMatchResult(const GameTypes::eGameSide); // Called when the game session finishes
        
        // Some other related code.
        private:
        Data::DataContainer m_data_container;
    };
}