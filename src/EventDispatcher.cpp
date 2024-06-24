#include "../include/EventDispatcher.h"

#include <functional>
#include <SDL3/SDL.h>

void EventDispatcher::HandleEvent(SDL_Event& event) {
    if (event.type == SDL_EVENT_KEY_DOWN) {
        for (auto handler : keyDownHandlers) {
            handler(event.key.keysym.sym);
        }
    }
    else if (event.type == SDL_EVENT_QUIT) {
        for (auto handler : quitHandlers) {
            handler();
        }
    }
}

void EventDispatcher::AddQuitHandler(std::function<void()> handler) {
    quitHandlers.push_back(handler);
}

void EventDispatcher::AddKeyDownHandler(std::function<void(SDL_Keycode)> handler) {
    keyDownHandlers.push_back(handler);
}

void EventDispatcher::AddKeyUpHandler(std::function<void(SDL_Keycode)> handler) {
    keyDownHandlers.push_back(handler);
}

