//
// Created by fgdou on 2/26/22.
//

#ifndef SANDBOX_GL_CPP_H
#define SANDBOX_GL_CPP_H

#include "torch.h"
#include "gl.h"
#include <string>

void Torch::detectError(int line, const char* file){
    GLenum err;
    while((err = glGetError()) != GL_NO_ERROR)
    {
        std::string error;
        switch (err)
        {
            case GL_INVALID_ENUM:                  error = "INVALID_ENUM"; break;
            case GL_INVALID_VALUE:                 error = "INVALID_VALUE"; break;
            case GL_INVALID_OPERATION:             error = "INVALID_OPERATION"; break;
            case GL_STACK_OVERFLOW:                error = "STACK_OVERFLOW"; break;
            case GL_STACK_UNDERFLOW:               error = "STACK_UNDERFLOW"; break;
            case GL_OUT_OF_MEMORY:                 error = "OUT_OF_MEMORY"; break;
            case GL_INVALID_FRAMEBUFFER_OPERATION: error = "INVALID_FRAMEBUFFER_OPERATION"; break;
            default:                               error = std::to_string(err);
        }
        throw std::runtime_error("OpenGL(" + error + ") error " + file + ":" + std::to_string(line));
    }
}

#endif //SANDBOX_GL_CPP_H
