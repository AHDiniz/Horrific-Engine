#ifndef APP_H_

#define APP_H_

struct GLFWwindow;

typedef struct app
{
    void *memCache;
    GLFWwindow *window;
} App;

bool AppInit(App *app, int width, int height, const char *name);
bool AppShouldClose(App *app);
void AppUpdate(App *app, float deltaTime);
void AppRender(App *app, float aspectRatio);
void AppFinish(App *app);

#endif
