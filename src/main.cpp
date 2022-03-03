#include "pch.h"
#include "glad.h"
#include "glfw3.h"
#include "core/memory.h"
#include "core/app.h"

int main(int argc, char *argv[])
{
    App app;

    bool result = AppInit(&app, 800, 600, "Horrific Engine");

    if (!result)
        return EXIT_FAILURE;

    while (!AppShouldClose(&app))
    {
        AppUpdate(&app, 1);
        AppRender(&app, 1);
    }

    AppFinish(&app);
    return EXIT_SUCCESS;
}
