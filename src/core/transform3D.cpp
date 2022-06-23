#include "core/transform3D.h"
#include "raymath.h"

namespace Horrific::Core
{
    Transform3D::Transform3D(Vector3 position, Quaternion rotation, Vector3 scale)
    {
        m_Transform.translation = position;
        m_Transform.rotation = rotation;
        m_Transform.scale = scale;
    }

    Transform3D::Transform3D(Vector3 position, Vector3 eulerAngles, Vector3 scale)
    {
        m_Transform.translation = position;
        m_Transform.rotation = QuaternionFromEuler(eulerAngles.x, eulerAngles.y, eulerAngles.z);
        m_Transform.scale = scale;
    }

    Component *Transform3DParser::Parse(json &data)
    {
        json position = data["position"];
        json rotation = data["rotation"];
        json scale = data["scale"];

        Vector3 p, s, r = Vector3Zero();
        p.x = position["x"].get<float>();
        p.y = position["y"].get<float>();
        p.z = position["z"].get<float>();

        s.x = scale["x"].get<float>();
        s.y = scale["y"].get<float>();
        s.z = scale["z"].get<float>();

        Transform3D *t = new Transform3D(p, r, s);

        if (rotation.contains("w"))
        {
            Quaternion rot;
            rot.x = rotation["x"].get<float>();
            rot.y = rotation["y"].get<float>();
            rot.z = rotation["z"].get<float>();
            rot.w = rotation["w"].get<float>();
            t->SetRotation(rot);
        }
        else
        {
            r.x = rotation["x"].get<float>();
            r.y = rotation["y"].get<float>();
            r.z = rotation["z"].get<float>();
            t->SetEuler(r);
        }

        return (Component *) t;
    }
}
