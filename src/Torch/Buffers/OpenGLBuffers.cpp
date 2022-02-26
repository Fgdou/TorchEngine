//
// Created by fgdou on 2/26/22.
//

#include "OpenGLBuffers.h"
#include "gl.h"

namespace Torch{

    uint32_t getSizeOfType(BufferType type){
        switch(type){
            case BufferType::FLOAT: return sizeof(float);
            case BufferType::UINT: return sizeof(uint32_t);
        }
        ASSERT(false, "type not found");
    }
    uint32_t getTypeToGL(BufferType type){
        switch(type){
            case BufferType::FLOAT: return GL_FLOAT;
            case BufferType::UINT: return GL_UNSIGNED_INT;
        }
        ASSERT(false, "type not found");
    }

    OpenGLVertexArray::OpenGLVertexArray()
        : handle(0)
    {
        LOG_INFO("Create vertex array");
        GL_CALL(glCreateVertexArrays(1, &handle));
        ASSERT(handle != 0, "failed to create vertex array");
    }

    OpenGLVertexArray::~OpenGLVertexArray() {
        LOG_INFO("Destroy vertex array");
        GL_CALL(glDeleteVertexArrays(1, &handle));
    }

    void OpenGLVertexArray::bind() const {
        GL_CALL(glBindVertexArray(handle));
    }

    uint32_t OpenGLVertexBuffer::getStride() const {
        uint32_t size = 0;
        for(auto& e : layout){
            size += getSizeOfType(e.type)*e.count;
        }
        return size;
    }

    OpenGLVertexBuffer::OpenGLVertexBuffer(std::initializer_list<BufferLayout> layout)
        : layout(layout)
    {
        LOG_INFO("Create vertex buffer");
        GL_CALL(glCreateBuffers(1, &handle));
        ASSERT(handle != 0, "failed to create vertex buffer");
    }

    OpenGLVertexBuffer::~OpenGLVertexBuffer() {
        LOG_INFO("Destroy vertex buffer");
        GL_CALL(glDeleteBuffers(1, &handle));
    }

    void OpenGLVertexBuffer::bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, handle);
    }

    void OpenGLVertexBuffer::sendLayout() {
        bind();

        auto stride = getStride();

        uint32_t offset = 0;
        uint32_t index = 0;
        for(auto& e : layout){
            GL_CALL(glEnableVertexAttribArray(index));
            GL_CALL(glVertexAttribPointer(index, e.count, getTypeToGL(e.type), GL_FALSE, stride, (void*)offset));

            offset += getSizeOfType(e.type)*e.count;
            index++;
        }
    }

    void OpenGLVertexBuffer::setData(const std::vector<float> &data) {
        bind();
        GL_CALL(glBufferData(GL_ARRAY_BUFFER, data.size()*sizeof(float), data.data(), GL_STATIC_DRAW));
    }

    OpenGLIndexBuffer::OpenGLIndexBuffer()
        : count(0)
    {
        LOG_INFO("Create index buffer");
        GL_CALL(glCreateBuffers(1, &handle));
        ASSERT(handle != 0, "failed to create index buffer");
    }

    OpenGLIndexBuffer::~OpenGLIndexBuffer() {
        GL_CALL(glDeleteBuffers(1, &handle));
        LOG_INFO("Destroy vertex buffer");
    }

    void OpenGLIndexBuffer::bind() const {
        GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, handle));
    }

    void OpenGLIndexBuffer::setData(const std::vector<uint32_t> &data) {
        bind();
        count = data.size();
        GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size()*sizeof(uint32_t), data.data(), GL_STATIC_DRAW));
    }

    uint32_t OpenGLIndexBuffer::getCount() const {
        return count;
    }
}