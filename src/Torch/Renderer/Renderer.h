//
// Created by fgdou on 2/26/22.
//

#ifndef SANDBOX_RENDERER_H
#define SANDBOX_RENDERER_H

#include "torch.h"
#include "Buffers/Buffers.h"

namespace Torch{
    class Renderer {
    protected:
        Renderer() = default;
        virtual ~Renderer() = default;
    public:
        static Renderer& getRenderer();
        static void createRenderer();

        virtual void drawIndex(VertexArray& va, VertexBuffer& vb, IndexBuffer& ib) = 0;
    };
}


#endif //SANDBOX_RENDERER_H
