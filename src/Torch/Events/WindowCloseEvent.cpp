//
// Created by fgdou on 2/26/22.
//

#include <string>
#include "WindowCloseEvent.h"

Torch::EventType Torch::WindowCloseEvent::getStaticType() {
    return Torch::EventType::WindowClose;
}

std::string Torch::WindowCloseEvent::toString() {
    return "WindowClose";
}
