#include "rendering/sprites.h"
#include "core/transform2D.h"

namespace Horrific::Rendering
{
    SpriteSheetRenderer::SpriteSheetRenderer(std::string sheetFileName, int width, int height, int countX, int countY)
    {
        m_SheetFileName = sheetFileName;
        m_Rect.width = width;
        m_Rect.height = height;
        m_CountX = countX;
        m_CountY = countY;

        m_Texture = LoadTexture(m_SheetFileName.c_str());
    }

    void SpriteSheetRenderer::Start()
    {
    	m_Transform = m_GameObject->GetComponent<Core::Transform2D>();
    }

    void SpriteSheetRenderer::Render()
    {
        Rectangle source, destination;

        source.x = m_CurrentSprite % m_CountX;
        source.y = m_CurrentSprite / m_CountX;

        Vector2 pos = m_Transform->Position();
        destination.x = pos.x;
        destination.y = pos.y;

        source.width = destination.width = m_Width;
        source.height = destination.height = m_Height;

        DrawTexturePro(m_Texture, source, destination, pos, m_Transform->Rotation(), m_Color);
    }

    void SpriteSheetRenderer::Finish()
    {
    	UnloadTexture(m_Texture);
    }

    Core::Component *SpriteSheetRendererParser::Parse(json &data)
    {
        std::string sheetFileName = data["sheetFileName"].get<std::string>();
        int width = data["width"].get<int>();
        int height = data["height"].get<int>();
        int countX = data["countX"].get<int>();
        int countY = data["countY"].get<int>();
        
        return (Core::Component*) new SpriteSheetRenderer(sheetFileName, width, height, countX, countY);
    }
}
