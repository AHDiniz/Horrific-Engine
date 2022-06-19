#ifndef SCENE_H_

#define SCENE_H_

#include "pch.h"

namespace Horrific::Core
{
    class GameObject;
    class IComponentParser;

    class Scene
    {
    public:

        Scene(std::string jsonFileName, std::unordered_map<std::string, IComponentParser*> &parsers);
        ~Scene();

        void Start();
        void Update();
        void Render();
        void Finish();

        GameObject *CreateGameObject();
        GameObject *FindGameObject(std::string name);

        inline std::string Name() { return m_Name; }
        inline void SetName(std::string name) { m_Name = name; }

        inline bool FinalScene() { return m_FinalScene; }
        inline void SetFinalScene(bool finalScene) { m_FinalScene = finalScene; }

        void AddGameObjects(const std::vector<GameObject *> &gameObjects);
        void GetPersistentObject(std::vector<GameObject *> &gameObjects);

    private:

        std::vector<GameObject *> m_GameObjects;
        std::string m_Name;
        bool m_FinalScene;
    };
}

#endif