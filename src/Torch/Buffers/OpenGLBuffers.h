//
// Created by fgdou on 2/26/22.
//

#ifndef SANDBOX_OPENGLBUFFERS_H
#define SANDBOX_OPENGLBUFFERS_H

#include "torch.h"
#include "Buffers.h"


namespace Torch{

    uint32_t getSizeOfType(BufferType type);
    uint32_t getTypeToGL(BufferType type);

    class OpenGLVertexArray: public VertexArray{
    public:
        OpenGLVertexArray();
        ~OpenGLVertexArray() override;

        void bind() const override;

    private:
        uint32_t handle;
    };
    class OpenGLVertexBuffer: public VertexBuffer{
    public:
        OpenGLVertexBuffer(std::initializer_list<BufferLayout> layout);
        ~OpenGLVertexBuffer() override;

        void bind() const override;
        void setData(const std::vector<float>& data) override;
        void sendLayout() override;
    private:
        uint32_t getStride() const override;
        std::vector<BufferLayout> layout;
        uint32_t handle;
    };
    class OpenGLIndexBuffer: public IndexBuffer{
    public:
        OpenGLIndexBuffer();
        ~OpenGLIndexBuffer() override;

        void bind() const override;
        void setData(const std::vector<uint32_t>& data) override;
        uint32_t getCount() const override;

    private:
        uint32_t handle;
        uint32_t count;
    };
}


#endif //SANDBOX_OPENGLBUFFERS_H
