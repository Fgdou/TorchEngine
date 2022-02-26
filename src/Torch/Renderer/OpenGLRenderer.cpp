//
// Created by fgdou on 2/26/22.
//

#include "OpenGLRenderer.h"
#include "gl.h"

void Torch::OpenGLRenderer::drawIndex(Torch::VertexArray &va, Torch::VertexBuffer &vb, Torch::IndexBuffer &ib, Shader& shader) {
    va.bind();
    vb.bind();
    ib.bind();

    vb.sendLayout();
    shader.bind();

    GL_CALL(glDrawElements(GL_TRIANGLES, ib.getCount(), GL_UNSIGNED_INT, nullptr));
}
