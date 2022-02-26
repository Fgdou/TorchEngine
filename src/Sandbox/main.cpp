#include <iostream>

#include "torch.h"
#include "Window/Window.h"
#include "Buffers/Buffers.h"
#include "Renderer/Renderer.h"
#include "Events/Event.h"
#include "Events/WindowCloseEvent.h"
#include <functional>

bool close = false;

void eventCallback(Torch::Event& e){
    LOG_INFO("Event %s", e.toString().c_str());

    Torch::Dispatcher d(e);

    d.dispatch<Torch::WindowCloseEvent>([&](Torch::WindowCloseEvent& e){
        close = true;
    });
}

int main() {
    auto window = Torch::Window::create(500, 600, "OpenGL test");

    window->registerEventCallback(eventCallback);

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

    auto shader = Torch::Shader::create("../shaders/simple.vert", "../shaders/simple.frag");

    shader->setUniformFloat3("color", {1.0f, .5f, .3f});

    while(!close) {
        Torch::Renderer::getRenderer().drawIndex(*va, *vb, *ib, *shader);
        window->swapBuffers();
        window->pollEvents();
    }
}
