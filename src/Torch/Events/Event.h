//
// Created by fgdou on 2/24/22.
//

#ifndef SANDBOX_EVENT_H
#define SANDBOX_EVENT_H

#include <functional>
#include <string>


namespace Torch{
    enum class EventType{
        WindowClose,
        WindowResize
    };

    class Event {
    protected:
        Event() = default;
        virtual ~Event() = default;
    public:
        virtual EventType getType() const = 0;
        inline bool isHandled() const{return handled;}
        inline void setHandled(){handled = true;}
        virtual std::string toString() = 0;

    private:
        bool handled = false;
    };

    class Dispatcher{
    public:
        explicit Dispatcher(Event& e);
        ~Dispatcher() = default;

        template<class T>
        bool dispatch(const std::function<void(T &)>& f) {
            if(e.getType() == T::getStaticType()){
                f(*dynamic_cast<T*>(&e));
                return true;
            }
            return false;
        }
    private:
        Event& e;
    };
}


#endif //SANDBOX_EVENT_H
