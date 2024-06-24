#include "../include/GameRectangle.h"

#include <SDL3/SDL.h>
#include <iostream>

GameRectangle::GameRectangle() {
    rectangle.w = 60;
    rectangle.h = 60;
}

void GameRectangle::Draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer,
    colour.Red, colour.Green, colour.Blue, colour.Alpha);
    SDL_RenderFillRect(renderer, &rectangle);
}
