#ifndef TRANSFORM3D_H_

#define TRANSFORM3D_H_

#include "core/gameobj.h"
#include "raylib.h"
#include "raymath.h"

namespace Horrific::Core
{
    using json = nlohmann::json;

    class Transform3D : public Component
    {
    public:

        Transform3D(Vector3 position, Quaternion rotation, Vector3 scale);
        Transform3D(Vector3 position, Vector3 eulerAngles, Vector3 scale);
        ~Transform3D() = default;

        void Start() override {}
        void Update() override {}
        void Render() override {}
        void Finish() override {}

        inline Vector3 Position() { return m_Transform.translation; }
        inline void SetPosition(Vector3 position) { m_Transform.translation = position; }

        inline Quaternion Rotation() { return m_Transform.rotation; }
        inline void SetRotation(Quaternion rotation) { m_Transform.rotation = rotation; }

        inline Vector3 Scale() { return m_Transform.scale; }
        inline void SetScale(Vector3 scale) { m_Transform.scale = scale; }

        inline Vector3 Euler() { return QuaternionToEuler(m_Transform.rotation); }
        inline void SetEuler(Vector3 euler) { m_Transform.rotation = QuaternionFromEuler(euler.x, euler.y, euler.z); }

    private:

        Transform m_Transform;
    };

    class Transform3DParser : public IComponentParser
    {
    public:
        Component *Parse(json &data) override;
    };
}

#endif
