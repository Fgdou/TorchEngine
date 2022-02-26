//
// Created by fgdou on 2/24/22.
//

#ifndef SANDBOX_WINDOW_H
#define SANDBOX_WINDOW_H

#include "torch.h"

namespace Torch{
    class Window {
    protected:
        Window(int height, int width);
        virtual ~Window() = default;
    public:
        int getHeight();
        int getWidth();
        float getRatio();

        static Ref<Window> create(int height, int width, const std::string& name);

        virtual void setVSync(bool active) = 0;
        virtual void swapBuffers() = 0;
        virtual void pollEvents() = 0;
    private:
        int height, width;
    };
}

#endif //SANDBOX_WINDOW_H
