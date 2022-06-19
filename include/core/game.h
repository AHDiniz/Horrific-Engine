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

        inline void SetName(std::string name) { m_Name = name; }
        inline std::string Name() { return m_Name; }

        inline void SetWidth(int width) { m_Width = width; }
        inline int Width() { return m_Width; }

        inline void SetHeight(int height) { m_Height = height; }
        inline int Height() { return m_Height; }

        void GoToScene(std::string name);
    
    private:
        
        Game() = default;
        
        std::vector<Scene*> m_Scenes;
        std::string m_Name;
        Scene *m_CurrentScene;
        int m_Width, m_Height;
    };
}

#endif