#include "core/transform2D.h"

namespace Horrific::Core
{
    Transform2D::Transform2D(Vector2 position, float rotation)
    {
        m_Position = position;
        m_Rotation = rotation;
    }

    Component *Transform2DParser::Parse(json &data)
    {
        json posJSON = data["position"];
        Vector2 position;
        position.x = posJSON["x"].get<float>();
        position.y = posJSON["y"].get<float>();
        float rotation = data["rotation"].get<float>();
        return (Component*) new Transform2D(position, rotation);
    }
}
