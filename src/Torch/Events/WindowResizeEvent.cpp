//
// Created by fgdou on 2/26/22.
//

#include "WindowResizeEvent.h"

Torch::WindowResizeEvent::WindowResizeEvent(int height, int width)
    : height(height), width(width)
{

}

std::string Torch::WindowResizeEvent::toString() {
    return "WindowResize(" + std::to_string(width) + "x" + std::to_string(height) + ")";
}

Torch::EventType Torch::WindowResizeEvent::getType() const {
    return EventType::WindowResize;
}

int Torch::WindowResizeEvent::getHeight() const {
    return height;
}

int Torch::WindowResizeEvent::getWidth() const {
    return width;
}
