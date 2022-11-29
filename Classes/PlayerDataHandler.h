#pragma once

#include "SimpleGameTypes.h"

namespace Data
{
    class PlayerDataHandler
    {
        public:
        // Some other related code.
        
        // It is used for updating a dedicated hard currency owned by the player
        inline void SetCurrency(const int amount, const GameTypes::eCurrencyType type) {
            if(type == GameTypes::eCurrencyType::DIAMOND)
            {
                total_diamond += amount;
            } else if (type == GameTypes::eCurrencyType::GOLD)
            {
                total_gold += amount;
            }
        }
        int tap_count{0};
        int score_count{0};
        int win_count{0};

        private:
          int total_gold{0};
          int total_diamond{0};
        // Some other related codeç.
    };
}