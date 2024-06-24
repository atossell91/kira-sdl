#pragma once

#include "GameContext.h"
#include "EventDispatcher.h"
#include "Game.h"
#include "GameRectangle.h"

class rpg {
 private:
    Game game;
    GameContext& context;
    EventDispatcher& eventDispatcher;
    GameRectangle character;

    void init();
    void handleKeyDown(SDL_Keycode keycode);
    void handleKeyUp(SDL_Keycode keycode);
 public:
    rpg() :
      game{Game()},
      context{game.GetGameContext()},
      eventDispatcher{game.GetEventDispatcher()}
      { init(); }

    void Start();
};
