#pragma once
#include <iostream>
#include <stdio.h>
#include "curses.h"
#include "SimpleGameTypes.h"

namespace Interaction
{
    // A class whose instance is generated when 
    // the player triggers a tapping action
    class Tap
    {
    public:
        inline GameTypes::eGameSide WhoIsTapped()
        {
            char tap;
            if(tap == '\n')
            {
                return GameTypes::eGameSide::PLAYER;
            } else if (tap == '\t')
            {
                return GameTypes::eGameSide::OPPONENT;
            } else {
                return GameTypes::eGameSide::UNDEFINIED;
            }
        }
    };
}