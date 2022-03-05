#include "pch.h"
#include "core/app.h"
#include "glad.h"
#include "glfw3.h"

float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

unsigned int vbo, vao;

unsigned int shaderProgram;

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

    glGenBuffers(1, &vbo);
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    FILE *vertexShaderFile = fopen("assets/shaders/vertex.glsl", "r");
    char vertexStr[256];
    while (!feof(vertexShaderFile))
    {
        fread(vertexStr, sizeof(vertexStr), 1, vertexShaderFile);
    }

    fclose(vertexShaderFile);

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, (const char * const*)&vertexStr, nullptr);
    glCompileShader(vertexShader);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)nullptr);
    glEnableVertexAttribArray(0);

    int vertexSuccess;
    char vertexLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vertexSuccess);

    if (!vertexSuccess)
    {
        glGetShaderInfoLog(vertexShader, 512, nullptr, vertexLog);
        printf("Error in vertex shader compilation: %s\n", vertexLog);
    }

    FILE *fragShaderFile = fopen("assets/shaders/fragment.glsl", "r");
    char fragStr[256];
    while (!feof(fragShaderFile))
    {
        fread(fragStr, sizeof(fragStr), 1, fragShaderFile);
    }

    fclose(fragShaderFile);

    unsigned int fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, (const char * const*)&fragStr, nullptr);
    glCompileShader(fragShader);

    int fragSuccess;
    char fragLog[512];
    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &fragSuccess);

    if (!fragSuccess)
    {
        glGetShaderInfoLog(fragShader, 512, nullptr, fragLog);
        printf("Error in fragment shader compilation: %s\n", fragLog);
    }

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragShader);
    glLinkProgram(shaderProgram);

    int linkSuccess;
    char linkLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &linkSuccess);
    if (!linkSuccess)
    {
        glGetProgramInfoLog(shaderProgram, 512, nullptr, linkLog);
        printf("Error in shader program linking: %s\n", linkLog);
    }

    glUseProgram(shaderProgram);
    glBindVertexArray(vao);

    glDeleteShader(vertexShader);
    glDeleteShader(fragShader);

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

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(app->window);
    glfwPollEvents();
}

void AppFinish(App *app)
{
    glfwTerminate();
}
