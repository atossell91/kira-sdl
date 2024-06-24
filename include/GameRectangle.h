#pragma once

#include <SDL3/SDL.h>

#include "interfaces/IDrawable.h"
#include "Colour.h"

class GameRectangle : public IDrawable {
 private:
    SDL_FRect rectangle;
    Colour::Colour colour;
 public:
    GameRectangle();
    void setXPosition(int pos) { rectangle.x = pos; }
    void setYPosition(int pos) { rectangle.y = pos; }
    void setColour(Colour::Colour c) { colour = c; }
    void Draw(SDL_Renderer* renderer) override;
};
