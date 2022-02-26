//
// Created by fgdou on 2/24/22.
//

#include "Window.h"
#include "Context/Context.h"
#include "OpenGLWindow.h"

namespace Torch{

    Window::Window(int height, int width)
        : height(height), width(width)
    {}

    int Window::getHeight() {
        return height;
    }

    int Window::getWidth() {
        return width;
    }

    float Window::getRatio() {
        return (float)width/(float)height;
    }

    Ref<Window> Window::create(int height, int width, const std::string &name) {
        auto state = Context::getEnv();
        if(state == Context::ENV::OPENGL){
            return std::make_shared<OpenGLWindow>(height, width, name);
        }
        ASSERT(false, "env not found");
    }
}