//
// Created by fgdou on 2/26/22.
//

#include "Renderer.h"
#include "Context/Context.h"
#include "OpenGLRenderer.h"

namespace Torch{
    static Renderer* renderer = nullptr;

    void Renderer::createRenderer() {
        auto state = Context::getEnv();

        if(state == Context::ENV::OPENGL)
            renderer = new OpenGLRenderer();
        else
            ASSERT(false, "state not found");
    }

    Renderer &Renderer::getRenderer() {
        if(renderer == nullptr)
            createRenderer();
        ASSERT(renderer != nullptr, "renderer is not created");
        return *renderer;
    }

}