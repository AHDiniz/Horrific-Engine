#ifndef SPRITES_H_

#define SPRITES_H_

#include "core/gameobj.h"
#include "raylib.h"
#include <string>

namespace Horrific::Rendering
{
	using json = nlohmann::json;

	class Core::Transform2D;

    class SpriteSheetRenderer : public Core::Component
    {
    public:
	
		SpriteSheetRenderer(std::string sheetFileName, int width, int height, int countX, int countY);
		~SpriteSheetRenderer() = default;

		void Start() override;
		void Update() override {}
		void Render() override;
		void Finish() override;
		
		inline int CurrentSprite() { return m_CurrentSprite; }
		inline void SetCurrentSprite(int currentSprite) { m_CurrentSprite = currentSprite; }

		inline int Width() { return m_Rect.width; }
		inline void SetWidth(int width) { m_Rect.width = width; }

		inline int Height() { return m_Rect.height; }
		inline void SetHeight(int height) { m_Rect.height = height; }

		inline Color GetColor() { return m_Color; }
		inline void SetColor(Color color) { m_Color = color; }

	private:

		std::string m_SheetFileName;
		int m_Width, m_Height;
		int m_CountX, m_CountY;
		int m_CurrentSprite;
		Color m_Color = WHITE;
		Texture m_Texture;
		Rectangle m_Rect;
		Core::Transform2D *m_Transform;
    };

	class SpriteSheetRendererParser : public Core::IComponentParser
	{
	public:
		Core::Component *Parse(json &data) override;
	};
}

#endif
