//
// Created by fgdou on 2/24/22.
//

#ifndef SANDBOX_BUFFERS_H
#define SANDBOX_BUFFERS_H

#include "torch.h"

namespace Torch{
    enum class BufferType{
        UINT,
        FLOAT,
    };

    struct BufferLayout{
        std::string name;
        uint32_t count;
        BufferType type;
    };

    class VertexArray{
    protected:
        VertexArray()= default;;
        virtual ~VertexArray() = default;
    public:
        static Ref<VertexArray> create();

        virtual void bind() const = 0;
    };

    class VertexBuffer{
    protected:
        VertexBuffer()= default;
        virtual~VertexBuffer() = default;
    public:
        static Ref<VertexBuffer> create(std::initializer_list<BufferLayout> layout);

        virtual uint32_t getStride() const = 0;
        virtual void sendLayout() = 0;

        virtual void bind() const = 0;
        virtual void setData(const std::vector<float>& data) = 0;
    };

    class IndexBuffer{
    protected:
        IndexBuffer()= default;;
        virtual~IndexBuffer() = default;
    public:
        static Ref<IndexBuffer> create();

        virtual void bind() const = 0;
        virtual void setData(const std::vector<uint32_t>& data) = 0;
        virtual uint32_t getCount() const = 0;
    };
}


#endif //SANDBOX_BUFFERS_H
