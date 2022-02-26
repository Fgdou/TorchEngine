//
// Created by fgdou on 2/26/22.
//

#include "OpenGLContext.h"
#include "torch.h"
#include "gl.h"
#include "GLFW/glfw3.h"

namespace Torch{

    bool openglInited = false;

    void OpenGLContext::create() {
        if(openglInited)
            return;
        LOG_INFO("Create openGL context");
        auto res = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
        ASSERT(res == GL_TRUE, "failed to create opengl context");
        openglInited = true;

        auto version = glGetString(GL_VERSION);
        LOG_INFO("OpenGL version %s", version);
    }
}
