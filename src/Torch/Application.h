//
// Created by fgdou on 2/26/22.
//

#ifndef SANDBOX_APPLICATION_H
#define SANDBOX_APPLICATION_H

#include "torch.h"
#include <string>
#include "Window/Window.h"

namespace Torch{
    class Application {
    public:
        Application(int width, int height, const std::string& name);
        ~Application() = default;

        void run();
        virtual void onUpdate() = 0;
        virtual void onDraw() = 0;
        virtual void onInit() = 0;
        virtual void onEvent(Event& event) = 0;
        virtual void onClose() = 0;

        void quit();

    private:
        void event(Event& e);
        bool shouldQuit = false;
        Ref<Window> window;
    };
}


#endif //SANDBOX_APPLICATION_H
