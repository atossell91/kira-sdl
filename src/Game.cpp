#include "../include/Game.h"

#include <thread>
#include <chrono>
#include <list>
#include <iostream>

#include "../include/GameContext.h"

Game::Game() {
    init();
}

void Game::init() {
    SDL_Init(kInitFlags);

    window = SDL_CreateWindow(gameName, kWindowWidth, kWindowHeight, 0);
    renderer = SDL_CreateRenderer(window, NULL, 0);
    if (renderer == NULL) {
        std::cout << "Renderer is null: " << SDL_GetError() << std::endl;
    }
}

void Game::mainLoop() {
    while (!gameContext.ShouldClose) {
        ProcessEvents();
        Draw();
        std::this_thread::sleep_for(
            std::chrono::milliseconds(kMainLoopDelay));
    }
}

void Game::ProcessEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        eventDispatcher.HandleEvent(event);
    }
}

void Game::Draw() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (auto drawable : drawables) {
        drawable->Draw(renderer);
    }

    SDL_RenderPresent(renderer);
}

void Game::Run() {
    mainLoop();
}

void Game::AddDrawable(IDrawable* drawable) {
    drawables.push_back(drawable);
}

void Game::RemoveDrawable(IDrawable* drawable) {
    drawables.remove(drawable);
}

GameContext& Game::GetGameContext() {
    return gameContext;
}

EventDispatcher& Game::GetEventDispatcher() {
    return eventDispatcher;
}
