#include "core/transform2D.h"

namespace Horrific::Core
{
    Transform2D::Transform2D(Vector2 position, float rotation)
    {
        m_Position = position;
        m_Rotation = rotation;
    }
}
