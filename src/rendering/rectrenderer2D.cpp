#include "rendering/rectrenderer2D.h"

#define RECT_SEGMENTS 64

namespace Horrific::Rendering
{
    RectRenderer2D::RectRenderer2D(Vector2 dimensions, Color color)
    {
        m_Dimensions = dimensions;
        m_Color = color;
    }

    void RectRenderer2D::Start()
    {
        m_Transform = m_GameObject->GetComponent<Core::Transform2D>();
    }

    void RectRenderer2D::Render()
    {
        Vector2 pos = m_Transform->Position();

        Rectangle rect;
        rect.x = pos.x;
        rect.y = pos.y;
        rect.width = m_Dimensions.x;
        rect.height = m_Dimensions.y;

        if (m_JustOutlines)
        {
            if (m_Rounded)
                DrawRectangleRoundedLines(rect, m_Roundness, RECT_SEGMENTS, m_Thickness, m_Color);
            else
                DrawRectangleLinesEx(rect, m_Thickness, m_Color);
        }
        else
        {
            if (m_Rounded)
                DrawRectangleRounded(rect, m_Roundness, RECT_SEGMENTS, m_Color);
            else
                DrawRectangleRec(rect, m_Color);
        }
    }

    Core::Component *RectRenderer2DParser::Parse(json &data)
    {
        json dimensions = data["dimensions"];
        json color = data["color"];

        Vector2 d;
        Color c;

        d.x = dimensions["x"].get<float>();
        d.y = dimensions["y"].get<float>();

        c.r = color["r"].get<int>();
        c.g = color["g"].get<int>();
        c.b = color["b"].get<int>();
        c.a = color["a"].get<int>();

        return (Core::Component*) new RectRenderer2D(d, c);
    }
}
