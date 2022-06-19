#ifndef TRANSFORM2D_H_

#define TRANSFORM2D_H_

#include "core/gameobj.h"
#include "raylib.h"

namespace Horrific::Core
{
    class Transform2D : public Component
    {
    public:

        Transform2D(Vector2 position, float rotation);
        ~Transform2D() = default;

        void Start() override {}
        void Update() override {}
        void Render() override {}
        void Finish() override {}

        inline Vector2 Position() { return m_Position; }
        inline void SetPosition(Vector2 position) { m_Position = position; }

        inline float Rotation() { return m_Rotation; }
        inline void SetRotation(float rotation) { m_Rotation = rotation; }

    private:

        Vector2 m_Position;
        float m_Rotation;
    };
}

#endif