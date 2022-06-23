#include <stdio.h>

#include "horrific.h"
#include <unordered_map>

namespace Horrific::Core
{
    void Game::Setup()
    {
        Transform2DParser transform2DParser;
        Transform3DParser transform3DParser;
        
        Rendering::CircleRenderer2DParser circleRenderer2DParser;
        Rendering::RectRenderer2DParser rectRenderer2DParser;
        Rendering::SpriteSheetRendererParser spriteRendererParser;

        std::unordered_map<std::string, IComponentParser*> parsers;
        
        parsers["Transform2D"] = &transform2DParser;
        parsers["Transform3D"] = &transform3DParser;

        parsers["CircleRenderer2D"] = &circleRenderer2DParser;
        parsers["RectRenderer2D"] = &rectRenderer2DParser;
        parsers["SpriteSheetRenderer"] = &spriteRendererParser;

        std::string testFile = "assets/scenes/test.json";
        Scene *testScene = new Scene(testFile, &parsers);

        m_Scenes.push_back(testScene);
    }
}
