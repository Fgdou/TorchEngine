//
// Created by fgdou on 2/26/22.
//

#ifndef SANDBOX_SHADER_H
#define SANDBOX_SHADER_H

#include "torch.h"
#include "glm.hpp"

namespace Torch{
    class Shader {
    protected:
        Shader() = default;
        virtual ~Shader() = default;
    public:
        static Ref<Shader> create(const std::string& vertexPath, const std::string& fragmentPath);

        virtual void bind() = 0;

        virtual void setUniformUInt(const std::string& name, uint32_t i) = 0;
        virtual void setUniformFloat(const std::string& name, float f) = 0;
        virtual void setUniformFloat2(const std::string& name, glm::vec2 f) = 0;
        virtual void setUniformFloat3(const std::string& name, glm::vec3 f) = 0;
        virtual void setUniformFloat4(const std::string& name, glm::vec4 f) = 0;
        virtual void setUniformMat4(const std::string& name, glm::mat4 mat) = 0;
    };
}


#endif //SANDBOX_SHADER_H
