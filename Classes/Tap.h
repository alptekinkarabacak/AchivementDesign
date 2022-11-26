#pragma once
#include <iostream>
#include <stdio.h>
#include "SimpleGameTypes.h"

namespace Interaction
{
    // A class whose instance is generated when 
    // the player triggers a tapping action
    class Tap
    {
    public:
        GameTypes::eGameSide m_who_is_tapped;
        inline void WhoIsTapped()
        {
            char tap;
            if(tap == '\n')
            {
                m_who_is_tapped = GameTypes::eGameSide::PLAYER;
            } else if (tap == '\t')
            {
                m_who_is_tapped = GameTypes::eGameSide::OPPONENT;
            } else {
                m_who_is_tapped = GameTypes::eGameSide::UNDEFINIED;
            }
        }
    };
}