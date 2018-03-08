#ifndef EVENT_HPP
#define EVENT_HPP

#include <GLFW/glfw3.h>

namespace OGAL {
    /// Struct which holds only key press related events
    struct key_event {
    public:
        GLFWwindow *window;
        int key;
        int scancode;
        int action;
        int mods;
    };
    
    /// Struct which holds only window related events
    struct window_event {
    public:
        GLFWwindow *window;
        int width;
        int height;
    };
    
    /// Struct which holds all the possible events provided by GLFW
    /// Types are:
    ///     0 - Key event
    ///     1 - Window event
    struct event {
    public:
        short unsigned int type;
        key_event key_event_;
        window_event window_event_;
    };
}
#endif //EVENT_HPP
