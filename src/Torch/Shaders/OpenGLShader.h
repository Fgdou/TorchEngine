//
// Created by fgdou on 2/26/22.
//

#ifndef SANDBOX_OPENGLSHADER_H
#define SANDBOX_OPENGLSHADER_H

#include "Shader.h"

namespace Torch{
    class OpenGLShader: public Shader {
    public:
        OpenGLShader(const std::string& vertex, const std::string& fragment);
        ~OpenGLShader() override;

        void bind() override;

        void setUniformUInt(const std::string& name, uint32_t i) override;
        void setUniformFloat(const std::string &name, float f) override;
        void setUniformFloat2(const std::string &name, glm::vec2 f) override;
        void setUniformFloat3(const std::string &name, glm::vec3 f) override;
        void setUniformFloat4(const std::string &name, glm::vec4 f) override;
        void setUniformMat4(const std::string &name, glm::mat4 mat) override;

    private:
        int getUniformLocation(const std::string& name) const;
        static uint32_t compileShader(const std::string& path, uint32_t type);
        static std::string openShader(const std::string& path);
        uint32_t handle;
    };
}


#endif //SANDBOX_OPENGLSHADER_H
