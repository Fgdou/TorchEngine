#include <iostream>

#include "torch.h"
#include "Window/Window.h"
#include "Buffers/Buffers.h"
#include "Renderer/Renderer.h"
#include "Events/Event.h"
#include "Events/WindowCloseEvent.h"
#include <functional>
#include "Application.h"

class App: public Torch::Application{
public:
    App(): Torch::Application(600, 500, "Test")
    {
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
    }

    void onUpdate() override {
        shader->setUniformFloat3("color", {1.0f, .5f, .3f});
    }

    void onDraw() override {
        Torch::Renderer::getRenderer().drawIndex(*va, *vb, *ib, *shader);
    }

    void onInit() override {

    }

    void onEvent(Torch::Event &event) override {
        LOG_INFO("Event %s", event.toString().c_str());
    }

    void onClose() override {

    }

private:
    Torch::Ref<Torch::VertexArray> va = Torch::VertexArray::create();
    Torch::Ref<Torch::VertexBuffer> vb = Torch::VertexBuffer::create({{
                                                                              "position",
                                                                              2,
                                                                              Torch::BufferType::FLOAT
                                                                      }});
    Torch::Ref<Torch::IndexBuffer> ib = Torch::IndexBuffer::create();
    Torch::Ref<Torch::Shader> shader = Torch::Shader::create("../shaders/simple.vert", "../shaders/simple.frag");
};

int main() {
    App app;
    app.run();
}
