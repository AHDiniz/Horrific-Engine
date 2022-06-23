#include "pch.h"
#include "core/game.h"
#include "raylib.h"

using namespace Horrific;

int main(int argc, char *argv[])
{
    Core::Game *game = Core::Game::Instance();

    game->Setup();

    game->Start();

    InitWindow(game->Width(), game->Height(), (game->Name()).c_str());

    while (!WindowShouldClose())
    {
        game->Update();

        BeginDrawing();
        {
            game->Render();
        }
        EndDrawing();
    }

    game->Finish();

    return EXIT_SUCCESS;
}
