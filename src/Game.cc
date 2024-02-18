// File: Game.cc
// Description: This file is part of Snakey game software project, distributed under the terms
// of the GNU General Public License version 3.0.
// Author: Abraham Gabrielyan

//Includes from this project
#include "Game.hpp"

//Includes from third party libraries

//Includes from standard library

void Snakey::Game::ShowLosingScreen() {
    SDL_Surface* surface = SDL_LoadBMP("res/game_over.bmp");
    if (!surface) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "ERROR: Failed to initialize splashscreen surface. %s\n", SDL_GetError());
        throw std::logic_error("Failed to initialize splashscreen surface.");
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer_, surface);
    SDL_FreeSurface(surface);
    if (!texture) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "ERROR: Failed to initialize splashscreen texture. %s\n", SDL_GetError());
        throw std::logic_error("Failed to initialize splashscreen texture.");
    }

    SDL_RenderClear(renderer_);
    SDL_RenderCopy(renderer_, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer_);
    SDL_Delay(1000);

    SDL_DestroyTexture(texture);
    exit(EXIT_FAILURE);
}

void Snakey::Game::HandleDirection() {
    while(SDL_PollEvent(&event_)) {
        if(event_.type == SDL_QUIT) {
            // Quit if the window is closed
            running_state_ = false;
        }
        if(event_.type == SDL_KEYDOWN) {
            // Change direction based on arrow keys
            if(event_.key.keysym.sym == SDLK_DOWN) {
                direction_ = Direction_::DOWN;
            }
            if(event_.key.keysym.sym == SDLK_UP) {
                direction_ = Direction_::UP;
            }
            if(event_.key.keysym.sym == SDLK_LEFT) {
                direction_ = Direction_::LEFT;
            }
            if(event_.key.keysym.sym == SDLK_RIGHT) {
                direction_ = Direction_::RIGHT;
            }
        }
    }
}

void Snakey::Game::HandleMovement() {
    // Move the snake based on its direction
    switch(direction_) {
        case Direction_::DOWN: {
            snake_.AddToHeadY(10);
            break;
        }
        case Direction_::UP: {
            snake_.SubFromHeadY(10);
            break;
        }
        case Direction_::LEFT: {
            snake_.SubFromHeadX(10);
            break;
        }
        case Direction_::RIGHT: {
            snake_.AddToHeadX(10);
            break;
        }
        // Handle unexpected direction
        [[unlikely]] default: {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "ERROR: Unhandled internal event in 'movement'. %s\n", SDL_GetError());
            throw std::logic_error("Failed to handle movement event.");
        }
    }
}

void Snakey::Game::HandleBordersCollision() {
    auto snake_head = snake_.GetSnakeHead();
    // Check if snake collides with borders and display losing screen if true
    if (snake_head.x < 0 or snake_head.y < 0 or
        snake_head.x + snake_head.w > 1000 or
        snake_head.y + snake_head.h > 1000) {
            ShowLosingScreen();
    }
}

void Snakey::Game::HandleEatingEvent() {
    auto snake_head = snake_.GetSnakeHead();
    static bool is_first_iteration = true;
    static bool is_eaten = false;
    // Initialize fruit position randomly on first iteration or after being eaten
    if(is_first_iteration or is_eaten) {
        fruit_.InitRandom();
    }
    is_first_iteration = false;
    // Increase snake size if it eats a fruit and update fruit position
    if(snake_head.x < fruit_.GetX() + fruit_.GetW() and
       snake_head.x + snake_head.w > fruit_.GetX() and
       snake_head.y < fruit_.GetY() + fruit_.GetH() and
       snake_head.y + snake_head.h > fruit_.GetY()) {
           snake_.IncreaseSize(10);
           fruit_.AssignToX(-10);
           fruit_.AssignToY(-10);
           is_eaten = true;
    }
    else {
        is_eaten = false;
    }
}

void Snakey::Game::HandleSnakePartCollision() {
    // Check if snake collides with itself and display losing screen if true
    for(auto& part : snake_.GetSnakeBody()) {
        if(snake_.GetSnakeHead().x == part.x and snake_.GetSnakeHead().y == part.y) {
            ShowLosingScreen();
        }
    }
}

void Snakey::Game::ResizeSnake() {
    // Add a part to the snake and remove parts if necessary to match its size
    snake_.AddPart();
    while(snake_.GetBodySize() > snake_.GetSize()) {
        snake_.RemovePart();
    }
}

void Snakey::Game::RenderObjects() {
    // Clear screen and set draw color
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
    SDL_RenderClear(renderer_);

    // Draw fruit
    SDL_SetRenderDrawColor(renderer_, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer_, &fruit_.GetRawFruit());

    // Draw snake
    SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
    for(auto& part : snake_.GetSnakeBody()) {
        SDL_RenderFillRect(renderer_, &part);
    }
    SDL_RenderPresent(renderer_);
    SDL_Delay(25);
}

void Snakey::Game::Run() {
    // Main game loop
    while(running_state_) {
        HandleDirection();
        HandleMovement();
        HandleBordersCollision();
        HandleEatingEvent();
        HandleSnakePartCollision();
        ResizeSnake();
        RenderObjects();
    }
}

Snakey::Game::Game() : running_state_(true) {
    SDL_Init(SDL_INIT_EVERYTHING);
    window_ = SDL_CreateWindow("Snakey", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, 0);
    if(!window_) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "ERROR: Failed to initialize main window. %s\n", SDL_GetError());
        throw std::runtime_error("Failed to initialize main window.");
    }
    renderer_ = SDL_CreateRenderer(window_, -1, 0);
    if(!renderer_) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "ERROR: Failed to initialize renderer. %s\n", SDL_GetError());
        throw std::runtime_error("Failed to initialize renderer.");
    }
}
