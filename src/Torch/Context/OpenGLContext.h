//
// Created by fgdou on 2/26/22.
//

#ifndef SANDBOX_OPENGLCONTEXT_H
#define SANDBOX_OPENGLCONTEXT_H

#include "Context.h"

namespace Torch{
    class OpenGLContext: public Context {
    public:
        static void create();
    };
}


#endif //SANDBOX_OPENGLCONTEXT_H
