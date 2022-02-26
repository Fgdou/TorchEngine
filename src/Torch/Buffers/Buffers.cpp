//
// Created by fgdou on 2/24/22.
//

#include "Buffers.h"
#include "OpenGLBuffers.h"
#include "Context/Context.h"

namespace Torch{

    Ref<VertexArray> VertexArray::create() {
        auto state = Context::getEnv();

        if(state == Context::ENV::OPENGL)
            return std::make_shared<OpenGLVertexArray>();

        ASSERT(false, "env not found");
    }

    Ref<VertexBuffer> VertexBuffer::create(std::initializer_list<BufferLayout> layout) {
        auto state = Context::getEnv();

        if(state == Context::ENV::OPENGL)
            return std::make_shared<OpenGLVertexBuffer>(layout);

        ASSERT(false, "env not found");
    }

    Ref<IndexBuffer> IndexBuffer::create() {
        auto state = Context::getEnv();

        if(state == Context::ENV::OPENGL)
            return std::make_shared<OpenGLIndexBuffer>();

        ASSERT(false, "env not found");
    }
}