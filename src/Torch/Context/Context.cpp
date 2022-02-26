//
// Created by fgdou on 2/26/22.
//

#include "Context.h"
#include "OpenGLContext.h"

namespace Torch{
    void Context::create() {
        if(getEnv() == ENV::OPENGL)
            OpenGLContext::create();
        else
            ASSERT(false, "env not found");
    }

    Context::ENV Context::getEnv() {
        return ENV::OPENGL;
    }
}
