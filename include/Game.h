#pragma once

#include <SDL3/SDL.h>
#include <list>

#include "GameContext.h"
#include "EventDispatcher.h"
#include "interfaces/IDrawable.h"

class Game {
 private:
    const int kInitFlags = SDL_INIT_VIDEO;

    GameContext gameContext;
    EventDispatcher eventDispatcher;

    const int kWindowWidth = 800;
    const int kWindowHeight = 600;
    const char* gameName = "Rubber Duck";

    const int kMainLoopDelay = 20; // Milliseconds

    SDL_Window* window;
    SDL_Renderer* renderer;

    std::list<IDrawable*> drawables;

    void init();
    void mainLoop();

 public:
    Game();
    void ProcessEvents();
    void Draw();
    void Run();
    void AddDrawable(IDrawable* drawable);
    void RemoveDrawable(IDrawable* drawable);
    GameContext& GetGameContext();
    EventDispatcher& GetEventDispatcher();
};