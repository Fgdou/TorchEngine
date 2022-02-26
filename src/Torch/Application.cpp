//
// Created by fgdou on 2/26/22.
//

#include "Application.h"
#include "Events/WindowCloseEvent.h"

Torch::Application::Application(int width, int height, const std::string &name)
    : window(Window::create(height, width, name))
{

}

void Torch::Application::run() {
    window->registerEventCallback([&](Event& e){ event(e); });
    onInit();
    while(!shouldQuit){
        onUpdate();
        onDraw();
        window->swapBuffers();
        window->pollEvents();
    }
    onClose();
}

void Torch::Application::quit() {
    shouldQuit = true;
}

void Torch::Application::event(Torch::Event &e) {
    Dispatcher d(e);
    auto res = d.dispatch<WindowCloseEvent>([&](WindowCloseEvent& e){
        shouldQuit = true;
    });
    if(!res)
        onEvent(e);
}
