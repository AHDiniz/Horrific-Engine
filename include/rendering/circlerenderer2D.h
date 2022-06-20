#ifndef CIRCLE_RENDERER_2D_H_

#define CIRCLE_RENDERER_2D_H_

#include "core/gameobj.h"
#include "raylib.h"

namespace Horrific::Core
{
    class Transform2D;
}

namespace Horrific::Rendering
{
    class CircleRenderer2D : public Core::Component
    {
    public:
    
        CircleRenderer2D(float radius, Color color);
        ~CircleRenderer2D() = default;

        inline bool IsOutline() { return m_IsOutline; }
        inline void SetIsOutline(bool isOutline) { m_IsOutline = isOutline; }

        inline bool IsSector() { return m_IsSector; }
        inline void SetIsSector(bool isSector) { m_IsSector = isSector; }

        inline Vector2 Angles() { return m_Angles; }
        inline void SetAngles(Vector2 angles) { m_Angles = angles; }

        inline float Radius() { return m_Radius; }
        inline void SetRadius(float radius) { m_Radius = radius; }

        inline Color GetColor() { return m_Color; }
        inline void SetColor(Color color) { m_Color = color; }

        void Start() override;
        void Update() override {}
        void Render() override;
        void Finish() override {}

    private:

        bool m_IsOutline = false, m_IsSector = false;
        float m_Radius;
        Color m_Color;
        Vector2 m_Angles;
        Core::Transform2D *m_Transform;
    };
}

#endif
