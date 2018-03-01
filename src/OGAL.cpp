#include "OGAL.hpp"

std::vector<OGAL::event> events;

void OGAL::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    OGAL::event new_event;
    new_event.key_event_.window = window;
    new_event.key_event_.key = key;
    new_event.key_event_.scancode = scancode;
    new_event.key_event_.action = action;
    new_event.key_event_.mods = mods;
    new_event.type = 0;

    events.push_back(new_event);
}

void OGAL::window_size_callback(GLFWwindow* window, int width, int height)
{
    OGAL::event new_event;
    new_event.window_event_.window = window;
    new_event.window_event_.width = width;
    new_event.window_event_.height = height;
    new_event.type = 1;

    events.push_back(new_event);
}

OGAL::event OGAL::poll_events() {
    glfwPollEvents();
    if (events.size() != 0) {
        OGAL::event tmp = events.at(events.size() - 1);
        events.pop_back();
        return tmp;
    } else
        return OGAL::event();
}
