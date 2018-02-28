#ifndef EVENT_HPP
#define EVENT_HPP

#include <GLFW/glfw3.h>

namespace OGAL {
    struct skey_event {
        public:
            GLFWwindow* window;
            int key;
            int scancode;
            int action;
            int mods;
    };

    struct event {
        public:
            skey_event key_event_;
    };
}
#endif //EVENT_HPP
