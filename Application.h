#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include <stack>
#include <memory>

#include "Renderer/Master.h"
#include "Camera.h"

class Application
{
    public:
        Application();

        void runMainGameLoop();
    private:
        Renderer::Master m_renderer;
        Camera m_camera;
};

#endif // APPLICATION_H_INCLUDED
