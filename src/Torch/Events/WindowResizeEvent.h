//
// Created by fgdou on 2/26/22.
//

#ifndef SANDBOX_WINDOWRESIZEEVENT_H
#define SANDBOX_WINDOWRESIZEEVENT_H

#include <string>
#include "Event.h"

namespace Torch{
    class WindowResizeEvent: public Event {
    public:
        WindowResizeEvent(int height, int width);
        ~WindowResizeEvent() override = default;

        std::string toString() override;
        EventType getType() const override;

        int getHeight() const;
        int getWidth() const;
    public:
        int height, width;
    };
}


#endif //SANDBOX_WINDOWRESIZEEVENT_H
