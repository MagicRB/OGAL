#ifndef EVENT_HPP
#define EVENT_HPP

#include <GLFW/glfw3.h>

namespace OGAL {
    /// Struct which holds only key press related events
    struct skey_event {
        public:
            GLFWwindow* window;
            int key;
            int scancode;
            int action;
            int mods;
    };

    /// Struct which holds all the possible events provided by GLFW
    struct event {
        public:
            skey_event key_event_;
    };
}
#endif //EVENT_HPP
