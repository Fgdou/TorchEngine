//
// Created by fgdou on 2/26/22.
//

#ifndef SANDBOX_OPENGLRENDERER_H
#define SANDBOX_OPENGLRENDERER_H

#include "Renderer.h"
#include "Buffers/Buffers.h"

namespace Torch{
    class OpenGLRenderer: public Renderer {
    public:
        OpenGLRenderer() = default;
        ~OpenGLRenderer() override = default;

        void drawIndex(VertexArray &va, VertexBuffer &vb, IndexBuffer &ib) override;
    };
}


#endif //SANDBOX_OPENGLRENDERER_H
