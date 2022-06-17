#include "core/game.h"

namespace Horrific::Core
{
    Game *Game::Instance()
    {
        static Game *instance = new Game();
        return instance;
    }

    
}
