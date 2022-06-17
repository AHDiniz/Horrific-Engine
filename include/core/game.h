#ifndef GAME_H_

#define GAME_H_

#include "pch.h"

namespace Horrific::Core
{
    class Scene;

    class Game
    {
    public:
        static Game *Instance();
        ~Game();

        void Start();
        void Update();
        void Render();
        void Finish();

        inline Scene *CurrentScene() { return m_CurrentScene; }

        void GoToScene(std::string name);
    
    private:
        
        Game() = default;
        std::vector<Scene*> m_Scenes;
        Scene *m_CurrentScene;
    };
}

#endif