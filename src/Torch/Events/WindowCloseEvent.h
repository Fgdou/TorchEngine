//
// Created by fgdou on 2/26/22.
//

#ifndef SANDBOX_WINDOWCLOSEEVENT_H
#define SANDBOX_WINDOWCLOSEEVENT_H

#include "Event.h"

namespace Torch{
    class WindowCloseEvent: public Event {
    public:
        inline EventType getType() const override {return EventType::WindowClose;}
        static EventType getStaticType();
        std::string toString() override;
    };
}


#endif //SANDBOX_WINDOWCLOSEEVENT_H
