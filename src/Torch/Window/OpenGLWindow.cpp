//
// Created by fgdou on 2/26/22.
//

#include "OpenGLWindow.h"
#include "Context/Context.h"

namespace Torch{

    static bool glfwInited = false;

    OpenGLWindow::OpenGLWindow(int height, int width, const std::string &name)
            : Window(height, width), window(nullptr)
    {
        if(!glfwInited){
            LOG_INFO("Init glfw");
            auto res = glfwInit();
            ASSERT(res == GLFW_TRUE, "failed to init glfw");
            glfwInited = true;
        }

        LOG_INFO("Create glfw window %s(%dx%d)", name.c_str(), width, height);
        window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
        ASSERT(window != nullptr, "failed to create window");

        glfwMakeContextCurrent(window);

        setVSync(true);

        Context::create();
    }

    OpenGLWindow::~OpenGLWindow() {
        if(window != nullptr)
            glfwDestroyWindow(window);
        LOG_INFO("Destroy glfw window");
    }

    void OpenGLWindow::swapBuffers() {
        glfwSwapBuffers(window);
    }

    void OpenGLWindow::setVSync(bool active) {
        glfwSwapInterval((active) ? 1 : 0);
    }

    void OpenGLWindow::pollEvents() {
        glfwPollEvents();
    }
}


