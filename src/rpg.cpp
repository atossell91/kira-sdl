#include "../include/rpg.h"

#include "../include/GameRectangle.h"

void rpg::init() {
    game.AddDrawable(&character);
    eventDispatcher.AddQuitHandler([this](){ context.ShouldClose = true; });
    eventDispatcher.AddKeyDownHandler([this](SDL_Keycode key){ handleKeyDown(key); });
    eventDispatcher.AddKeyUpHandler([this](SDL_Keycode key){ handleKeyUp(key); });
}

void rpg::Start() {
    game.Run();
}

void rpg::handleKeyDown(SDL_Keycode code) {
}

void rpg::handleKeyUp(SDL_Keycode code) {
}
