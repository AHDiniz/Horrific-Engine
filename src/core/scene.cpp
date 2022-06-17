#include "core/gameobj.h"
#include "core/scene.h"
#include "raylib.h"
#include "json.hpp"
#include <algorithm>

namespace Horrific::Core
{
    using json = nlohmann::json;

    Scene::Scene(std::string jsonFileName, std::unordered_map<std::string, IComponentParser*> &parsers)
    {
        const char *data = LoadFileText(jsonFileName.c_str());
        json sceneJson = json::parse(data);

        m_Name = sceneJson["name"].get<std::string>();

        
    }

    void Scene::Start()
    {
        for (GameObject *g : m_GameObjects)
        {
            g->Start();
        }
    }

    void Scene::Update()
    {
        for (GameObject *g : m_GameObjects)
        {
            if (g->Active())
                g->Update();
        }
    }

    void Scene::Render()
    {
        for (GameObject *g : m_GameObjects)
        {
            if (g->Active())
                g->Render();
        }
    }

    void Scene::Finish()
    {
        for (GameObject *g : m_GameObjects)
        {
            g->Finish();
        }
    }

    GameObject *Scene::CreateGameObject()
    {
        GameObject *g = new GameObject();
        m_GameObjects.push_back(g);
        return g;
    }

    GameObject *Scene::FindGameObject(std::string name)
    {
        for (GameObject *g : m_GameObjects)
        {
            if (g->Name() == name)
                return g;
        }
        return nullptr;
    }

    void Scene::GetGameObjects(const std::vector<std::string> names, std::vector<GameObject*> &gameObjects)
    {
        for (GameObject *g : m_GameObjects)
        {
            if (std::count(names.begin(), names.end(), g->Name()))
                gameObjects.push_back(g);
        }
    }
    
    void Scene::AddGameObjects(std::vector<GameObject *> &gameObjects)
    {
        for (GameObject *g : gameObjects)
        {
            m_GameObjects.push_back(g);
        }
    }
}
