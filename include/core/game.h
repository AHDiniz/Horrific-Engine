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

        void Setup();

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

        inline std::string GamePath() { return m_GamePath; }
        inline void SetGamePath(std::string gamePath) { m_GamePath = gamePath; }

        void GoToScene(std::string name);
    
    protected:
        
        static Game *s_Instance;

        Game() = default;
        
        std::vector<Scene*> m_Scenes;
        std::string m_Name;
        std::string m_GamePath;
        Scene *m_CurrentScene;
        int m_Width, m_Height;
    };
}

#endif