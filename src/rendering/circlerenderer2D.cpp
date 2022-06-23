#include "rendering/circlerenderer2D.h"
#include "core/transform2D.h"
#include "raylib.h"

#define CIRCLE_SEGMENTS 256

namespace Horrific::Rendering
{
    CircleRenderer2D::CircleRenderer2D(float radius, Color color)
    {
        m_Radius = radius;
        m_Color = color;
    }

    void CircleRenderer2D::Start()
    {
        m_Transform = m_GameObject->GetComponent<Core::Transform2D>();
    }

    void CircleRenderer2D::Render()
    {
        Vector2 pos = m_Transform->Position();

        if (m_IsOutline)
        {
            if (m_IsSector)
                DrawCircleSectorLines(pos, m_Radius, m_Angles.x, m_Angles.y, CIRCLE_SEGMENTS, m_Color);
            else
                DrawCircleLines(pos.x, pos.y, m_Radius, m_Color);
        }
        else
        {
            if (m_IsSector)
                DrawCircleSector(pos, m_Radius, m_Angles.x, m_Angles.y, CIRCLE_SEGMENTS, m_Color);
            else
                DrawCircle(pos.x, pos.y, m_Radius, m_Color);
        }
    }

    Core::Component *CircleRenderer2D::Parse(json &data)
    {
        float radius = data["radius"].get<float>();
        json colorJSON = data["color"];
        Color color;
        color.r = colorJSON["r"].get<int>();
        color.g = colorJSON["g"].get<int>();
        color.b = colorJSON["b"].get<int>();
        color.a = colorJSON["a"].get<int>();
        return (Core::Component *) new CircleRenderer2D(radius, color);
    }
}
