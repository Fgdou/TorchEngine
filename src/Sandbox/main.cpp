#include <iostream>

#include "torch.h"
#include "Window/Window.h"
#include "Buffers/Buffers.h"
#include "Renderer/Renderer.h"


int main() {
    auto window = Torch::Window::create(500, 600, "OpenGL test");

    auto va = Torch::VertexArray::create();
    va->bind();

    auto vb = Torch::VertexBuffer::create({
          {
              "position",
              2,
              Torch::BufferType::FLOAT
          }
    });
    auto ib = Torch::IndexBuffer::create();

    std::vector<float> pos{
            -0.5f, -0.5f,
             0.5f, -0.5f,
             0.5f,  0.5f,
            -0.5f,  0.5f,
    };
    std::vector<uint32_t> index{
            0, 1, 2
    };

    vb->setData(pos);
    ib->setData(index);

    while(true) {
        Torch::Renderer::getRenderer().drawIndex(*va, *vb, *ib);
        window->swapBuffers();
    }
}
