#include "core/gameobj.h"
#include "core/scene.h"
#include "raylib.h"
#include "json.hpp"
#include <algorithm>

namespace Horrific::Core
{
    using json = nlohmann::json;

    Scene::~Scene()
    {
        if (!m_FinalScene)
        {
            for (GameObject *g : m_GameObjects)
            {
                if (!g->Persistent())
                    delete g;
            }
        }
        else
        {
            for (GameObject *g : m_GameObjects)
            {
                delete g;
            }
        }
    }

    Scene::Scene(std::string jsonFileName, std::unordered_map<std::string, IComponentParser*> &parsers)
    {
        const char *data = LoadFileText(jsonFileName.c_str());
        json sceneJson = json::parse(data);

        m_Name = sceneJson["name"].get<std::string>();

        json objs = sceneJson["gameObjects"].array();

        for (json obj : objs)
        {
            std::string name = obj["name"].get<std::string>();
            bool persistent = obj["persistent"].get<bool>();

            json comps = obj["components"].array();

            GameObject *g = new GameObject();
            g->SetName(name);
            g->SetPersistent(persistent);

            for (json comp : comps)
            {
                std::string typeName = comp["type"].get<std::string>();
                Component *c = parsers[typeName]->Parse(comp["data"]);
                g->AddComponent(c);
            }

            m_GameObjects.push_back(g);
        }
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
    
    void Scene::AddGameObjects(const std::vector<GameObject *> &gameObjects)
    {
        for (GameObject *g : gameObjects)
        {
            m_GameObjects.push_back(g);
        }
    }

    void Scene::GetPersistentObject(std::vector<GameObject *> &gameObjects)
    {
        for (GameObject *g : m_GameObjects)
        {
            if (g->Persistent())
                gameObjects.push_back(g);
        }
    }
}
