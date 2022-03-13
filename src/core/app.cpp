#include "pch.h"
#include "core/app.h"
#include "glad.h"
#include "glfw3.h"

float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

void FrameBufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

bool AppInit(App *app, int width, int height, const char *name)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    app->window = glfwCreateWindow(width, height, name, nullptr, nullptr);

    if (!app->window)
    {
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(app->window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        return false;
    }

    glfwSetFramebufferSizeCallback(app->window, FrameBufferSizeCallback);

    return true;
}

bool AppShouldClose(App *app)
{
    return glfwWindowShouldClose(app->window);
}

void AppUpdate(App *app, float deltaTime)
{
    if (glfwGetKey(app->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(app->window, true);
}

void AppRender(App *app, float aspectRatio)
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(app->window);
    glfwPollEvents();
}

void AppFinish(App *app)
{
    glfwTerminate();
}
