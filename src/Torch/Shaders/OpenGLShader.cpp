//
// Created by fgdou on 2/26/22.
//

#include "OpenGLShader.h"
#include "gl.h"
#include <fstream>

namespace Torch{

    uint32_t OpenGLShader::compileShader(const std::string &path, uint32_t type) {
        GL_CALL(int shader = glCreateShader(type));

        auto source = openShader(path);
        auto ptr = source.c_str();
        GL_CALL(glShaderSource(shader, 1, &ptr, nullptr));

        GL_CALL(glCompileShader(shader));

        GLint vertex_compiled;
        GL_CALL(glGetShaderiv(shader, GL_COMPILE_STATUS, &vertex_compiled));
        if (vertex_compiled != GL_TRUE)
        {
            GLsizei log_length = 0;
            GLchar message[1024];
            GL_CALL(glGetShaderInfoLog(shader, 1024, &log_length, message));

            LOG_ERROR("Shader %s cannot compile: \n%s", path.c_str(), message);
            throw std::runtime_error("shader cannot compile");
        }

        return shader;
    }
    std::string OpenGLShader::openShader(const std::string &path) {
        std::ifstream file(path);
        if(!file.is_open()){
            LOG_ERROR("Failed to open file %s", path.c_str());
            throw std::runtime_error("failed to open file");
        }
        file.seekg(0, std::ios::end);
        auto size = file.tellg();
        std::string buff(size, ' ');
        file.seekg(0);
        file.read(&buff[0], size);

        return buff;
    }

    OpenGLShader::OpenGLShader(const std::string &vertex, const std::string &fragment) {
        GL_CALL(handle = glCreateProgram());
        auto vertexSource = compileShader(vertex, GL_VERTEX_SHADER);
        auto fragmentSource = compileShader(fragment, GL_FRAGMENT_SHADER);

        GL_CALL(glAttachShader(handle, vertexSource));
        GL_CALL(glAttachShader(handle, fragmentSource));

        GL_CALL(glLinkProgram(handle));

        GLint program_linked;
        GL_CALL(glGetProgramiv(handle, GL_LINK_STATUS, &program_linked));
        if (program_linked != GL_TRUE)
        {
            GLsizei log_length = 0;
            GLchar message[1024];
            glGetProgramInfoLog(handle, 1024, &log_length, message);

            LOG_ERROR("Failed to link program: \n\t%s\n\t%s\n%s", vertex.c_str(), fragment.c_str(), message);
            GL_CALL(glDeleteShader(vertexSource));
            GL_CALL(glDeleteShader(fragmentSource));
            throw std::runtime_error("failed to link program");
        }

        GL_CALL(glDeleteShader(vertexSource));
        GL_CALL(glDeleteShader(fragmentSource));
    }

    OpenGLShader::~OpenGLShader() {
        GL_CALL(glDeleteProgram(handle));
    }

    void OpenGLShader::bind() {
        GL_CALL(glUseProgram(handle));
    }

    void OpenGLShader::setUniformUInt(const std::string& name, uint32_t i) {
        auto location = getUniformLocation(name);
        if(location != -1){
            GL_CALL(glProgramUniform1ui(handle, location, i));
        }
    }

    void OpenGLShader::setUniformFloat(const std::string &name, float f) {
        auto location = getUniformLocation(name);
        if(location != -1){
            GL_CALL(glProgramUniform1f(handle, location, f));
        }
    }

    void OpenGLShader::setUniformFloat2(const std::string &name, glm::vec2 f) {
        auto location = getUniformLocation(name);
        if(location != -1){
            GL_CALL(glProgramUniform2f(handle, location, f.x, f.y));
        }
    }

    void OpenGLShader::setUniformFloat3(const std::string &name, glm::vec3 f) {
        auto location = getUniformLocation(name);
        if(location != -1){
            GL_CALL(glProgramUniform3f(handle, location, f.x, f.y, f.z));
        }
    }

    void OpenGLShader::setUniformFloat4(const std::string &name, glm::vec4 f) {
        auto location = getUniformLocation(name);
        if(location != -1){
            GL_CALL(glProgramUniform4f(handle, location, f.x, f.y, f.z, f.w));
        }
    }

    void OpenGLShader::setUniformMat4(const std::string &name, glm::mat4 mat) {
        auto location = getUniformLocation(name);
        if(location != -1){
            GL_CALL(glProgramUniformMatrix4fv(handle, location, 4*4, GL_FALSE, &mat[0][0]));
        }
    }

    int OpenGLShader::getUniformLocation(const std::string &name) const {
        GL_CALL(int n = glGetUniformLocation(handle, name.c_str()));
        if(n == -1) LOG_WARN("Uniform %s not found", name.c_str());
        return n;
    }
}
