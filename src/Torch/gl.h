//
// Created by fgdou on 2/26/22.
//

#ifndef SANDBOX_GL_H
#define SANDBOX_GL_H

#include "glad/glad.h"

#define GL_CALL(x) x; Torch::detectError(__LINE__, __FILE__)
namespace Torch{
    void detectError(int line, const char* file);
}

#endif //SANDBOX_GL_H
