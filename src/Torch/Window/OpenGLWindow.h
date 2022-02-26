//
// Created by fgdou on 2/26/22.
//

#ifndef SANDBOX_OPENGLWINDOW_H
#define SANDBOX_OPENGLWINDOW_H

#include "Window.h"
#include "GLFW/glfw3.h"
#include <string>

namespace Torch{
    class OpenGLWindow : public Window{
    public:
        OpenGLWindow(int height, int width, const std::string& name);
        ~OpenGLWindow() override;

        void swapBuffers() override;
        void setVSync(bool active) override;
        void pollEvents() override;

    private:
        void setCallbacks();

        GLFWwindow* window;
    };
}


#endif //SANDBOX_OPENGLWINDOW_H
