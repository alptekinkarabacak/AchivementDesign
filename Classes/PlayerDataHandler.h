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
        int tap_count;

        private:
          int total_gold;
          int total_diamond;
        // Some other related codeç.
    };
}