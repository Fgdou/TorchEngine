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

    int Window::getHeight() const {
        return height;
    }

    int Window::getWidth() const {
        return width;
    }

    float Window::getRatio() const {
        return (float)width/(float)height;
    }

    Ref<Window> Window::create(int height, int width, const std::string &name) {
        auto state = Context::getEnv();
        if(state == Context::ENV::OPENGL){
            return std::make_shared<OpenGLWindow>(height, width, name);
        }
        ASSERT(false, "env not found");
    }

    void Window::registerEventCallback(const std::function<void(Event &)>& f) {
        callback = f;
    }

    void Window::sendEvent(Event &e) {
        callback(e);
    }
}