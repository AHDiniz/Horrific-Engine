#include "core/transform3D.h"

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
}
