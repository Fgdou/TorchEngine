//
// Created by fgdou on 2/24/22.
//

#ifndef SANDBOX_WINDOW_H
#define SANDBOX_WINDOW_H

#include "torch.h"
#include <functional>
#include "Events/Event.h"

namespace Torch{
    class Window {
    protected:
        Window(int height, int width);
        virtual ~Window() = default;
    public:
        int getHeight() const;
        int getWidth() const;
        float getRatio() const;

        static Ref<Window> create(int height, int width, const std::string& name);

        virtual void setVSync(bool active) = 0;
        virtual void swapBuffers() = 0;
        virtual void pollEvents() = 0;
        void registerEventCallback(const std::function<void(Event& e)>& f);
        void sendEvent(Event& e);
    private:
        int height, width;
        std::function<void(Event& e)> callback;
    };
}

#endif //SANDBOX_WINDOW_H
