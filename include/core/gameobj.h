#ifndef GAMEOBJ_H_

#define GAMEOBJ_H_

#include "pch.h"

namespace Horrific::Core
{
    class json;
    class GameObject;

    class Component
    {
    public:

        virtual void Start() = 0;
        virtual void Update() = 0;
        virtual void Render() = 0;
        virtual void Finish() = 0;

        inline bool Enabled() { return m_Enabled; }
        inline void SetEnabled(bool enabled) { m_Enabled = enabled; }

    protected:

        friend class GameObject;

        bool m_Enabled;
        GameObject *m_GameObject;
    };

    class IComponentParser
    {
    public:
        virtual Component *Parse(json &data) = 0;
    };

    class GameObject
    {
    public:

        GameObject() = default;
        ~GameObject() = default;

        void Start();
        void Update();
        void Render();
        void Finish();

        inline bool Active() { return m_Active; }
        inline void SetActive(bool active) { m_Active = active; }

        inline bool Persistent() { return m_Persistent; }
        inline void SetPersistent(bool persistent) { m_Persistent = persistent; }

        inline std::string Name() { return m_Name; }
        inline void SetName(std::string name) { m_Name = name; }

        inline void AddComponent(Component *c)
        {
            c->m_GameObject = this;
            m_Components.push_back(c);
        }

        inline const std::vector<Component*> &Components() const { return m_Components; }

        template<typename T>
        T *GetComponent()
        {
            for (Component *c : m_Components)
            {
                T *t = dynamic_cast<T *>(c);
                if (t != nullptr)
                    return t;
            }
            return nullptr;
        }

        template<typename T>
        void GetComponents(std::vector<T *> &components)
        {
            for (Component *c : m_Components)
            {
                T *t = dynamic_cast<T *>(c);
                if (t != nullptr)
                    components.push_back(t);
            }
        }

    private:

        std::vector<Component*> m_Components;
        std::string m_Name;
        bool m_Active;
        bool m_Persistent = false;
    };
}

#endif
