//
// Created by fgdou on 2/26/22.
//

#include "Shader.h"
#include "OpenGLShader.h"
#include "Context/Context.h"

namespace Torch{

    Ref<Shader> Shader::create(const std::string &vertexPath, const std::string &fragmentPath) {
        auto state = Context::getEnv();

        if(state == Context::ENV::OPENGL)
            return std::make_shared<OpenGLShader>(vertexPath, fragmentPath);
        ASSERT(false, "state not found");
    }
}