// File: main.cc
// Description: This file is part of Snakey game software project, distributed under the terms
// of the GNU General Public License version 3.0.
// Author: Abraham Gabrielyan

//Includes from this project
#include "Game.hpp"

//Includes from third party libraries

//Includes from standard library

int main(void) {
  try {
    Snakey::Game game;
    game.Run();
  }
  catch(const std::exception& ex) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, ex.what(), SDL_GetError());
    return EXIT_FAILURE;
  }
  catch(...) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "ERROR: Internal game error. %s\n", SDL_GetError());
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
