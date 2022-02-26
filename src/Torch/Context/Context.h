//
// Created by fgdou on 2/26/22.
//

#ifndef SANDBOX_CONTEXT_H
#define SANDBOX_CONTEXT_H

#include "torch.h"

namespace Torch{
    class Context {
    public:
        enum class ENV{
            OPENGL,
            NONE
        };
        static ENV getEnv();
        static void create();
    };
}


#endif //SANDBOX_CONTEXT_H
