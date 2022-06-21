#include "rendering/sprites.h"

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
    	
    }

    void SpriteSheetRenderer::Render()
    {
	
    }

    void SpriteSheetRenderer::Finish()
    {
    	UnloadTexture(m_Texture);
    }
}
