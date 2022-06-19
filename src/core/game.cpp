#include "core/game.h"
#include "core/scene.h"
#include "raylib.h"

namespace Horrific::Core
{
    Game *Game::Instance()
    {
        static Game *instance = new Game();
        return instance;
    }

    void Game::Start()
    {
        m_CurrentScene = m_Scenes[0];
        m_CurrentScene->Start();
    }

    void Game::Update()
    {
        m_CurrentScene->Update();
    }

    void Game::Render()
    {
        ClearBackground(BLACK);
        m_CurrentScene->Render();
    }

    void Game::Finish()
    {
        m_CurrentScene->Finish();
    }

    void Game::GoToScene(std::string name)
    {
        for (Scene *s : m_Scenes)
        {
            if (s->Name() == name)
            {
                m_CurrentScene->Finish();
                m_CurrentScene = s;
                m_CurrentScene->Start();
                return;
            }
        }
    }
}
