#ifndef GAME_H_

#define GAME_H_

namespace Horrific::Core
{
    class Game
    {
    public:
        static Game *Instance();
    
    private:
        Game() = default;
    };
}

#endif