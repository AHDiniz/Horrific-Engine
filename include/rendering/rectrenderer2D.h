#ifndef RECT_RENDERER_2D_H_

#define RECT_RENDERER_2D_H_

#include "core/gameobj.h"
#include "core/transform2D.h"
#include "raylib.h"

namespace Horrific::Rendering
{
    class RectRenderer2D : public Core::Component
    {
    public:

        RectRenderer2D(Vector2 dimensions, Color color);
        ~RectRenderer2D() = default;

        inline bool JustOutlines() { return m_JustOutlines; }
        inline void SetJustOutlines(bool justOutlines) { m_JustOutlines = justOutlines; }

        inline bool Rounded() { return m_Rounded; }
        inline void SetRounded(bool rounded) { m_Rounded = rounded; }

        inline float Roundness() { return m_Roundness; }
        inline void SetRoundness(float roundness) { m_Roundness = roundness; }

        inline Color GetColor() { return m_Color; }
        inline void SetColor(Color color) { m_Color = color; }

        inline float Thickness() { return m_Thickness; }
        inline void SetThinkness(float thickness) { m_Thickness = thickness; }

        void Start() override;
        void Update() override {}
        void Render() override;
        void Finish() override {}

    private:

        bool m_JustOutlines = false, m_Rounded = false;
        float m_Roundness, m_Thickness;
        Vector2 m_Dimensions;
        Color m_Color;
        Core::Transform2D *m_Transform;
    };
}

#endif
